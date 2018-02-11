;include \ASM\Text ADV\src\strings.asm

.code

;-----------------------------------------------------------------------------
; Name: Render
; Desc: Draws the scene
;-----------------------------------------------------------------------------
Render PROC

	LOCAL buffer[128]:byte
	
;   Make sure that the Direct3D8 device exists.
    mov eax, g_pd3dDevice
    .if eax == NULL
        ret
    .endif

;   Clear the backbuffer to a blue color (the 4th parameter).
    mcall [g_pd3dDevice],IDirect3DDevice8_Clear,0, NULL, D3DCLEAR_TARGET, 000000000, tmpfloat, 0
    
;   Begin the scene.
     mcall [g_pd3dDevice],IDirect3DDevice8_BeginScene
    
;   Rendering of scene objects can happen here
  
;   End the scene.
    mcall [g_pd3dDevice],IDirect3DDevice8_EndScene
    
;   Present the backbuffer contents to the display.
    mcall [g_pd3dDevice],IDirect3DDevice8_Present, NULL, NULL, NULL, NULL
	
	; mcall [g_pFontUL],ID3DXFont_DrawTextA, ADDR plainText, -1, ADDR plainTextC, DT_LEFT OR DT_WORDBREAK , 0ff00ffffh
    ; invoke wsprintf,addr buffer,addr szTexttemplate
    
    ret
Render ENDP