	;LIBS ----------------------------------------------------
	include \masm32\include\masm32rt.inc

	; include     \masm32\include\winmm.inc
	; includelib  \masm32\lib\winmm.lib

	; includelib  \masm32\lib\advapi32.lib

	; include     \masm32\include\d3d8.inc
	; includelib  \masm32\lib\d3d8.lib

	;include     \masm32\include\winextra.def
	
	include     c:\ASM\TextADV\include\d3d8.inc
	include     c:\ASM\TextADV\include\macros.inc
	include     c:\ASM\TextADV\include\matrix.inc
	include     c:\ASM\TextADV\include\d3dsetup.inc
	;include 	c:\ASM\TextADV\include\cube.inc
	;include     \masm32\include\d3dx8core.inc
	
	;FILES --------------------------------------------------
	include \ASM\TextADV\src\data.asm
	include \ASM\TextADV\src\directX.asm
	include \ASM\TextADV\src\functions.asm
	
.data

.data?
	   
.code
		
createGraphicsWindow:
		invoke GetModuleHandle,NULL 
		invoke WinMain,eax,NULL,NULL,NULL
		;invoke ExitProcess,eax
		jmp request3D
		
start:
		;invoke CreateFile, addr szTextureName, GENERIC_WRITE, FILE_SHARE_WRITE or FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
		
		INVOKE SetConsoleTitle, ADDR ConsTitleString     ;Set window title. I figured this out through deep library search. In kernel32
		call general
		call INPUT
		call CMPchar
		
		
exit0:
		inkey
		push 0
		call ExitProcess

end start
