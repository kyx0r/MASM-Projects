.486
.model flat,stdcall
option casemap:none

include .\macros.inc
include .\d3d8.inc
include .\vector.inc



.data

.data?
; var_24          dd ?
; var_20          dd ?
; var_1C          dd ?
; var_18          dd ?
; var_14          dd ?
; var_10          dd ?
; var_C           dd ?
; var_8           dd ?
; var_4           dd ?
; s              db 4 dup(?)
; r              db 4 dup(?)
; arg_0           dd ?
; arg_4           dd ?
; arg_8           dd ?
; arg_C           dd ?
.code	

; D3DXVec3Normalize proc near
; jmp     off_49667C
; D3DXVec3Normalize endp


D3DXMatrixLookAtRH proc near
	var_24= dword ptr -24h
	var_20= dword ptr -20h
	var_1C= dword ptr -1Ch
	var_18= dword ptr -18h
	var_14= dword ptr -14h
	var_10= dword ptr -10h
	var_C= dword ptr -0Ch
	var_8= dword ptr -8
	var_4= dword ptr -4
	arg_0= dword ptr  8
	arg_4= dword ptr  0Ch
	arg_8= dword ptr  10h
	arg_C= dword ptr  14h
	
	push    ebp
	mov     ebp, esp
	sub     esp, 24h
	push    ebx
	mov     ebx, [ebp+arg_0]
	test    ebx, ebx
	push    esi
	jz      loc_4230F9
		
	mov     eax, [ebp+arg_4]
	test    eax, eax
	jz      loc_4230F9
	
	mov     ecx, [ebp+arg_8]
	test    ecx, ecx
	jz      loc_4230F9
	
	mov     esi, [ebp+arg_C]
	test    esi, esi
	jz      loc_4230F9
	
	fld     dword ptr [eax]
	push    edi
	fsub    dword ptr [ecx]
	fstp    [ebp+var_C]
	fld     dword ptr [eax+4]
	fsub    dword ptr [ecx+4]
	fstp    [ebp+var_8]
	fld     dword ptr [eax+8]
	lea     eax, [ebp+var_C]
	fsub    dword ptr [ecx+8]
	push    eax
	lea     eax, [ebp+var_C]
	push    eax
	fstp    [ebp+var_4]
	;invoke  D3DXVec3Normalize
	fld     [ebp+var_4]
	lea     edi, [ebp+var_18]
	fmul    dword ptr [esi+4]
	lea     eax, [ebp+var_18]
	fld     [ebp+var_8]
	push    eax
	fmul    dword ptr [esi+8]
	lea     eax, [ebp+var_18]
	push    eax
	fsubp   st(1), st
	fstp    [ebp+var_24]
	fld     [ebp+var_C]
	fmul    dword ptr [esi+8]
	fld     [ebp+var_4]
	fmul    dword ptr [esi]
	fsubp   st(1), st
	fstp    [ebp+var_20]
	fld     [ebp+var_8]
	fmul    dword ptr [esi]
	fld     [ebp+var_C]
	fmul    dword ptr [esi+4]
	lea     esi, [ebp+var_24]
	fsubp   st(1), st
	fstp    [ebp+var_1C]
	movsd
	movsd
	movsd
	;invoke  D3DXVec3Normalize
	mov     eax, [ebp+var_18]
	fld     [ebp+var_8]
	mov     [ebx], eax
	fmul    [ebp+var_10]
	mov     eax, [ebp+var_14]
	fld     [ebp+var_4]
	mov     [ebx+10h], eax
	fmul    [ebp+var_14]
	mov     eax, [ebp+var_10]
	mov     [ebx+20h], eax
	mov     eax, [ebp+arg_4]
	fsubp   st(1), st
	fld     [ebp+var_4]
	fmul    [ebp+var_18]
	fld     [ebp+var_C]
	fmul    [ebp+var_10]
	fsubp   st(1), st
	fld     [ebp+var_C]
	fmul    [ebp+var_14]
	fld     [ebp+var_8]
	fmul    [ebp+var_18]
	fsubp   st(1), st
	fld     [ebp+var_18]
	fmul    dword ptr [eax]
	fld     [ebp+var_14]
	fmul    dword ptr [eax+4]
	faddp   st(1), st
	fld     [ebp+var_10]
	fmul    dword ptr [eax+8]
	faddp   st(1), st
	fchs
	fstp    dword ptr [ebx+30h]
	fld     st(2)
	fstp    dword ptr [ebx+4]
	fld     st(1)
	fstp    dword ptr [ebx+14h]
	fst     dword ptr [ebx+24h]
	fld     st(2)
	fmul    dword ptr [eax]
	mov     ecx, [ebp+var_C]
	fld     st(2)
	pop     edi
	fmul    dword ptr [eax+4]
	faddp   st(1), st
	fld     st(1)
	fmul    dword ptr [eax+8]
	mov     [ebx+8], ecx
	mov     ecx, [ebp+var_8]
	mov     [ebx+18h], ecx
	faddp   st(1), st
	mov     ecx, [ebp+var_4]
	mov     [ebx+28h], ecx
	fchs
	fstp    dword ptr [ebx+34h]
	fstp    st
	fstp    st
	fstp    st
	fld     [ebp+var_C]
	fmul    dword ptr [eax]
	fld     [ebp+var_8]
	fmul    dword ptr [eax+4]
	faddp   st(1), st
	fld     [ebp+var_4]
	fmul    dword ptr [eax+8]
	mov     eax, ebx
	faddp   st(1), st
	fchs
	fstp    dword ptr [ebx+38h]
	fldz
	fstp    dword ptr [ebx+0Ch]
	fldz
	fstp    dword ptr [ebx+1Ch]
	fldz
	fstp    dword ptr [ebx+2Ch]
	fld1
	fstp    dword ptr [ebx+3Ch]
	jmp     short loc_4230FB
	
	loc_4230F9:
	xor eax, eax
	
	loc_4230FB:
	pop     esi
	pop     ebx
	leave
	retn    10h
	
D3DXMatrixLookAtRH endp
	
end