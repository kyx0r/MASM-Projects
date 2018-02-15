.data

string proc
	   ;Console strings ----------------------------------------------
	   
	   num1 db 0
       msg1 db "What is your name? ",0
       msg2 db "Hello ",0
	   backquote db "'",0
	   frontquote db "'",0
	   space db "   ",0
	   welcome db " Welcome to Text Adventure!",0ah,0
	   bye db "Goodbye!",0ah,0
		
	   continue db "Do you want to continue?",0ah,0
	   error db "Invalid syntax. Try again.",0ah,0
	   yes db "Yes",0
	   no db "No",0
	   ConsTitleString db 'Text Adventure',0    ; Window title
	   
	   ; DirectX strings -----------------------------------------------
	   
	   MyClassName         db 'Directx',0            ; Our class name
       WinTitleString      db 'Graphics window',0    ; Window title
	   plainText         db "Here will be all graphics for the project.",0
	   szTexttemplate db "%d",0
	   
string endp	   

Global_Vars proc
	;-----------------------------------------------------------------------------
	; Global variables
	;-----------------------------------------------------------------------------
	EXTERN lpD3DDevice:DWORD
	
    hWindow         HWND    ?
    hInstance       HANDLE  ?
    IDI_ICON        equ     01h
	
	; Window dimensions
	XDIM	EQU 640
	YDIM	EQU 480
	
	

    ;g_pD3D              LPDIRECT3D8             NULL
    ;g_pd3dDevice        LPDIRECT3DDEVICE8       NULL
	;g_pVB               LPDIRECT3DVERTEXBUFFER8 NULL        ; Buffer to hold vertices
	
	;CUSTOMVERTEX-------------------------------------------------------------------
	
	CUSTOM_VERTEX STRUCT 
	x	REAL4 ?
	y	REAL4 ?
	z	REAL4 ?
	col	dd ?
	CUSTOM_VERTEX ENDS
	
	xtrans		REAL4 0.0
	ytrans		REAL4 0.0
	ztrans		REAL4 -1.5
	
	fov		    REAL4 1.0472	; Field of vision: 60 * PI / 180
	aspect		REAL4 0.75	; Aspect ration: height/width
	zNear		REAL4 1.0	; Distance to near clipping plane
	zFar		REAL4 100.0	; Distance to far clipping plane

	; This is the triangle. The colors are in ARGB format.
	vertexes	CUSTOM_VERTEX < 0.0,  0.7, 0.0, 0ffff0000h>,
	                              <-0.7, -0.7, 0.0, 0ff00ff00h>,
	                              < 0.7, -0.7, 0.0, 0ff0000ffh>
								  ;< 0.7, -0.7, 0.0, 0ff0000ffh>
								  ;< 0.7, -0.7, 0.0, 0ff0000ffh>
	
	;CUBE------------------------------------------------------------------------------
	CUBE STRUCT 
	x	REAL4 ?
	y	REAL4 ?
	z	REAL4 ?
	col dd ?
	; nx	REAL4 ?
	; ny	REAL4 ?
	; nz	REAL4 ?
	; u	REAL4 ?
	; v	REAL4 ?
    CUBE ENDS
	
	cubevert	CUBE < 0.50,  0.7, 0.0, 0ffff0000h>,
					< -0.50,  0.7, 0.0, 0ffff0000h>,
	                              <-0.17, -0.3, 0.0, 0ff00ff00h>,
	                              < 0.17, -0.3, 0.0, 0ff0000ffh>
	
	
	;FONT------------------------------------------------------------------------------
	
	;g_pFontUL           LPD3DXFONT              NULL    ; Used to create the under-lined font
	
	
	;Coordinates------------------------------------------------------------------
	
	plainTextC RECT <10,10,200,30>
	
	
	
	;Macro------------------------------------------------------------------------
	
	return MACRO returnvalue
		mov eax, returnvalue ;just a macro example. 
		ret
	ENDM
	
Global_Vars endp


.data?

	NotIndexed proc
		buffer db 100 dup(?)   ; reserve 100 bytes for input storage
		choice db 20 dup(?)
		;hWindow		dd ?
	
		viewMatrix	D3DXMATRIX <?>
		projMatrix	D3DXMATRIX <?>
		worldMatrix	D3DXMATRIX <?>
	NotIndexed endp	
		
		