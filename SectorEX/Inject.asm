; .386 
; .model flat,stdcall 
; option casemap:none 

include \masm32\include\masm32rt.inc
include \masm32\macros\pomacros.asm

    ; TestFunction PROTO :DWORD
	; TestFunction2 PROTO :DWORD
	
.data 
string db 'Text Adventure',0ah
string2 db '2nd function',0ah
string3 db '3rd function',0ah
.code 


DllEntry proc hInstDLL:HINSTANCE, reason:DWORD, reserved1:DWORD 
        mov  eax,TRUE 	
        ret 
DllEntry Endp 

TestFunction proc 
	push offset string
	call StdOut
    ret 
TestFunction endp

TestFunction2 proc 
	push offset string2
	call StdOut
    ret 
TestFunction2 endp

TestFunction3 proc 
	push offset string3
	call StdOut
    ret 
TestFunction3 endp


End DllEntry

