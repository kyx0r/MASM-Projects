; Some matrix functions to use instead of the ones in D3DX
; /Mic, 2003

; There seems to be a bug in (either or both) MatrixLookAtLH and
; MatrixPerspectiveFovLH. Use the RH versions instead.


.486
.model flat,stdcall
option casemap:none


include .\macros.inc
include .\d3d8.inc
include .\vector.inc


.data
	_D3DX_two	REAL4 2.0
	one_half	REAL4 0.5

.data?
	xaxis_		D3DXVECTOR <?>
	yaxis_		D3DXVECTOR <?>
	zaxis_		D3DXVECTOR <?>
	tempv_		D3DXVECTOR <?>
	tempm_		D3DXMATRIX <?>
.code	



_D3DXMatrixLookAtLH PROC pOut:DWORD,camera:DWORD,lookat:DWORD,upvec:DWORD
	
	pusha

	invoke _D3DXVec3Subtract,ADDR tempv_,lookat,camera
	invoke _D3DXVec3Normalize,ADDR zaxis_,ADDR tempv_
	
	invoke _D3DXVec3Cross,ADDR tempv_,upvec,ADDR zaxis_
	invoke _D3DXVec3Normalize,ADDR xaxis_,ADDR tempv_
	
	invoke _D3DXVec3Cross,ADDR yaxis_,ADDR zaxis_,ADDR xaxis_

	mov edx,pOut
	
	; Row 1
	mov eax,xaxis_.x
	mov ebx,yaxis_.x
	mov ecx,zaxis_.x
	mov [edx],eax
	mov [edx+4],ebx
	mov [edx+8],ecx
	fldz
	fstp dword ptr [edx+12]
	
	; Row 2
	mov eax,xaxis_.y
	mov ebx,yaxis_.y
	mov ecx,zaxis_.y
	mov [edx+16],eax
	mov [edx+20],ebx
	mov [edx+24],ecx
	fldz
	fstp dword ptr [edx+28]

	; Row 3
	mov eax,xaxis_.z
	mov ebx,yaxis_.z
	mov ecx,zaxis_.z
	mov [edx+32],eax
	mov [edx+36],ebx
	mov [edx+40],ecx
	fldz
	fstp dword ptr [edx+44]

	; Row 4
	invoke _D3DXVec3Dot,ADDR xaxis_,camera
	fldz
	fsub st(0),st(1)
	fstp dword ptr [edx+48]
	invoke _D3DXVec3Dot,ADDR yaxis_,camera
	fldz
	fsub st(0),st(1)
	fstp dword ptr [edx+52]
	invoke _D3DXVec3Dot,ADDR zaxis_,camera
	fldz
	fsub st(0),st(1)
	fstp dword ptr [edx+56]
	fld1
	fstp dword ptr [edx+60]

	popa	
	return pOut
_D3DXMatrixLookAtLH ENDP



_D3DXMatrixLookAtRH PROC pOut:DWORD,camera:DWORD,lookat:DWORD,upvec:DWORD
	
	pusha

	invoke _D3DXVec3Subtract,ADDR tempv_,camera,lookat
	invoke _D3DXVec3Normalize,ADDR zaxis_,ADDR tempv_
	
	invoke _D3DXVec3Cross,ADDR tempv_,upvec,ADDR zaxis_
	invoke _D3DXVec3Normalize,ADDR xaxis_,ADDR tempv_
	
	invoke _D3DXVec3Cross,ADDR yaxis_,ADDR zaxis_,ADDR xaxis_

	mov edx,pOut
	
	; Row 1
	mov eax,xaxis_.x
	mov ebx,yaxis_.x
	mov ecx,zaxis_.x
	mov [edx],eax
	mov [edx+4],ebx
	mov [edx+8],ecx
	fldz
	fstp dword ptr [edx+12]
	
	; Row 2
	mov eax,xaxis_.y
	mov ebx,yaxis_.y
	mov ecx,zaxis_.y
	mov [edx+16],eax
	mov [edx+20],ebx
	mov [edx+24],ecx
	fldz
	fstp dword ptr [edx+28]

	; Row 3
	mov eax,xaxis_.z
	mov ebx,yaxis_.z
	mov ecx,zaxis_.z
	mov [edx+32],eax
	mov [edx+36],ebx
	mov [edx+40],ecx
	fldz
	fstp dword ptr [edx+44]

	; Row 4
	invoke _D3DXVec3Dot,ADDR xaxis_,camera
	fchs
	fstp dword ptr [edx+48]
	invoke _D3DXVec3Dot,ADDR yaxis_,camera
	fchs
	fstp dword ptr [edx+52]
	invoke _D3DXVec3Dot,ADDR zaxis_,camera
	fchs
	fstp dword ptr [edx+56]
	fld1
	fstp dword ptr [edx+60]

	popa	
	return pOut
_D3DXMatrixLookAtRH ENDP



_D3DXMatrixPerspectiveFovLH PROC pOut:DWORD,fovy:DWORD,Aspect:DWORD,zn:DWORD,zf:DWORD
    	LOCAL w:REAL4,h:REAL4
    	
    	fld     dword ptr [fovy]       
   	fmul    dword ptr [one_half]          
  
      	fsincos
      	fdiv 	st(0),st(1)
       	fst     dword ptr [h]  			; h = cos(fov/2) / sin(fov/2)             
    	fdiv	dword ptr [Aspect]
    	fstp     dword ptr [w]               

       	mov      eax,pOut       

	; Row 1       	
       	fld	dword ptr [zn]
       	fadd	dword ptr [zn]
       	fdiv	dword ptr [w]
        fstp     dword ptr [eax]               
    	fldz                                   
      	fst     dword ptr [eax+04h]           
       	fst     dword ptr [eax+08h]           
       	fstp     dword ptr [eax+0Ch]           

     	; Row 2
     	fld	dword ptr [zn]
       	fadd	dword ptr [zn]
       	fdiv	dword ptr [h]
	fstp	dword ptr [eax+14h]       	
        fldz                                   
       	fst     dword ptr [eax+010h]          
      	fst     dword ptr [eax+018h]          
      	fst     dword ptr [eax+01ch]          

	fld 	dword ptr [zf]
	fld 	dword ptr [zf]
	fsub 	dword ptr [zn]
	fdivp 	st(1),st(0)
	fstp	dword ptr [eax+28h]
	fldz
	fst	dword ptr [eax+20h]
	fstp	dword ptr [eax+24h]
 	mov      dword ptr [eax+02Ch],03F800000h	; _33 = 1.0

	fld 	dword ptr [zf]
	fmul	dword ptr [zn]
	fld 	dword ptr [zn]
	fsub 	dword ptr [zf]
	fdivp 	st(1),st(0)
	fstp	dword ptr [eax+38h]
	fldz
	fst	dword ptr [eax+30h]
	fstp	dword ptr [eax+34h]
	fstp	dword ptr [eax+3ch]

        return pOut                               
_D3DXMatrixPerspectiveFovLH ENDP



_D3DXMatrixPerspectiveFovRH PROC pOut:DWORD,fovy:DWORD,Aspect:DWORD,zn:DWORD,zf:DWORD
    	LOCAL w:REAL4,h:REAL4
    	
    	fld     dword ptr [fovy]       
   	fmul    dword ptr [one_half]          
  
      	fsincos
      	fdiv 	st(0),st(1)
       	fst     dword ptr [h]  			; h = cos(fov/2) / sin(fov/2)             
    	fdiv	dword ptr [Aspect]
    	fstp     dword ptr [w]               

       	mov      eax,pOut       

	; Row 1       	
       	fld	dword ptr [zn]
       	fadd	dword ptr [zn]
       	fdiv	dword ptr [w]
        fstp     dword ptr [eax]               
    	fldz                                   
      	fst     dword ptr [eax+04h]           
       	fst     dword ptr [eax+08h]           
       	fstp     dword ptr [eax+0Ch]           

     	; Row 2
     	fld	dword ptr [zn]
       	fadd	dword ptr [zn]
       	fdiv	dword ptr [h]
	fstp	dword ptr [eax+14h]       	
        fldz                                   
       	fst     dword ptr [eax+010h]          
      	fst     dword ptr [eax+018h]          
      	fst     dword ptr [eax+01ch]          

	fld 	dword ptr [zf]
	fld 	dword ptr [zn]
	fsub 	dword ptr [zf]
	fdivp 	st(1),st(0)
	fstp	dword ptr [eax+28h]
	fldz
	fst	dword ptr [eax+20h]
	fstp	dword ptr [eax+24h]
 	mov      dword ptr [eax+02Ch],0BF800000h	; _33 = -1.0

	fld 	dword ptr [zf]
	fmul	dword ptr [zn]
	fld 	dword ptr [zn]
	fsub 	dword ptr [zf]
	fdivp 	st(1),st(0)
	fstp	dword ptr [eax+38h]
	fldz
	fst	dword ptr [eax+30h]
	fstp	dword ptr [eax+34h]
	fstp	dword ptr [eax+3ch]

        return pOut                             
_D3DXMatrixPerspectiveFovRH ENDP



_D3DXMatrixRotationX PROC mOut:LPVOID,angle:REAL4

	ZeroMemory mOut,sizeof D3DMATRIX
	
	push edi
	mov edi,mOut
	
	fld1
	fst dword ptr [edi]
	fstp dword ptr [edi+60]
	
	fld dword ptr [angle]
	fsincos
	fst dword ptr [edi+20]
	fstp dword ptr [edi+40]
	
	fst dword ptr [edi+24]
	fchs
	fstp dword ptr [edi+36]
	
	pop edi
	return mOut
_D3DXMatrixRotationX ENDP



_D3DXMatrixRotationY PROC mOut:LPVOID,angle:REAL4

	ZeroMemory mOut,sizeof D3DMATRIX
	
	push edi
	mov edi,mOut
	
	fld1
	fst dword ptr [edi+20]
	fstp dword ptr [edi+60]
	
	fld dword ptr [angle]
	fsincos
	fst dword ptr [edi]
	fstp dword ptr [edi+40]
	
	fst dword ptr [edi+32]
	fchs
	fstp dword ptr [edi+8]
	
	pop edi
	return mOut
_D3DXMatrixRotationY ENDP

	

_D3DXMatrixRotationZ PROC mOut:LPVOID,angle:REAL4

	ZeroMemory mOut,sizeof D3DMATRIX
	
	push edi
	mov edi,mOut
	
	fld1
	fst dword ptr [edi+40]
	fstp dword ptr [edi+60]
	
	fld dword ptr [angle]
	fsincos
	fst dword ptr [edi]
	fstp dword ptr [edi+20]
	
	fst dword ptr [edi+4]
	fchs
	fstp dword ptr [edi+16]
	
	pop edi
	return mOut
_D3DXMatrixRotationZ ENDP



_D3DXMatrixTranslation PROC mOut:LPVOID,x:REAL4,y:REAL4,z:REAL4
	pusha
	
	ZeroMemory mOut,sizeof D3DMATRIX
	
	mov 	ebx,mOut
	fld1 
	fst 	dword ptr [ebx]
	fst 	dword ptr [ebx+20]
	fst 	dword ptr [ebx+40]
	fstp 	dword ptr [ebx+60]
	mov 	eax,x
	mov 	ecx,y
	mov 	edx,z
	mov 	[ebx+48],eax
	mov 	[ebx+52],ecx
	mov 	[ebx+56],edx
	
	popa
	
	return mOut
_D3DXMatrixTranslation ENDP




_D3DXMatrixMultiply PROC pOut:DWORD,pM1:DWORD,pM2:DWORD
	push ecx
	push edx
	
  	mov eax,OFFSET tempm_
  	mov ecx,pM2
  	mov edx,pM1
  
  	fld   dword ptr [edx]
  	fmul  dword ptr [ecx]
  	fld   dword ptr [edx + 04h]
  	fmul  dword ptr [ecx + 10h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 08h]
  	fmul  dword ptr [ecx + 20h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 0ch]
  	fmul  dword ptr [ecx + 30h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax]

  	fld   dword ptr [edx]
  	fmul  dword ptr [ecx + 04h]
  	fld   dword ptr [edx + 04h]
  	fmul  dword ptr [ecx + 14h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 08h]
  	fmul  dword ptr [ecx + 24h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 0ch]
  	fmul  dword ptr [ecx + 34h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 04h]
	
  	fld   dword ptr [edx]
  	fmul  dword ptr [ecx + 08h]
  	fld   dword ptr [edx + 04h]
  	fmul  dword ptr [ecx + 18h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 08h]
  	fmul  dword ptr [ecx + 28h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 0ch]
  	fmul  dword ptr [ecx + 38h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 08h]

  	fld   dword ptr [edx]
  	fmul  dword ptr [ecx + 0ch]
  	fld   dword ptr [edx + 04h]
  	fmul  dword ptr [ecx + 1ch]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 08h]
  	fmul  dword ptr [ecx + 2ch]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 0ch]
  	fmul  dword ptr [ecx + 3ch]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 0ch]

  	fld   dword ptr [edx + 10h]
  	fmul  dword ptr [ecx]
  	fld   dword ptr [edx + 14h]
  	fmul  dword ptr [ecx + 10h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 18h]
  	fmul  dword ptr [ecx + 20h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 1ch]
  	fmul  dword ptr [ecx + 30h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 10h]

  	fld   dword ptr [edx + 10h]
  	fmul  dword ptr [ecx + 04h]
  	fld   dword ptr [edx + 14h]
  	fmul  dword ptr [ecx + 14h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 18h]
  	fmul  dword ptr [ecx + 24h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 1ch]
  	fmul  dword ptr [ecx + 34h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 14h]

  	fld   dword ptr [edx + 10h]
  	fmul  dword ptr [ecx + 08h]
  	fld   dword ptr [edx + 14h]
  	fmul  dword ptr [ecx + 18h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 18h]
  	fmul  dword ptr [ecx + 28h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 1ch]
  	fmul  dword ptr [ecx + 38h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 18h]

  	fld   dword ptr [edx + 10h]
  	fmul  dword ptr [ecx + 0ch]
  	fld   dword ptr [edx + 14h]
  	fmul  dword ptr [ecx + 1ch]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 18h]
  	fmul  dword ptr [ecx + 2ch]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 1ch]
  	fmul  dword ptr [ecx + 3ch]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 1ch]

  	fld   dword ptr [edx + 20h]
  	fmul  dword ptr [ecx]
  	fld   dword ptr [edx + 24h]
  	fmul  dword ptr [ecx + 10h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 28h]
  	fmul  dword ptr [ecx + 20h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 2ch]
  	fmul  dword ptr [ecx + 30h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 20h]

  	fld   dword ptr [edx + 20h]
  	fmul  dword ptr [ecx + 04h]
  	fld   dword ptr [edx + 24h]
  	fmul  dword ptr [ecx + 14h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 28h]
  	fmul  dword ptr [ecx + 24h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 2ch]
  	fmul  dword ptr [ecx + 34h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 24h]

  	fld   dword ptr [edx + 20h]
  	fmul  dword ptr [ecx + 08h]
  	fld   dword ptr [edx + 24h]
  	fmul  dword ptr [ecx + 18h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 28h]
  	fmul  dword ptr [ecx + 28h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 2ch]
  	fmul  dword ptr [ecx + 38h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 28h]

  	fld   dword ptr [edx + 20h]
  	fmul  dword ptr [ecx + 0ch]
  	fld   dword ptr [edx + 24h]
  	fmul  dword ptr [ecx + 1ch]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 28h]
  	fmul  dword ptr [ecx + 2ch]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 2ch]
  	fmul  dword ptr [ecx + 3ch]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 2ch]

  	fld   dword ptr [edx + 30h]
  	fmul  dword ptr [ecx]
  	fld   dword ptr [edx + 34h]
  	fmul  dword ptr [ecx + 10h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 38h]
  	fmul  dword ptr [ecx + 20h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 3ch]
  	fmul  dword ptr [ecx + 30h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 30h]

  	fld   dword ptr [edx + 30h]
  	fmul  dword ptr [ecx + 04h]
  	fld   dword ptr [edx + 34h]
  	fmul  dword ptr [ecx + 14h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 38h]
  	fmul  dword ptr [ecx + 24h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 3ch]
  	fmul  dword ptr [ecx + 34h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 34h]

  	fld   dword ptr [edx + 30h]
  	fmul  dword ptr [ecx + 08h]
  	fld   dword ptr [edx + 34h]
  	fmul  dword ptr [ecx + 18h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 38h]
  	fmul  dword ptr [ecx + 28h]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 3ch]
  	fmul  dword ptr [ecx + 38h]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 38h]

  	fld   dword ptr [edx + 30h]
  	fmul  dword ptr [ecx + 0ch]
  	fld   dword ptr [edx + 34h]
  	fmul  dword ptr [ecx + 1ch]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 38h]
  	fmul  dword ptr [ecx + 2ch]
  	faddp st(1),st(0)
  	fld   dword ptr [edx + 3ch]
  	fmul  dword ptr [ecx + 3ch]
  	faddp st(1),st(0)
  	fstp  dword ptr [eax + 3ch]                      

	push esi
	push edi
	mov esi,eax
	mov edi,pOut
	mov ecx,(sizeof D3DXMATRIX)/4
	rep movsd
	pop edi
	pop esi
	
	pop edx
	pop ecx
	
	ret              
_D3DXMatrixMultiply ENDP


END

	
	
	