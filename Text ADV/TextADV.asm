	;LIBS ----------------------------------------------------
	include \masm32\include\masm32rt.inc

	include     \masm32\include\winmm.inc
	includelib  \masm32\lib\winmm.lib

	includelib  \masm32\lib\advapi32.lib

	include     \masm32\include\d3d8.inc
	includelib  \masm32\lib\d3d8.lib

	include     \masm32\include\winextra.def
	
	;FILES --------------------------------------------------
	include \ASM\Text ADV\src\strings.asm
	include \ASM\Text ADV\src\functions.asm
	
.data


.data?
       buffer db 100 dup(?)   ; reserve 100 bytes for input storage
	   choice db 20 dup(?)
.code

	   	   		
start:
		INVOKE SetConsoleTitle, ADDR WinTitleString     ;Set window title. I figured this out through deep library search. In kernel32
		call general
		call INPUT
		call CMPchar	
exit0:
		inkey
		push 0
		call ExitProcess

end start
