ifndef __D3DX8MATH__

__D3DX8MATH__			equ	1


;ifndef	FLOAT
;  FLOAT	typedef Real4
;  FLOAT equ FLOAT
;endif


  D3DXCreateMatrixStack			Proto	:DWORD, :DWord

  D3DXVec2Normalize			Proto	:Dword, :Dword
  D3DXVec2Hermite			Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :FLOAT
  D3DXVec2CatmullRom			Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :FLOAT
  D3DXVec2BaryCentric			Proto	:Dword, :Dword, :Dword, :Dword, :FLOAT, :FLOAT
  D3DXVec2Transform			Proto	:Dword, :Dword, :Dword
  D3DXVec2TransformCoord		Proto	:Dword, :Dword, :Dword
  D3DXVec2TransformNormal		Proto	:Dword, :Dword, :Dword

  D3DXVec3Normalize			Proto	:Dword, :Dword
  D3DXVec3Hermite			Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :FLOAT
  D3DXVec3CatmullRom			Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :FLOAT
  D3DXVec3BaryCentric			Proto	:Dword, :Dword, :Dword, :Dword, :FLOAT, :FLOAT
  D3DXVec3Transform			Proto	:Dword, :Dword, :Dword
  D3DXVec3TransformCoord		Proto	:Dword, :Dword, :Dword
  D3DXVec3TransformNormal		Proto	:Dword, :Dword, :Dword
  D3DXVec3Project			Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXVec3Unproject			Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword

  D3DXVec4Normalize			Proto	:Dword, :Dword
  D3DXVec4Hermite			Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :FLOAT
  D3DXVec4CatmullRom			Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :FLOAT
  D3DXVec4BaryCentric			Proto	:Dword, :Dword, :Dword, :Dword, :FLOAT, :FLOAT
  D3DXVec4Transform			Proto	:Dword, :Dword, :Dword
  D3DXVec4Cross				Proto	:Dword, :Dword, :Dword, :Dword

  D3DXMatrixfDeterminant		Proto	:Dword
    D3DXMatrixMultiply          PROTO :DWORD, :DWORD, :DWORD
  D3DXMatrixTranspose			Proto	:Dword, :Dword
  D3DXMatrixInverse			Proto	:Dword, :FLOAT, :Dword
  D3DXMatrixScaling			Proto	:Dword, :FLOAT, :FLOAT, :FLOAT
D3DXMatrixTranslation PROTO :DWORD, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixRotationX			Proto	:Dword, :FLOAT
D3DXMatrixRotationY PROTO :DWORD, :FLOAT
  D3DXMatrixRotationZ			Proto	:Dword, :FLOAT
  D3DXMatrixRotationAxis		Proto	:Dword, :Dword, :FLOAT
  D3DXMatrixRotationQuaternion		Proto	:Dword, :Dword
  D3DXMatrixRotationYawPitchRoll 	Proto	:Dword, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixTransformation		Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXMatrixAffineTransformation 	Proto	:Dword, :FLOAT, :Dword, :Dword, :Dword
  D3DXMatrixLookAtRH			Proto	:Dword, :Dword, :Dword, :Dword
  D3DXMatrixLookAtLH			Proto	:Dword, :Dword, :Dword, :Dword
  D3DXMatrixPerspectiveRH		Proto	:Dword, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixPerspectiveLH		Proto	:Dword, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixPerspectiveFovRH		Proto	:Dword, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixPerspectiveFovLH		Proto	:Dword, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixPerspectiveOffCenterRH	Proto	:Dword, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixPerspectiveOffcenterLH	Proto	:Dword, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixOrthoRH			Proto	:Dword, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixOrthoLH			Proto	:Dword, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixOrthoOffCenterRH		Proto	:Dword, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixOrthoOffcenterLH		Proto	:Dword, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixShadow			Proto	:Dword, :Dword, :Dword
  D3DXMatrixReflect			Proto	:Dword, :Dword, :Dword

  D3DXColorAdjustSaturation		Proto	:Dword, :Dword, :FLOAT
  D3DXColorAdjustContrast		Proto	:Dword, :Dword, :FLOAT

  D3DXPlaneNormalize			Proto	:Dword, :Dword
  D3DXPlaneIntersectLine		Proto	:Dword, :Dword, :Dword, :Dword
  D3DXPlaneFromPointNormal		Proto	:Dword, :Dword, :Dword
  D3DXPlaneFromPoints			Proto	:Dword, :Dword, :Dword, :Dword
  D3DXPlaneFromTransform		Proto	:Dword, :Dword, :Dword
  D3DXQuaternionToAxisAngle		Proto	:Dword, :Dword, :FLOAT
  D3DXQuaternionRotationMatrix		Proto	:Dword, :Dword
  D3DXQuaternionRotationAxis		Proto	:Dword, :Dword, :FLOAT
  D3DXQuaternionRotationYawPitchRoll	Proto	:Dword, :FLOAT, :FLOAT, :FLOAT
  D3DXQuaternionMultiply		Proto	:Dword, :Dword, :Dword
  D3DXQuaternionNormalize		Proto	:Dword, :Dword
  D3DXQuaternionInverse			Proto	:Dword, :Dword
  D3DXQuaternionLn			Proto	:Dword, :Dword
  D3DXQuaternionExp			Proto	:Dword, :Dword
  D3DXQuaternionSlerp			Proto	:Dword, :Dword, :Dword, :FLOAT
  D3DXQuaternionSquad			Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :FLOAT
  D3DXQuaternionBaryCentric		Proto	:Dword, :Dword, :Dword, :Dword, :FLOAT, :FLOAT

DECLARE_INTERFACE <ID3DXMatrixStack_>
;   /*** IUnknown methods ***/
    INHERIT_IUnknown
;   /*** ID3DXMatrixStack methods ***/

    STDMETHOD	<Pop>
    STDMETHOD	<Push>
    STDMETHOD	<LoadIdentity>
    STDMETHOD	<LoadMatrix>, :DWord
    STDMETHOD	<MultMatrix>, :DWord
    STDMETHOD	<MultMatrixLocal>, :DWord
    STDMETHOD	<RotateAxis>, :DWord, :FLOAT
    STDMETHOD	<RotateAxisLocal>, :DWord, :FLOAT
    STDMETHOD	<RotateYawPitchRoll>, :FLOAT, :FLOAT, :FLOAT
    STDMETHOD	<RotateYawPitchRollLocal>, :FLOAT, :FLOAT, :FLOAT
    STDMETHOD	<Scale>, :FLOAT, :FLOAT, :FLOAT
    STDMETHOD	<ScaleLocal>, :FLOAT, :FLOAT, :FLOAT
    STDMETHOD	<Translate>, :FLOAT, :FLOAT, :FLOAT
    STDMETHOD	<TranslateLocal>, :FLOAT, :FLOAT, :FLOAT
    STDMETHOD	<GetTop>

LPD3DXMATRIXSTACK	typedef	ptr

;include <math.h>

D3DX_PI             EQU         3.141592654f
D3DX_1BYPI		EQU	0.318309886f

; *** not standard-values, but added by me ***

D3DX_0			EQU	0.0f
D3DX_1			EQU	1.0f
D3DX_PIHALF 		EQU	1.570796327f
D3DX_1BYPIHALF 		EQU	0.636619772f
D3DX_PIQUARTER 		EQU	0.785398164f
D3DX_1BYPIQUARTER	      EQU	1.273239545f
D3DX_SQRT2    		EQU	1.414213562f
D3DX_1BYSQRT2  		EQU	0.707106781f
D3DX_SQRTPI    		EQU	1.772453851f
D3DX_1BYSQRTPI 		EQU	1.564189583f


;D3DXToRadian	Macro	degree
;		Endm	(degree * (D3DX_PI / 180.0f))

;D3DXToDegree	macro   radian
;		endm	(radian * (180.0f / D3DX_PI))



_D3DXVECTOR2		struct

    x			FLOAT		?
    y			FLOAT		?

_D3DXVECTOR2		ends

D3DXVECTOR2		typedef		_D3DXVECTOR2
LPD3DXVECTOR2		typedef	ptr	D3DXVECTOR2


_D3DXVECTOR3		struct

    x			FLOAT		?
    y			FLOAT		?
    z			FLOAT		?

_D3DXVECTOR3		ends

D3DXVECTOR3		typedef		_D3DXVECTOR3
LPD3DXVECTOR3		typedef	ptr	D3DXVECTOR3


_D3DXVECTOR4		struct

    x			FLOAT		?
    y			FLOAT		?
    z			FLOAT		?
    w			FLOAT		?

_D3DXVECTOR4		ends

D3DXVECTOR4		typedef		_D3DXVECTOR4
LPD3DXVECTOR4		typedef	ptr	D3DXVECTOR4

D3DXQUATERNION		typedef		D3DXVECTOR4
LPD3DXQUATERNION	typedef	ptr	D3DXVECTOR4


_D3DXMATRIX		struct

    _11			FLOAT		?
    _12			FLOAT		?
    _13			FLOAT		?
    _14			FLOAT		?
    _21			FLOAT		?
    _22			FLOAT		?
    _23			FLOAT		?
    _24			FLOAT		?
    _31			FLOAT		?
    _32			FLOAT		?
    _33			FLOAT		?
    _34			FLOAT		?
    _41			FLOAT		?
    _42			FLOAT		?
    _43			FLOAT		?
    _44			FLOAT		?

_D3DXMATRIX		ends

D3DXMATRIX		typedef		_D3DXMATRIX
LPD3DXMATRIX		typedef	ptr	D3DXMATRIX


_D3DXPLANE		struct

    x			FLOAT		?
    y			FLOAT		?
    z			FLOAT		?
    w			FLOAT		?

_D3DXPLANE		ends

D3DXPLANE		typedef		_D3DXPLANE
LPD3DXPLANE		typedef	ptr	D3DXPLANE


_D3DXCOLOR		struct

    r			FLOAT		?
    g			FLOAT		?
    b			FLOAT		?
    a			FLOAT		?

_D3DXCOLOR		ends

D3DXCOLOR		typedef		_D3DXCOLOR
LPD3DXCOLOR		typedef	ptr	D3DXCOLOR

;
;COMMENT §(
;
;FLOAT D3DXVec2Length
;    ( CONST D3DXVECTOR2 *pV );
D3DXVec2Length PROTO :DWORD
;
;FLOAT D3DXVec2LengthSq
;    ( CONST D3DXVECTOR2 *pV );
D3DXVec2LengthSq PROTO :DWORD
;
;FLOAT D3DXVec2Dot
;    ( CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );
;
;// Z component of ((x1,y1,0) cross (x2,y2,0))
;FLOAT D3DXVec2CCW
;    ( CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );
;
;D3DXVECTOR2* D3DXVec2Add
;    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );
;
;D3DXVECTOR2* D3DXVec2Subtract
;    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );
;
;// Minimize each component.  x = min(x1, x2), y = min(y1, y2)
;D3DXVECTOR2* D3DXVec2Minimize
;    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );
;
;// Maximize each component.  x = max(x1, x2), y = max(y1, y2)
;D3DXVECTOR2* D3DXVec2Maximize
;    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );
;
;D3DXVECTOR2* D3DXVec2Scale
;    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV, FLOAT s );
;
;// Linear interpolation. V1 + s(V2-V1)
;D3DXVECTOR2* D3DXVec2Lerp
;    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2,
;      FLOAT s );
;
;FLOAT D3DXVec3Length
;    ( CONST D3DXVECTOR3 *pV );
;
;FLOAT D3DXVec3LengthSq
;    ( CONST D3DXVECTOR3 *pV );
;
;FLOAT D3DXVec3Dot
;    ( CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );
D3DXVec3Dot PROTO :DWORD, :DWORD
;
;D3DXVECTOR3* D3DXVec3Cross
;    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );
D3DXVec3Cross PROTO :DWORD, :DWORD, :DWORD
;
;D3DXVECTOR3* D3DXVec3Add
;    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );
;
;D3DXVECTOR3* D3DXVec3Subtract
;    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );
;
;// Minimize each component.  x = min(x1, x2), y = min(y1, y2), ...
;D3DXVECTOR3* D3DXVec3Minimize
;    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );
;
;// Maximize each component.  x = max(x1, x2), y = max(y1, y2), ...
;D3DXVECTOR3* D3DXVec3Maximize
;    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );
;
;D3DXVECTOR3* D3DXVec3Scale
;    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, FLOAT s);
;
;// Linear interpolation. V1 + s(V2-V1)
;D3DXVECTOR3* D3DXVec3Lerp
;    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2,
;      FLOAT s );
;
;FLOAT D3DXVec4Length
;    ( CONST D3DXVECTOR4 *pV );
;
;FLOAT D3DXVec4LengthSq
;    ( CONST D3DXVECTOR4 *pV );
;
;FLOAT D3DXVec4Dot
;    ( CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2 );
;
;D3DXVECTOR4* D3DXVec4Add
;    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);
;
;D3DXVECTOR4* D3DXVec4Subtract
;    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);
;
;// Minimize each component.  x = min(x1, x2), y = min(y1, y2), ...
;D3DXVECTOR4* D3DXVec4Minimize
;    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);
;
;// Maximize each component.  x = max(x1, x2), y = max(y1, y2), ...
;D3DXVECTOR4* D3DXVec4Maximize
;    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);
;
;D3DXVECTOR4* D3DXVec4Scale
;    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV, FLOAT s);
;
;// Linear interpolation. V1 + s(V2-V1)
;D3DXVECTOR4* D3DXVec4Lerp
;    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2,
;      FLOAT s );
;
;D3DXMATRIX* D3DXMatrixIdentity
;    ( D3DXMATRIX *pOut );
D3DXMatrixIdentity PROTO :LPD3DMATRIX
;
;BOOL D3DXMatrixIsIdentity
;    ( CONST D3DXMATRIX *pM );
;
;
;FLOAT D3DXQuaternionLength
;    ( CONST D3DXQUATERNION *pQ );
;
;// Length squared, or "norm"
;FLOAT D3DXQuaternionLengthSq
;    ( CONST D3DXQUATERNION *pQ );
;
;FLOAT D3DXQuaternionDot
;    ( CONST D3DXQUATERNION *pQ1, CONST D3DXQUATERNION *pQ2 );
;
;// (0, 0, 0, 1)
;D3DXQUATERNION* D3DXQuaternionIdentity
;    ( D3DXQUATERNION *pOut );
;
;BOOL D3DXQuaternionIsIdentity
;    ( CONST D3DXQUATERNION *pQ );
;
;// (-x, -y, -z, w)
;D3DXQUATERNION* D3DXQuaternionConjugate
;    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ );
;
;
;// ax + by + cz + dw
;FLOAT D3DXPlaneDot
;    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR4 *pV);
;
;// ax + by + cz + d
;FLOAT D3DXPlaneDotCoord
;    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV);
;
;// ax + by + cz
;FLOAT D3DXPlaneDotNormal
;    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV);
;
;// (1-r, 1-g, 1-b, a)
;D3DXCOLOR* D3DXColorNegative
;    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC);
;
;D3DXCOLOR* D3DXColorAdd
;    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2);
;
;D3DXCOLOR* D3DXColorSubtract
;    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2);
;
;D3DXCOLOR* D3DXColorScale
;    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC, FLOAT s);
;
;// (r1*r2, g1*g2, b1*b2, a1*a2)
;D3DXCOLOR* D3DXColorModulate
;    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2);
;
;// Linear interpolation of r,g,b, and a. C1 + s(C2-C1)
;D3DXCOLOR* D3DXColorLerp
;    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2, FLOAT s);
;
;	)§
;

include	d3dx8math.inl

endif
