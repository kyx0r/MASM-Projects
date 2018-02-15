
.code

;-----------------------------------------------------------------------------
; Name: Render
; Desc: Draws the scene
;-----------------------------------------------------------------------------
Render2D PROC
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
Render2D ENDP

Render3D PROC
	pusha
	
	COINVOKE lpD3DDevice,IDirect3DDevice8,Clear, 0, NULL, D3DCLEAR_TARGET or D3DCLEAR_ZBUFFER,\
	                                             clearColor, clearDepth, 0

	; Beginning of scene.	
	COINVOKE lpD3DDevice,IDirect3DDevice8,BeginScene

		; Rotate 'theta' radians about all three axes.
		invoke _D3DXMatrixRotationX,ADDR worldMatrix,theta
		invoke _D3DXMatrixRotationY,ADDR tempMatrix,theta
		invoke _D3DXMatrixMultiply,ADDR worldMatrix,ADDR worldMatrix,ADDR tempMatrix
		invoke _D3DXMatrixRotationZ,ADDR tempMatrix,theta
		invoke _D3DXMatrixMultiply,ADDR worldMatrix,ADDR worldMatrix,ADDR tempMatrix

		; Finally do the translation.		
		invoke _D3DXMatrixTranslation, ADDR tempMatrix, xtrans,ytrans, ztrans
		invoke _D3DXMatrixMultiply,ADDR worldMatrix,ADDR worldMatrix,ADDR tempMatrix

		; And set this to the current world matrix.		
		COINVOKE lpD3DDevice,IDirect3DDevice8,SetTransform, D3DTS_WORLD, ADDR worldMatrix		
	
		; Set the stream source to our vertex buffer.
		COINVOKE lpD3DDevice,IDirect3DDevice8,SetStreamSource, 0, lpVertexBuffer, sizeof CUBE

		; Draw 12 triangles (6 faces of a cube).
		COINVOKE lpD3DDevice,IDirect3DDevice8,DrawPrimitive, D3DPT_TRIANGLELIST, 0, 12

	; End of scene.
	COINVOKE lpD3DDevice,IDirect3DDevice8,EndScene

	; Swap the front and back buffers.
	COINVOKE lpD3DDevice,IDirect3DDevice8,Present, NULL, NULL, NULL, NULL

	fld dword ptr [theta]
	fadd dword ptr [d_theta]
	fstp dword ptr [theta]

	popa
	ret
Render3D ENDP