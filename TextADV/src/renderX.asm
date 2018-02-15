
.code

;-----------------------------------------------------------------------------
; Name: Render
; Desc: Draws the scene
;-----------------------------------------------------------------------------
Draw PROC
	pusha
	
	; Cleat the target with color 00000000h (black).
	; COINVOKE is defined in macros.inc. It's used to call functions through a COM interface.
	COINVOKE lpD3DDevice,IDirect3DDevice8,Clear, 0, NULL, D3DCLEAR_TARGET, 00000000h, 0, 0

	; Beginning of scene.	
	COINVOKE lpD3DDevice,IDirect3DDevice8,BeginScene

		; Set the vertex format.
		COINVOKE lpD3DDevice,IDirect3DDevice8,SetVertexShader, D3DFVF_XYZ or D3DFVF_DIFFUSE

		; Draw a triangle.		
		COINVOKE lpD3DDevice,IDirect3DDevice8,DrawPrimitiveUP, D3DPT_TRIANGLELIST, 1, ADDR vertexes, sizeof CUSTOM_VERTEX
		COINVOKE lpD3DDevice,IDirect3DDevice8,DrawPrimitiveUP, D3DPT_LINESTRIP, 1, ADDR cubevert, sizeof CUBE
		
		;PRIMITIVES--------------------------------------------------------------------------------------------------------
		; D3DPT_POINTLIST             EQU 1
		; D3DPT_LINELIST              EQU 2
		; D3DPT_LINESTRIP             EQU 3
		; D3DPT_TRIANGLELIST          EQU 4
		; D3DPT_TRIANGLESTRIP         EQU 5
		
		
	; End of scene.
	COINVOKE lpD3DDevice,IDirect3DDevice8,EndScene

	; Swap the front and back buffers.
	COINVOKE lpD3DDevice,IDirect3DDevice8,Present, NULL, NULL, NULL, NULL

	popa
	ret
Draw ENDP