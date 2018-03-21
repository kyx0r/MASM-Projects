.386 
.model flat,stdcall 
option casemap:none 
include \masm32\include\masm32rt.inc

.data 
LibName db "Inject.dll",0 
FunctionName db "TestHello",0 
DllNotFound db "Cannot load library",0 
AppName db "Load Library",0 
FunctionNotFound db "TestHello function not found",0
FuncName db "TestFunction",0

.data? 
libHandle dd ?                                         ; the handle of the library (DLL) 
TestHelloAddr dd ?                        ; the address of the TestHello function

.code 

; Load proc
	; invoke LoadLibrary,addr LibName 
	; ret
; Load endp


start: 
        invoke LoadLibrary,addr LibName 
		;mov esi, rv(GetProcAddress, rv(GetModuleHandle, LibName), FuncName)
		;and eax,eax 
		;jz @@quitError 
		mov libHandle, eax
		invoke GetProcAddress, libHandle, addr FuncName
		call eax
		invoke FreeLibrary,libHandle
		mov libHandle, eax

; @@quitError:
	; push offset DllNotFound
	; call StdOut
	; jmp exit0	
	
exit0:
		inkey
		push 0
		call ExitProcess		
end start