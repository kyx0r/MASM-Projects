	;LIBS ----------------------------------------------------
	include \masm32\include\masm32rt.inc

	include     \masm32\include\winmm.inc
	includelib  \masm32\lib\winmm.lib

	includelib  \masm32\lib\advapi32.lib

	include     \masm32\include\d3d8.inc
	includelib  \masm32\lib\d3d8.lib

	include     \masm32\include\winextra.def
	
	;include \masm32\include\Irvine32.inc
	;include \masm32\Irvine\Irvine32.lib
	
	; include \masm32\MasmBasic\MasmBasic.inc
	
	;FILES --------------------------------------------------
	include \ASM\Text ADV\src\strings.asm
	include \ASM\Text ADV\src\functions.asm
	include \ASM\Text ADV\src\directX.asm
	
.data

.data?
       buffer db 100 dup(?)   ; reserve 100 bytes for input storage
	   choice db 20 dup(?)
.code

createGraphicsWindow:
		invoke GetModuleHandle,NULL ; Get hInstance
		sub edx,edx
		invoke WinMain,eax,edx,edx,edx
		;invoke ExitProcess,eax
		jmp noreply
		
start:
		INVOKE SetConsoleTitle, ADDR ConsTitleString     ;Set window title. I figured this out through deep library search. In kernel32
		call general
		call INPUT
		call CMPchar		
		
exit0:
		inkey
		push 0
		call ExitProcess

end start
