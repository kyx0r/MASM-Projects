; Functions for easy setup of Direct3D 8 
; /Mic, 2003


.486
.model flat,stdcall
option casemap:none

include .\d3d8.inc
include .\macros.inc
include \masm32\include\kernel32.inc
include \masm32\include\ole32.inc
include \masm32\include\user32.inc

includelib \masm32\lib\KERNEL32.LIB
includelib \masm32\lib\ole32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\d3d8.lib


.data?

	PUBLIC lpD3D
	PUBLIC lpD3DDevice
	PUBLIC d3ddm
	PUBLIC d3dpp

	lpD3D		dd ?
	lpD3DDevice	dd ?
	d3ddm		D3DDISPLAYMODE <?>
	d3dpp		D3DPRESENT_PARAMETERS <?>
	
	clientRect	RECT <?>


.code


CreateD3DDevice PROC owner:HWND,width_:DWORD,height:DWORD,bitcount:DWORD,fullscreen:DWORD
	pusha
	
	invoke CoInitialize,NULL

	invoke Direct3DCreate8,D3D_SDK_VERSION
	test eax,eax
	jnz @@Direct3DCreate8_ok
		MSGBOX "Unable to create a Direct3D interface"
		popa
		return FALSE
	@@Direct3DCreate8_ok:
	mov lpD3D,eax

  
  	ZeroMemory OFFSET d3ddm,sizeof D3DDISPLAYMODE
	.if fullscreen != 0
		mov eax,width_
		mov ebx,height
		mov d3ddm.Width_,eax
		mov d3ddm.Height,ebx
		mov d3ddm.RefreshRate,0
		mov ebx,bitcount
		.if ebx == 8
		.elseif ebx == 15
			mov d3ddm.Format,D3DFMT_X1R5G5B5
		.elseif ebx == 16
			mov d3ddm.Format,D3DFMT_R5G6B5
		.elseif ebx == 24
			mov d3ddm.Format,D3DFMT_X8R8G8B8
		.elseif ebx == 32
			mov d3ddm.Format,D3DFMT_A8R8G8B8
		.endif
	.else	
		COINVOKE lpD3D, IDirect3D8, GetAdapterDisplayMode, D3DADAPTER_DEFAULT, ADDR d3ddm
		test eax,eax
		jge @@gadm_ok
			MSGBOX "Unable to get the current display mode"
			popa
			return FALSE
		@@gadm_ok:
	.endif
	

	ZeroMemory OFFSET d3dpp,sizeof D3DPRESENT_PARAMETERS

	mov eax,d3ddm.Format
	mov d3dpp.BackBufferFormat,eax
	mov d3dpp.BackBufferCount,1
	mov eax,owner
	mov d3dpp.hDeviceWindow,eax

	.if fullscreen == 0
		mov d3dpp.Windowed,TRUE
		invoke GetClientRect,owner,ADDR clientRect
		mov eax,clientRect.right
		mov ebx,clientRect.bottom
		sub eax,clientRect.left
		sub ebx,clientRect.top
		mov d3dpp.BackBufferWidth,eax
		mov d3dpp.BackBufferHeight,ebx
	.else
		mov d3dpp.Windowed,FALSE
		mov eax,d3ddm.Width_
		mov ebx,d3ddm.Height
		mov d3dpp.BackBufferWidth,eax
		mov d3dpp.BackBufferHeight,ebx
	.endif
	
	mov d3dpp.SwapEffect,D3DSWAPEFFECT_COPY_VSYNC	

	;; Select the best depth buffer, select 32, 24 or 16 bit
	mov d3dpp.EnableAutoDepthStencil,FALSE
	
	COINVOKE lpD3D, IDirect3D8, CheckDeviceFormat, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3ddm.Format,D3DUSAGE_DEPTHSTENCIL,D3DRTYPE_SURFACE,D3DFMT_D32
	.if eax==0
		mov d3dpp.AutoDepthStencilFormat,D3DFMT_D32
		mov d3dpp.EnableAutoDepthStencil,TRUE
	.else
		COINVOKE lpD3D, IDirect3D8, CheckDeviceFormat, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3ddm.Format,D3DUSAGE_DEPTHSTENCIL,D3DRTYPE_SURFACE,D3DFMT_D24X8
		.if eax==0
			mov d3dpp.AutoDepthStencilFormat,D3DFMT_D24X8
			mov d3dpp.EnableAutoDepthStencil,TRUE
		.else
			COINVOKE lpD3D, IDirect3D8, CheckDeviceFormat, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3ddm.Format,D3DUSAGE_DEPTHSTENCIL,D3DRTYPE_SURFACE,D3DFMT_D16
			.if eax==0
				mov d3dpp.AutoDepthStencilFormat,D3DFMT_D16
				mov d3dpp.EnableAutoDepthStencil,TRUE
			.endif
		.endif
	.endif

   	;Create a Direct3D device.
    	COINVOKE lpD3D, IDirect3D8, CreateDevice, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, owner, D3DCREATE_HARDWARE_VERTEXPROCESSING, ADDR d3dpp, ADDR lpD3DDevice
	test eax,eax
	jge @@createdev_ok
	    	COINVOKE lpD3D, IDirect3D8, CreateDevice, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, owner, D3DCREATE_SOFTWARE_VERTEXPROCESSING,ADDR d3dpp, ADDR lpD3DDevice
		test eax,eax
		jge @@createdev_ok
			MSGBOX "Unable to create a Direct3D device"
			popa
			return FALSE
	@@createdev_ok:
	.if lpD3DDevice == NULL
		MSGBOX "Device pointer is NULL"
		popa
		return FALSE
	.endif

	
	popa
	return TRUE
CreateD3DDevice ENDP



DestroyD3DDevice PROC
	pusha
	
	.if lpD3DDevice != NULL
		COINVOKE lpD3DDevice,IDirect3DDevice8, Release
		mov lpD3DDevice,NULL
	.endif

	.if lpD3D != NULL
		COINVOKE lpD3D,IDirect3D8, Release
		mov lpD3D,NULL
	.endif
	
	invoke CoUninitialize
	
	popa
	ret
DestroyD3DDevice ENDP

END
