; Some vector functions to use instead of the ones in D3DX
; /Mic, 2003


.486
.model flat,stdcall
option casemap:none


.code


_D3DXVec3Add PROC pOut:DWORD,pV1:DWORD,pV2:DWORD
  	push ebx
 	push edx
 
 	mov eax,pV1
 	mov ebx,pV2
 	mov edx,pOut

	fld dword ptr [eax]
	fadd dword ptr [ebx]
	fstp dword ptr [edx]

	fld dword ptr [eax+4]
	fadd dword ptr [ebx+4]
	fstp dword ptr [edx+4]

	fld dword ptr [eax+8]
	fadd dword ptr [ebx+8]
	fstp dword ptr [edx+8]

	pop edx
	pop ebx
	mov eax,pOut
	ret
_D3DXVec3Add ENDP



_D3DXVec3Subtract PROC pOut:DWORD,pV1:DWORD,pV2:DWORD
  	push ebx
 	push edx
 
 	mov eax,pV1
 	mov ebx,pV2
 	mov edx,pOut

	fld dword ptr [eax]
	fsub dword ptr [ebx]
	fstp dword ptr [edx]

	fld dword ptr [eax+4]
	fsub dword ptr [ebx+4]
	fstp dword ptr [edx+4]

	fld dword ptr [eax+8]
	fsub dword ptr [ebx+8]
	fstp dword ptr [edx+8]

	pop edx
	pop ebx
	mov eax,pOut
	ret
_D3DXVec3Subtract ENDP



_D3DXVec3Cross PROC pOut:DWORD,pV1:DWORD,pV2:DWORD
  	push ebx
 	push edx
 
 	mov eax,pV1
 	mov ebx,pV2
 	mov edx,pOut
 	
 	fld dword ptr [eax+4]
 	fmul dword ptr [ebx+8]
 	fld dword ptr [eax+8]
 	fmul dword ptr [ebx+4]
 	fsubp st(1),st(0)
 	fstp dword ptr [edx]
 	
 	fld dword ptr [eax+8]
 	fmul dword ptr [ebx]
 	fld dword ptr [eax]
 	fmul dword ptr [ebx+8]
 	fsubp st(1),st(0)
 	fstp dword ptr [edx+4]
 
 	fld dword ptr [eax]
  	fmul dword ptr [ebx+4]
  	fld dword ptr [eax+4]
  	fmul dword ptr [ebx]
  	fsubp st(1),st(0)
  	fstp dword ptr [edx+8]
  	
 	pop edx
 	pop ebx
 	mov eax,pOut
 	ret
_D3DXVec3Cross ENDP
 
 
 
_D3DXVec3Dot PROC pV1:DWORD,pV2:DWORD
   	push ebx
   	
   	mov      eax,pV1       
     	mov      ebx,pV2       
     	fld      dword ptr [eax+8]           
    	fmul     dword ptr [ebx+8]           
      	fld      dword ptr [eax+4]           
     	fmul     dword ptr [ebx+4]           
      	faddp    st(1),st(0)                   
       	fld      dword ptr [eax]               
      	fmul     dword ptr [ebx]               
      	faddp    st(1),st(0)                   
 
 	pop ebx
	ret
_D3DXVec3Dot ENDP

 

_D3DXVec3Normalize PROC pOut:DWORD,pV:DWORD
	push ebx
	
	mov eax,pV
	mov ebx,pOut

	fld dword ptr [eax]
	fmul dword ptr [eax]
	fld dword ptr [eax+4]
	fmul dword ptr [eax+4]
	faddp st(1),st(0)
	fld dword ptr [eax+8]
	fmul dword ptr [eax+8]
	faddp st(1),st(0)
	fsqrt

	fld dword ptr [eax]
	fdiv st(0),st(1)
	fstp dword ptr [ebx]

	fld dword ptr [eax+4]
	fdiv st(0),st(1)
	fstp dword ptr [ebx+4]

	fld dword ptr [eax+8]
	fdiv st(0),st(1)
	fstp dword ptr [ebx+8]

	pop ebx	
	mov eax,pOut
	ret
_D3DXVec3Normalize ENDP


END
