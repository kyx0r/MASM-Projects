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





; HERE ICON

.386
.model flat,stdcall
option casemap:none

include    \masm32\include\windows.inc
include    \masm32\include\kernel32.inc
include    \masm32\include\user32.inc

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

.data

kernel32    db 'kernel32.dll',0
FuncName    db 'SetConsoleIcon',0
msg         db 'Click the message box to change the console icon',0
msg2        db 'Console icon changed',0
capt        db 'Test',0
func        db 0FFh,025h ; define a jump entry
            dd pFunc


.data?

hIcon       dd ?
pFunc       dd ?

SetConsoleIcon  EQU <pr1 PTR func>

.code

start:

    invoke  GetModuleHandle,0
    invoke  LoadIcon,eax,200
    mov     hIcon,eax
    invoke  GetModuleHandle,ADDR kernel32
    invoke  GetProcAddress,eax,ADDR FuncName
    mov     pFunc,eax
    invoke  MessageBox,0,ADDR msg,ADDR capt,MB_OK
    invoke  SetConsoleIcon,hIcon
    invoke  MessageBox,0,ADDR msg2,ADDR capt,MB_OK
    invoke  ExitProcess,0

END start


















; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

;                 Build this with the "Project" menu using
;                        "Console Assemble & Link"

comment * ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

There is another method of allocating space for uninitialised data in
MASM that can only be done within a procedure. The use of LOCAL variables
is possible in a procedure because the memory from the "stack" can be
used in this way.

In MASM, allocating a LOCAL uninitialised variable is done at the beginning
of a procedure BEFORE you write any code in the procedure. With memory
allocated on the stack, it can only be used within that procedure and is
deallocated at the end of the procedure on exit.

    LOCAL MyVar:DWORD       ; allocate a 32 bit space on the stack
    LOCAL Buffer[128]:BYTE  ; allocate 128 BYTEs of space for TEXT data.

Variables created on the stack in this manner are sometimes called
automatic variables and their main advantage is being fast, flexible
and easy to use.

This demo also shows how to get user input from the console using "input".
It also introduces a simple procedure that has a value passed to it and
the procedure uses a PROTOTYPE to enable size and parameter count checking
to make the code more reliable.

ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл *

    .486                                    ; create 32 bit code
    .model flat, stdcall                    ; 32 bit memory model
    option casemap :none                    ; case sensitive
 
    include \masm32\include\windows.inc     ; always first
    include \masm32\macros\macros.asm       ; MASM support macros

  ; -----------------------------------------------------------------
  ; include files that have MASM format prototypes for function calls
  ; -----------------------------------------------------------------
    include \masm32\include\masm32.inc
    include \masm32\include\gdi32.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc

  ; ------------------------------------------------
  ; Library files that have definitions for function
  ; exports and tested reliable prebuilt code.
  ; ------------------------------------------------
    includelib \masm32\lib\masm32.lib
    includelib \masm32\lib\gdi32.lib
    includelib \masm32\lib\user32.lib
    includelib \masm32\lib\kernel32.lib

  ; --------------------------------------------------------------
  ; This is a prototype for a procedure used in the demo. It tells
  ; MASM how many parameters are passed to the procedure and how
  ; big they are. This makes procedure calls far more reliable as
  ; MASM will not allow different sizes or different numbers of
  ; parameters to be passed. Note that a C calling convention
  ; procedure CAN have a variable number of arguments but these
  ; examples use the normal Windows STDCALL convention which is
  ; different.
  ; --------------------------------------------------------------
    show_text PROTO :DWORD

    .code                       ; Tell MASM where the code starts

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

start:                          ; The CODE entry point to the program

    call main                   ; branch to the "main" procedure

    exit

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

main proc

    LOCAL txtinput:DWORD        ; a "handle" for the text returned by "input"

    mov txtinput, input("Type some text at the cursor : ")
    invoke show_text, txtinput

    ret

main endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

show_text proc string:DWORD

    print chr$("This is what you typed at the cursor",13,10,"     *** ")
    print string                ; show the string at the console
    print chr$(" ***",13,10)

    ret

show_text endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start                       ; Tell MASM where the program ends









INCLUDE Irvine32.inc
INCLUDE Macros.inc
INCLUDE C:\masm32\include\user32.inc

.data
POINT STRUCT
x DWORD ?
y DWORD ?
POINT ENDS
MOUSE   POINT   <>

.code
GetMouseCoords PROC 
.REPEAT
   invoke GetKeyState, VK_LBUTTON   
    .if sbyte ptr ah<0
      mov ebx, 1
   .ENDIF
.UNTIL(ebx==1)
   INVOKE   GetCursorPos, ADDR MOUSE
   ;here is where I would put the Invoke ScreenToClient command if I knew how to use it

   mov eax, MOUSE.x
   Call Writedec
   mov al, "X"
   Call WriteChar
   mov eax, MOUSE.Y
   Call Writedec
   mov eax, 10000
   Call Delay

ret
GetMouseCoords ENDP

