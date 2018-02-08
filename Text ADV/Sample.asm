jumpIfEqual PROC var1:DWORD, var2:DWORD, jmpAddress:DWORD
    mov eax,var1
    cmp eax,var2
    jne skip
    pop eax
    push jmpAddress
    skip:
    ret
jumpIfEqual ENDP

....

push OFFSET jumpToHere
mov eax, 5
push eax
push eax
call jumpIfEqual





abc db "abc",0
def db "def",0
...
mov ecx,3                          #the length of the abc and def strings
cld                                  #set the direction flag so that EDI and ESI will increase using repe
mov esi, offset [abc]               #moves address of abc string into esi
mov edi, offset [def]                  #exact syntax may differ depending on assembler you use
                                       #I am not exactly sure what MASM accepts but certainly something similar to this
repe cmpsb     							 #repeat compare [esi] with [edi] until ecx!=0 and current chars in strings match
											#edi and esi increase for each repetition, so pointing to the next char
cmp ecx,0     								 #test if the above command passed until the end of strings
je strings_are_equal  								#if yes then strings are equal
														# here print the message that strings are not equal (i.e. invoke MessageBox)
jmp end
strings_not_equal:
													# here print the message that strings are equal (i.e. invoke MessageBox)
end:





.data
	sz1 db "hello",0
	sz2 db "hello",0
.code

cld
lea edi,sz1
mov ecx,-1
xor eax,eax
mov edx,edi
repnz scasb
sub edi,edx
mov ecx,edi
mov edi,edx

lea esi,sz2
repz cmpsb
.if ZERO?
	; equal
.else
	; not equal	
.endif


; HERE IS SAMPLE STRING COMPARISON.

.686
.model flat
public _main
extern _ExitProcess@4 : PROC
extern _MessageBoxA@16 : PROC 
.data
window_title db 'Example 42', 0
string1 db 'bies', 0
size1 = $ - string1
string2 db 'bies', 0
size2 = $ - string2
output db 80 dup(?), 0 ; variable to output result
.code
_main PROC
    mov esi, OFFSET string1
    mov edi, OFFSET string2
    mov al, OFFSET size1
    mov dl, OFFSET size2
    xor ebx, ebx ; set ebx = 0
    cmp al, dl ; compare sizes i want shorter to be counter for comparsion loop
    jbe second_as_counter ; case when bl is shorter - bl is counter
    movzx ecx, al 
    jmp compare

second_as_counter:
    movzx ecx, dl

compare:
    cmp ecx, ebx ; im checking if strings are the same size, ebx starts as 0
    je same ; if none of the others condition were fullfilled it means all the letter were the same
    push ecx ; remember the counter value, cause i have no more free registers
    mov ecx, dword ptr [edi+ebx] ; compare x element of both strings
    cmp dword ptr [esi+ebx], ecx
    ja after ; if letter in esi is bigger than letter in edi, it will be placed after edi in dictionary
    jb before ; else  edi is first 
    pop ecx ; return ecx previous value
    inc ebx ; increment counter, to check next elemnt of string
    jmp compare

after:
    stc ; set carry flag
    mov ecx, 2
    dec ecx ; clear zero flag
    mov byte ptr output, byte ptr '1' ; just an output to have a proof it works
    jmp koniec

before:
    clc ; clear carry flag
    mov ecx, 2
    dec ecx ; clear zero flag
    mov byte ptr output, byte ptr '2'
    jmp koniec

same:
    cmp al, dl ; check if lenghts are the same
    je identical 
    ja after
    jmp before

identical:
    clc ; clear carry flag 
    mov ecx, 1
    dec ecx ; set zero flag
    mov byte ptr output, byte ptr '3'


koniec:
    push 0; MB_OK
    push OFFSET window_title
    push OFFSET output 
    push 0
    call _MessageBoxA@16 
    push 0
    call _ExitProcess@4 
_main ENDP
END
; 1 - after(CF=1, ZF=0), 2 - before(CF=0, ZF=0), 3 - identical(CF=0, ZF=1)





