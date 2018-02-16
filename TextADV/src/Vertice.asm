.code

InitTexture proc

		LOCAL fileHandle:DWORD,lpRow:DWORD,dummy:DWORD
	
	pusha

	; Create a texture 256x256 elements large.	
	COINVOKE lpD3DDevice,IDirect3DDevice8,CreateTexture, 256, 256, 0, 0,\
					      D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, ADDR lpTexture
	.if eax<0
		MSGBOX "Failed to create texture"
		popa
		return FALSE
	.endif

	; Lock the texture rect so that we can write to it.	
	COINVOKE lpTexture,IDirect3DTexture8,LockRect,0,ADDR d3dlr,0,0
	.if d3dlr.pBits == NULL
		MSGBOX "Failed to lock texture"
		popa
		return FALSE
	.endif

	; Open the texture file
	invoke CreateFile,ADDR szTextureName, GENERIC_READ, 0, NULL, OPEN_EXISTING,\
                    	  FILE_ATTRIBUTE_NORMAL or FILE_FLAG_SEQUENTIAL_SCAN,NULL
 	.if eax == INVALID_HANDLE_VALUE
    		MSGBOX "Missing file: mad040.raw"
    		return FALSE
    	.endif
    	mov fileHandle,eax

	;---------------------------------------------------------------------------------------
	; The texture file is BGR format and we want it in ARGB format so we'll convert it here.
	
	; Allocate memory for one row of image data.
	invoke LocalAlloc,LPTR,768
	.if eax == NULL
		MSGBOX "Out of memory"
		return NULL
	.endif
	mov lpRow,eax

	mov edi,d3dlr.pBits
	mov edx,d3dlr.Pitch

	mov ecx,256
	mov ebx,0
	@@upload_texture_y:
		pusha
		invoke ReadFile, fileHandle, lpRow, 768, ADDR dummy, NULL
		popa
		push edi
		push ecx
		mov esi,lpRow
		mov ecx,256
		@@upload_texture_x:
			mov al,[esi]
			mov [edi+2],al
			mov al,[esi+1]
			mov [edi+1],al
			mov al,[esi+2]
			mov [edi],al
			; Set alpha to FFh 
			mov al,0FFh
			mov [edi+3],al
			add esi,3
			add edi,4
			dec ecx
		jnz @@upload_texture_x
		pop ecx
		pop edi
		add edi,edx
		dec ecx
	jnz @@upload_texture_y

	invoke LocalFree,lpRow	
	;---------------------------------------------------------------------------------------

	invoke CloseHandle,fileHandle
	
	COINVOKE lpTexture,IDirect3DTexture8,UnlockRect,0

	; Set our created texture to the current one.
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetTexture, 0, lpTexture

	; Set up the texture parameters.
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetTextureStageState, 0, D3DTSS_MINFILTER, D3DTEXF_LINEAR
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetTextureStageState, 0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetTextureStageState, 0, D3DTSS_COLOROP, D3DTOP_MODULATE4X
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetTextureStageState, 0, D3DTSS_COLORARG1, D3DTA_TEXTURE
	COINVOKE lpD3DDevice,IDirect3DDevice8,SetTextureStageState, 0, D3DTSS_COLORARG2, D3DTA_CURRENT

	popa

	return lpTexture

InitTexture endp 
