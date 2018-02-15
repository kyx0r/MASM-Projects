IFNDEF _D3DX8MATH_INL_
_D3DX8MATH_INL_	equ		1

.CODE

;//--------------------------
;// 4D Matrix
;//--------------------------

;D3DXINLINE D3DXMATRIX* D3DXMatrixIdentity
;    ( D3DXMATRIX *pOut )
;{
;#ifdef D3DX_DEBUG
;    if(!pOut)
;        return NULL;
;#endif

;    pOut->m[0][1] = pOut->m[0][2] = pOut->m[0][3] =
;    pOut->m[1][0] = pOut->m[1][2] = pOut->m[1][3] =
;    pOut->m[2][0] = pOut->m[2][1] = pOut->m[2][3] =
;    pOut->m[3][0] = pOut->m[3][1] = pOut->m[3][2] = 0.0f;

;    pOut->m[0][0] = pOut->m[1][1] = pOut->m[2][2] = pOut->m[3][3] = 1.0f;
;    return pOut;
;}
D3DXMatrixIdentity PROC pMatrix:LPD3DMATRIX
    mov ecx,4
    mov edx,pMatrix
RowLoop:
    mov ch,4
ColLoop:
    sub eax,eax
    .if cl==ch
        mov eax,1
    .endif
    mov [edx],eax
    add edx,sizeof(FLOAT)
    dec ch
jnz ColLoop
loop RowLoop

    mov eax, pMatrix
    ret
D3DXMatrixIdentity ENDP


;D3DXINLINE D3DXVECTOR3* D3DXVec3Cross
;    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
;{
;    D3DXVECTOR3 v;

;#ifdef D3DX_DEBUG
;    if(!pOut || !pV1 || !pV2)
;        return NULL;
;#endif

;    v.x = pV1->y * pV2->z - pV1->z * pV2->y;
;    v.y = pV1->z * pV2->x - pV1->x * pV2->z;
;    v.z = pV1->x * pV2->y - pV1->y * pV2->x;

;    *pOut = v;
;    return pOut;
;}

; res=(A.y*B.z-B.y*A.z, A.z*B.x-B.z*A.x, A.x*B.y-B.x*A.y)
D3DXVec3Cross PROC res:DWORD,vec1:DWORD,vec2:DWORD
 mov eax,vec1
 mov edx,vec2
 fld [eax].D3DVECTOR.x
 fld st(0)
 fmul [edx].D3DVECTOR.z
 fxch
 fmul [edx].D3DVECTOR.y
 ;****
 fld [eax].D3DVECTOR.y
 fld st(0)
 fmul [edx].D3DVECTOR.z
 fxch
 fmul [edx].D3DVECTOR.x
 ;****
 fld [eax].D3DVECTOR.z
 fld st(0)
 fmul [edx].D3DVECTOR.y
 fxch
 fmul [edx].D3DVECTOR.x
 ; 0       1       2       3       4       5
 ; Az*Bx . Az*By . Ay*Bx . Ay*Bz . Ax*By . Ax*Bz
 fxch st(5)
 fsubp st(5),st
 fsubp st(2),st
 fsubp st(2),st
 mov eax,res
 fstp [eax].D3DVECTOR.x
 fstp [eax].D3DVECTOR.z
 fstp [eax].D3DVECTOR.y
 ret
D3DXVec3Cross ENDP

;D3DXINLINE FLOAT D3DXVec3Dot
;    ( CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
;{
;#ifdef D3DX_DEBUG
;    if(!pV1 || !pV2)
;        return 0.0f;
;#endif

;    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z;
;}

; ST=A.x*B.x+A.y*B.y+A.z*B.z
D3DXVec3Dot PROC vec1:DWORD,vec2:DWORD
 mov eax,vec1
 mov edx,vec2
 fld [eax].D3DVECTOR.x
 fmul [edx].D3DVECTOR.x
 fld [eax].D3DVECTOR.y
 fmul [edx].D3DVECTOR.y
 faddp st(1),st
 fld [eax].D3DVECTOR.z
 fmul [edx].D3DVECTOR.z
 faddp st(1),st
 ret
D3DXVec3Dot ENDP



ENDIF