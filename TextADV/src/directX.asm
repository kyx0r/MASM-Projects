include \ASM\TextADV\src\Vertice.asm
include \ASM\TextADV\src\renderX.asm

.code

Init2D PROC
	pusha
	
	invoke CreateD3DDevice,hWindow,XDIM,YDIM,32,0
	.if eax == FALSE
		invoke ExitProcess,0
		popa
		ret
	.endif

	; Disable Z-buffering.
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetRenderState, D3DRS_ZENABLE, D3DZB_FALSE
	
	; Disable lighting.
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetRenderState, D3DRS_LIGHTING, FALSE
	
	; Set the culling mode to no culling.
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetRenderState, D3DRS_CULLMODE, D3DCULL_NONE


	; Transform the world matrix to move all objects "backwards".
	invoke _D3DXMatrixTranslation, ADDR worldMatrix, xtrans,ytrans, ztrans
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetTransform, D3DTS_WORLD, ADDR worldMatrix
	
	; Set up a projection matrix. I'm using a right-handed coordinate system here, i.e.
	; Z grows "towards the screen".
	invoke _D3DXMatrixPerspectiveFovRH, ADDR projMatrix, fov, aspect, zNear, zFar
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetTransform, D3DTS_PROJECTION, ADDR projMatrix
		
	popa
	ret
Init2D ENDP



Init3D PROC
	LOCAL temp:DWORD
	
	pusha
	
	invoke CreateD3DDevice,hWindow,XDIM,YDIM,32,0
	.if eax == FALSE
		invoke ExitProcess,0
		popa
		ret
	.endif

	; Set the culling mode to clockwise defined backfaces.
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetRenderState, D3DRS_CULLMODE, D3DCULL_CW

	; Set the vertex format.
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetVertexShader, D3DFVF_XYZ + D3DFVF_NORMAL + D3DFVF_TEX1

	; Create a vertex buffer
	mov eax,36
	mov ebx,sizeof CUBE
	mul ebx
	mov temp,eax
	COINVOKE lpD3DDevice,IDirect3DDevice8,CreateVertexBuffer, temp, 0,\
	                                                          D3DFVF_XYZ + D3DFVF_NORMAL + D3DFVF_TEX1,\
	                                                          D3DPOOL_MANAGED, ADDR lpVertexBuffer
	.if lpVertexBuffer == NULL
		MSGBOX "Failed to create vertex buffer"
		invoke ExitProcess,0
	.endif


	; Lock the vertex buffer.
	COINVOKE lpVertexBuffer,IDirect3DVertexBuffer8,Lock_,0, 0, ADDR lpVertexBufferData, NULL
	
	; Populate the vertex buffer with the cube data.
	mov esi,OFFSET cubevert
	mov edi,lpVertexBufferData
	mov ecx,temp
	shr ecx,2
	rep movsd

	; Unlock the vertex buffer
	COINVOKE lpVertexBuffer,IDirect3DVertexBuffer8,Unlock
	
        invoke InitTexture
        .if eax == NULL
        	invoke ExitProcess,0
        .endif
         
	
	; Set up a view matrix.
	invoke _D3DXMatrixLookAtRH, ADDR viewMatrix, ADDR cameraPos, ADDR lookAt, ADDR upVector
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetTransform, D3DTS_VIEW, ADDR viewMatrix
	
	; Set up a projection matrix. 
	invoke _D3DXMatrixPerspectiveFovRH, ADDR projMatrix, fov, aspect, zNear, zFar
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetTransform, D3DTS_PROJECTION, ADDR projMatrix

	; Disable Z-buffering.
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetRenderState, D3DRS_ZENABLE, D3DZB_FALSE
	
	; Enable lighting.
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetRenderState, D3DRS_LIGHTING, TRUE
	COINVOKE lpD3DDevice,IDirect3DDevice8,LightEnable, 0, TRUE		

	; Set the light and material parameters.
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetLight, 0, ADDR light
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetMaterial, ADDR material

	popa
	ret
Init3D ENDP


WndProc2D PROC hWnd:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
	LOCAL crect:RECT
	LOCAL ps:PAINTSTRUCT
	
 	mov eax,uMsg

 	.if eax==WM_PAINT
    		invoke BeginPaint,hWnd,ADDR ps

		; Draw another frame 
    		invoke Render2D
			
    		invoke EndPaint,hWnd,ADDR ps
    		xor eax,eax
  
  	.elseif eax==WM_KEYDOWN
    		.if wParam==VK_ESCAPE
      			invoke PostMessage,hWnd,WM_CLOSE,NULL,NULL
    		.endif
		xor eax,eax
		
  	.elseif eax==WM_DESTROY
    		invoke PostQuitMessage,0
 
	.else
 		invoke DefWindowProc,hWnd,uMsg,wParam,lParam
 	.endif
	
	ret
	
WndProc2D ENDP

WndProc3D proc hWnd:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
		LOCAL crect:RECT
		LOCAL ps:PAINTSTRUCT
		mov eax,uMsg
	
	 	.if eax==WM_PAINT
    		invoke BeginPaint,hWnd,ADDR ps

		; Draw another frame 
    		invoke Render3D
			
    		invoke EndPaint,hWnd,ADDR ps
    		xor eax,eax
  
  	.elseif eax==WM_KEYDOWN
    		.if wParam==VK_ESCAPE
      			invoke PostMessage,hWnd,WM_CLOSE,NULL,NULL
    		.endif
		xor eax,eax
		
  	.elseif eax==WM_DESTROY
    		invoke PostQuitMessage,0
 
	.else
 		invoke DefWindowProc,hWnd,uMsg,wParam,lParam
 	.endif	
	
 	ret
WndProc3D endp

; setDimension proc wc:DWORD
	; cmp BX,8
	; je Pass
	; mov wc.lpfnWndProc,offset WndProc2D
	; Pass:
	; mov wc.lpfnWndProc,offset WndProc3D
	; ret
; setDimension endp


WinMain PROC hInst:DWORD,prevInstance:DWORD,cmdlinePtr:DWORD,cmdShow:DWORD
	LOCAL wc:WNDCLASSEX
	LOCAL msg:MSG

 	lea edi,wc
 	xor eax,eax
 	mov ecx,(sizeof WNDCLASSEX)/4
 	rep stosd
 	mov eax,hInst
  	mov wc.hInstance,eax
 	mov wc.cbSize, sizeof WNDCLASSEX
 	mov wc.style,CS_OWNDC or CS_HREDRAW or CS_VREDRAW
 	mov wc.lpszClassName,offset MyClassName
 	cmp BX,8
	je notPass
	mov wc.lpfnWndProc,offset WndProc2D
	jmp Pass
	notPass:
	mov wc.lpfnWndProc,offset WndProc3D
	jmp Pass
	Pass:
 	invoke LoadCursor,NULL,IDC_ARROW
 	mov wc.hCursor,eax
 	mov wc.hbrBackground,0
	invoke LoadIcon, hInst, IDI_ICON
	mov wc.hIcon,eax
	mov wc.hIconSm, NULL

 	invoke RegisterClassEx,ADDR wc

 	sub eax,eax 
 	invoke CreateWindowEx,NULL,ADDR MyClassName,ADDR WinTitleString,WS_OVERLAPPEDWINDOW OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS,80,80,XDIM,YDIM,eax,eax,hInst,eax
 	mov hWindow,eax

	; Initialize

	cmp BX,8
	je DX3
	invoke Init2D
	jmp passs
	DX3:
	invoke Init3D
	jmp passs
	
	passs:
 	invoke ShowWindow,eax,SW_SHOWDEFAULT
 	invoke UpdateWindow,hWindow  

 	@@winmainmsgloop:
  		invoke InvalidateRect,hWindow,NULL,FALSE 
  		sub eax,eax
  		lea edi,msg
  		invoke GetMessage,edi,eax,eax,eax
  		test eax,eax
  		jz @@quitmsgposted
  		push edi
  		push edi
  		call TranslateMessage
  		call DispatchMessage
  	jmp @@winmainmsgloop
 
 	EVEN
 
 	@@quitmsgposted:
	
	; Destroy the D3D device.  
  	invoke DestroyD3DDevice
  	
  	ret
WinMain ENDP

