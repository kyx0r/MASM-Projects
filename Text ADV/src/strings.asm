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
    hWindow         HWND    ?
    hInstance       HANDLE  ?
    IDI_ICON        equ     01h

    g_pD3D              LPDIRECT3D8             NULL
    g_pd3dDevice        LPDIRECT3DDEVICE8       NULL
	g_pVB               LPDIRECT3DVERTEXBUFFER8 NULL        ; Buffer to hold vertices
	
	;CUSTOMVERTEX-------------------------------------------------------------------
	
	D3DFVF_CUSTOMVERTEX EQU (D3DFVF_XYZRHW OR D3DFVF_DIFFUSE)

    CUSTOMVERTEX    struct  DWORD
        x       FLOAT   ?
        y       FLOAT   ? 
        z       FLOAT   ?
        rhw     FLOAT   ?               ; The transformed position for the vertex
        color   DWORD   ?               ; The vertex color
    CUSTOMVERTEX    ENDS
	
    tmpfloat        FLOAT                   1.0f
    d3dcol        D3DCOLOR                00000000h;
	
	x equ <250.0f >
    y equ <250.0f >

    g_Vertices CUSTOMVERTEX <150.0f, 50.0f, 0.5f, 1.0f, 0ffff0000h>,\
                           <x, y, 0.5f, 1.0f, 0ff00ff00h>,\
                           <50.0f, y, 0.5f, 1.0f, 0ff00ffffh>
	
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