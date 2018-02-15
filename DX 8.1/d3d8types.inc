;/*==========================================================================;
; *
; *  Copyright (C) 1995-2000 Microsoft Corporation.  All Rights Reserved.
; *
; *  File:       d3d8types.h
; *  Content:    Direct3D capabilities include file
; *
; ***************************************************************************/

;
;
;   NOTE: The following items have been changed from the original header
;
;   The 'Width' variable in the 'D3DVIEWPORT8' structure:
;_D3DVIEWPORT8   struct    DWORD
;    _Width       DWORD       ?   ;<--------------------------can't use 'Width' in Masm.
;
;   The 'Type' variable in the D3DLIGHT8 structure:
;_D3DLIGHT8 struct  DWORD
;    _Type                D3DLIGHTTYPE        ?   ;   /* Type of light source */<---can't use 'Type' in Masm.

IFNDEF _D3D8TYPES_INC_
_D3D8TYPES_INC_=1

IFNDEF DIRECT3D_VERSION
DIRECT3D_VERSION 	EQU	0800h
ENDIF   ;DIRECT3D_VERSION

;// include this file content only if compiling for DX8 interfaces
;#if(DIRECT3D_VERSION >= 0x0800)

;#include <float.h>

;#pragma warning(disable:4201) // anonymous unions warning
;#pragma pack(4)

;###########################################
; * D3DVALUE is the fundamental Direct3D fractional data type
;D3DVALUE typedef FLOAT
;LPD3DVALUE typedef PTR D3DVALUE

;D3DFIXED typedef LONG

;D3DCOLOR typedef DWORD
;LPD3DCOLOR typedef PTR D3DCOLOR
;###########################################

;// D3DCOLOR is equivalent to D3DFMT_A8R8G8B8
;IFNDEF D3DCOLOR_DEFINED
;    D3DCOLOR typedef DWORD
;    D3DCOLOR_DEFINED=1
;ENDIF

;// maps unsigned 8 bits/channel to D3DCOLOR
;#define D3DCOLOR_ARGB(a,r,g,b) \
;    ((D3DCOLOR)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
;D3DCOLOR_ARGB MACRO a, r, g, b	;; ((D3DCOLOR)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
;    D3DCOLOR (((a AND 0FFh) SHL 24) OR ((r AND 0FFh) SHL 16) OR ((g AND 0FFh) SHL 8) OR (b AND 0FFh))
;ENDM

;#define D3DCOLOR_RGBA(r,g,b,a) D3DCOLOR_ARGB(a,r,g,b)
;D3DCOLOR_RGBA MACRO r, g, b, a;	;; D3DCOLOR_ARGB(a,r,g,b)
;    D3DCOLOR_ARGB a,r,g,b
;ENDM

;#define D3DCOLOR_XRGB(r,g,b)   D3DCOLOR_ARGB(0xff,r,g,b)
;D3DCOLOR_RGBA MACRO r, g, b, a	;; D3DCOLOR_ARGB(0xff,r,g,b)
;    D3DCOLOR_ARGB 0FFh,r,g,b
;ENDM

;// maps floating point channels (0.f to 1.f range) to D3DCOLOR
;#define D3DCOLOR_COLORVALUE(r,g,b,a) \
;    D3DCOLOR_RGBA((DWORD)((r)*255.f),(DWORD)((g)*255.f),(DWORD)((b)*255.f),(DWORD)((a)*255.f))
;D3DCOLOR_COLORVALUE MACRO r, g, b, a    ;;D3DCOLOR_RGBA((DWORD)((r)*255.f),(DWORD)((g)*255.f),(DWORD)((b)*255.f),(DWORD)((a)*255.f))
;    D3DCOLOR_RGBA (r*255.0f),(g*255.0f),(b*255.0f),(a*255.0f)
;ENDM

;// D3DCOLOR is equivalent to D3DFMT_A8R8G8B8
D3DCOLOR TYPEDEF DWORD

;// maps unsigned 8 bits/channel to D3DCOLOR
D3DCOLOR_ARGB MACRO a, r, g, b
	LOCAL DefineAs
	IF a GT 0ffh
		.ERR <D3DCOLOR component 'a'(=a) out of limits(over 0ffh)>
	ENDIF
	IF r GT 0ffh
		.ERR <D3DCOLOR component 'r'(=r) out of limits(over 0ffh)>
	ENDIF
	IF g GT 0ffh
		.ERR <D3DCOLOR component 'g'(=g) out of limits(over 0ffh)>
	ENDIF
	IF b GT 0ffh
		.ERR <D3DCOLOR component 'b'(=b) out of limits(over 0ffh)>
	ENDIF

	DefineAs	TEXTEQU %((((a) AND 0ffh) SHL 24) OR (((r) AND 0ffh) SHL 16) OR (((g) AND 0ffh) SHL 8) OR ((b) AND 0ffh))
	EXITM DefineAs
ENDM D3DCOLOR_ARGB

D3DCOLOR_RGBA MACRO r, g, b, a
	LOCAL DefineAs
	DefineAs TEXTEQU %(D3DCOLOR_ARGB(a, r, g, b)
	EXITM DefineAs
ENDM D3DCOLOR_RGBA

D3DCOLOR_XRGB MACRO r, g, b
	LOCAL DefineAs
	DefineAs	TEXTEQU %(D3DCOLOR_ARGB(0ffh, r, g, b))
	EXITM DefineAs
ENDM D3DCOLOR_XRGB

;// maps floating point channels (0.f to 1.f range) to D3DCOLOR
D3DCOLOR_COLORVALUE MACRO r, g, b, a
	LOCAL DefineAs
	DefinaAs TEXTEQU %(D3DCOLOR_RGBA((DWORD)((r)*255.f), (DWORD)((g)*255.f), (DWORD)((b)*255.f), (DWORD)((a)*255.f)))
	EXITM DefineAs
ENDM D3DCOLOR_COLORVALUE


IFNDEF D3DVECTOR_DEFINED
    _D3DVECTOR struct   DWORD
        x   FLOAT   ?
        y   FLOAT   ?
        z   FLOAT   ?
    _D3DVECTOR  ENDS
    D3DVECTOR		TYPEDEF		_D3DVECTOR
    LPD3DVECTOR		TYPEDEF		PTR _D3DVECTOR
    D3DVECTOR_DEFINED=1
ENDIF

IFNDEF D3DCOLORVALUE_DEFINED
    _D3DCOLORVALUE struct   DWORD
        r   FLOAT   ?
        g   FLOAT   ?
        b   FLOAT   ?
        a   FLOAT   ?
    _D3DCOLORVALUE  ENDS
    D3DCOLORVALUE		TYPEDEF		_D3DCOLORVALUE
    D3DCOLORVALUE_DEFINED=1
ENDIF

IFNDEF D3DRECT_DEFINED
    _D3DRECT struct   DWORD
        x1      LONG    ?
        y1      LONG    ?
        x2      LONG    ?
        y2      LONG    ?
    _D3DRECT  ENDS
    D3DRECT             TYPEDEF		_D3DRECT
    D3DRECT_DEFINED=1
ENDIF

IFNDEF D3DMATRIX_DEFINED
    _D3DMATRIX struct   DWORD
    ;   union 
    ;   {
    ;       struct 
    ;       {
    ;           float        _11, _12, _13, _14;
    ;           float        _21, _22, _23, _24;
    ;           float        _31, _32, _33, _34;
    ;           float        _41, _42, _43, _44;
    ;       };
    ;       float m[4][4];
    ;   };
    ;    UNION
            _11		FLOAT		?
            _12		FLOAT		?
            _13		FLOAT		?
            _14		FLOAT		?
            _21		FLOAT		?
            _22		FLOAT		?
            _23		FLOAT		?
            _24		FLOAT		?
            _31		FLOAT		?
            _32		FLOAT		?
            _33		FLOAT		?
            _34		FLOAT		?
            _41		FLOAT		?
            _42		FLOAT		?
            _43		FLOAT		?
            _44		FLOAT		?

      ;      m FLOAT 4 dup ({?,?,?,?})
     ;   ENDS

    _D3DMATRIX  ENDS
    D3DMATRIX               TYPEDEF		_D3DMATRIX
    LPD3DMATRIX		TYPEDEF		PTR _D3DMATRIX
    D3DMATRIX_DEFINED=1
ENDIF

_D3DVIEWPORT8   struct    DWORD
    X           DWORD       ?   ;
    Y           DWORD       ?   ;  Viewport Top left
    _Width       DWORD       ?   ;<--------------------------can't use 'Width' in Masm.
    Height      DWORD       ?   ;      /* Viewport Dimensions */
    MinZ        FLOAT       ?   ;      /* Min/max of clip Volume */
    MaxZ        FLOAT       ?   ;
_D3DVIEWPORT8   ENDS
D3DVIEWPORT8                TYPEDEF		_D3DVIEWPORT8

;/*
; * Values for clip fields.
; */

;// Max number of user clipping planes, supported in D3D.
D3DMAXUSERCLIPPLANES    EQU 32

;// These bits could be ORed together to use with D3DRS_CLIPPLANEENABLE
;//
;#define D3DCLIPPLANE0 (1 << 0)
D3DCLIPPLANE0 MACRO 	;; (1 << 0)
    (1 SHL 0)
ENDM

;#define D3DCLIPPLANE1 (1 << 1)
D3DCLIPPLANE1 MACRO 	;; (1 << 1)
    (1 SHL 1)
ENDM
;#define D3DCLIPPLANE2 (1 << 2)
D3DCLIPPLANE2 MACRO 	;; (1 << 2)
    (1 SHL 2)
ENDM
;#define D3DCLIPPLANE3 (1 << 3)
D3DCLIPPLANE3 MACRO 	;; (1 << 3)
    (1 SHL 3)
ENDM
;#define D3DCLIPPLANE4 (1 << 4)
D3DCLIPPLANE4 MACRO 	;; (1 << 4)
    (1 SHL 4)
ENDM
;#define D3DCLIPPLANE5 (1 << 5)
D3DCLIPPLANE5 MACRO 	;; (1 << 5)
    (1 SHL 5)
ENDM

;// The following bits are used in the ClipUnion and ClipIntersection
;// members of the D3DCLIPSTATUS8
;//
D3DCS_LEFT          EQU		000000001h
D3DCS_RIGHT	        EQU		000000002h
D3DCS_TOP           EQU		000000004h
D3DCS_BOTTOM        EQU		000000008h
D3DCS_FRONT	        EQU		000000010h
D3DCS_BACK          EQU		000000020h
D3DCS_PLANE0        EQU		000000040h
D3DCS_PLANE1        EQU		000000080h
D3DCS_PLANE2        EQU		000000100h
D3DCS_PLANE3        EQU		000000200h
D3DCS_PLANE4        EQU		000000400h
D3DCS_PLANE5        EQU		000000800h

D3DCS_ALL           EQU         D3DCS_LEFT   OR \
                  D3DCS_RIGHT  OR \
                  D3DCS_TOP    OR \
                  D3DCS_BOTTOM OR \
                  D3DCS_FRONT  OR \
                  D3DCS_BACK   OR \
                  D3DCS_PLANE0 OR \
                  D3DCS_PLANE1 OR \
                  D3DCS_PLANE2 OR \
                  D3DCS_PLANE3 OR \
                  D3DCS_PLANE4 OR \
                  D3DCS_PLANE5

_D3DCLIPSTATUS8 struct  DWORD
    ClipUnion           DWORD       ?
    ClipIntersection    DWORD       ?
_D3DCLIPSTATUS8 ENDS
D3DCLIPSTATUS8                TYPEDEF		_D3DCLIPSTATUS8
    LPD3DCLIPSTATUS8		TYPEDEF		PTR _D3DCLIPSTATUS8
    
_D3DMATERIAL8 struct  DWORD
    Diffuse     D3DCOLORVALUE   <>;         /* Diffuse color RGBA */
    Ambient     D3DCOLORVALUE   <>;         /* Ambient color RGB */
    Specular    D3DCOLORVALUE   <>;         /* Specular 'shininess' */
    Emissive    D3DCOLORVALUE   <>;         /* Emissive color RGB */
    Power       FLOAT           ?;          /* Sharpness if specular highlight */
_D3DMATERIAL8 ENDS
D3DMATERIAL8                TYPEDEF		_D3DMATERIAL8

	D3DLIGHT_POINT             EQU       1
	D3DLIGHT_SPOT              EQU       2
	D3DLIGHT_DIRECTIONAL       EQU       3
	D3DLIGHT_FORCE_DWORD       EQU       07fffffffh      ; /* force 32-bit size enum */

D3DLIGHTTYPE                TYPEDEF			DWORD

_D3DLIGHT8 struct  DWORD
    _Type                D3DLIGHTTYPE        ?   ;   /* Type of light source */<---can't use 'Type' in Masm.
    Diffuse             D3DCOLORVALUE       <>  ;   /* Diffuse color of light */
    Specular            D3DCOLORVALUE       <>  ;   /* Specular color of light */
    Ambient             D3DCOLORVALUE       <>  ;   /* Ambient color of light */
    Position            D3DVECTOR           <>  ;   /* Position in world space */
    Direction           D3DVECTOR           <>  ;   /* Direction in world space */
    Range               FLOAT               ?   ;   /* Cutoff range */
    Falloff             FLOAT               ?   ;   /* Falloff */
    Attenuation0        FLOAT               ?   ;   /* Constant attenuation */
    Attenuation1        FLOAT               ?   ;   /* Linear attenuation */
    Attenuation2        FLOAT               ?   ;   /* Quadratic attenuation */
    Theta               FLOAT               ?   ;   /* Inner angle of spotlight cone */
    Phi                 FLOAT               ?   ;   /* Outer angle of spotlight cone */
_D3DLIGHT8 ENDS
D3DLIGHT8                TYPEDEF		_D3DLIGHT8

;/*
; * Options for clearing
; */
D3DCLEAR_TARGET         EQU     000000001h      ;   0x00000001l  /* Clear target surface */
D3DCLEAR_ZBUFFER        EQU     000000002h      ;   0x00000002l  /* Clear target z buffer */
D3DCLEAR_STENCIL        EQU     000000004h      ;   0x00000004l  /* Clear stencil planes */

;/*
; * The following defines the rendering states
; */
    D3DSHADE_FLAT               EQU     1
    D3DSHADE_GOURAUD            EQU     2
    D3DSHADE_PHONG              EQU     3
    D3DSHADE_FORCE_DWORD        EQU     07fffffffh        ; /* force 32-bit size enum */
D3DSHADEMODE                TYPEDEF     DWORD

    D3DFILL_POINT               EQU     1
    D3DFILL_WIREFRAME           EQU     2
    D3DFILL_SOLID               EQU     3
    D3DFILL_FORCE_DWORD         EQU     07fffffffh        ; /* force 32-bit size enum */
D3DFILLMODE                 TYPEDEF      DWORD 

_D3DLINEPATTERN struct  DWORD
    wRepeatFactor       WORD        ?
    wLinePattern        WORD        ?
_D3DLINEPATTERN ENDS
D3DLINEPATTERN                TYPEDEF		_D3DLINEPATTERN

    D3DBLEND_ZERO               EQU     1
    D3DBLEND_ONE                EQU     2
    D3DBLEND_SRCCOLOR           EQU     3
    D3DBLEND_INVSRCCOLOR        EQU     4
    D3DBLEND_SRCALPHA           EQU     5
    D3DBLEND_INVSRCALPHA        EQU     6
    D3DBLEND_DESTALPHA          EQU     7
    D3DBLEND_INVDESTALPHA       EQU     8
    D3DBLEND_DESTCOLOR          EQU     9
    D3DBLEND_INVDESTCOLOR       EQU     10
    D3DBLEND_SRCALPHASAT        EQU     11
    D3DBLEND_BOTHSRCALPHA       EQU     12
    D3DBLEND_BOTHINVSRCALPHA    EQU     13
    D3DBLEND_FORCE_DWORD        EQU     07fffffffh    ; /* force 32-bit size enum */
D3DBLEND                TYPEDEF             DWORD

    D3DBLENDOP_ADD              EQU     1
    D3DBLENDOP_SUBTRACT         EQU     2
    D3DBLENDOP_REVSUBTRACT      EQU     3
    D3DBLENDOP_MIN              EQU     4
    D3DBLENDOP_MAX              EQU     5
    D3DBLENDOP_FORCE_DWORD      EQU     07fffffffh  ; /* force 32-bit size enum */
D3DBLENDOP                TYPEDEF             DWORD

    D3DTADDRESS_WRAP            EQU     1
    D3DTADDRESS_MIRROR          EQU     2
    D3DTADDRESS_CLAMP           EQU     3
    D3DTADDRESS_BORDER          EQU     4
    D3DTADDRESS_MIRRORONCE      EQU     5
    D3DTADDRESS_FORCE_DWORD     EQU     07fffffffh  ; /* force 32-bit size enum */
D3DTEXTUREADDRESS              TYPEDEF             DWORD

    D3DCULL_NONE                EQU     1
    D3DCULL_CW                  EQU     2
    D3DCULL_CCW                 EQU     3
    D3DCULL_FORCE_DWORD         EQU     07fffffffh  ; /* force 32-bit size enum */
D3DCULL                TYPEDEF             DWORD

    D3DCMP_NEVER                EQU     1
    D3DCMP_LESS                 EQU     2
    D3DCMP_EQUAL                EQU     3
    D3DCMP_LESSEQUAL            EQU     4
    D3DCMP_GREATER              EQU     5
    D3DCMP_NOTEQUAL             EQU     6
    D3DCMP_GREATEREQUAL         EQU     7
    D3DCMP_ALWAYS               EQU     8
    D3DCMP_FORCE_DWORD          EQU     07fffffffh  ; /* force 32-bit size enum */
D3DCMPFUNC                TYPEDEF             DWORD

    D3DSTENCILOP_KEEP           EQU     1
    D3DSTENCILOP_ZERO           EQU     2
    D3DSTENCILOP_REPLACE        EQU     3
    D3DSTENCILOP_INCRSAT        EQU     4
    D3DSTENCILOP_DECRSAT        EQU     5
    D3DSTENCILOP_INVERT         EQU     6
    D3DSTENCILOP_INCR           EQU     7
    D3DSTENCILOP_DECR           EQU     8
    D3DSTENCILOP_FORCE_DWORD    EQU     07fffffffh  ; /* force 32-bit size enum */
D3DSTENCILOP                TYPEDEF             DWORD

    D3DFOG_NONE                 EQU     0
    D3DFOG_EXP                  EQU     1
    D3DFOG_EXP2                 EQU     2
    D3DFOG_LINEAR               EQU     3
    D3DFOG_FORCE_DWORD          EQU     07fffffffh  ; /* force 32-bit size enum */
D3DFOGMODE                TYPEDEF             DWORD

    D3DZB_FALSE                 EQU     0
    D3DZB_TRUE                  EQU     1   ;// Z buffering
    D3DZB_USEW                  EQU     2   ;// W buffering
    D3DZB_FORCE_DWORD           EQU     07fffffffh  ;/* force 32-bit size enum */
D3DZBUFFERTYPE                TYPEDEF             DWORD

;// Primitives supported by draw-primitive API
    D3DPT_POINTLIST             EQU     1
    D3DPT_LINELIST              EQU     2
    D3DPT_LINESTRIP             EQU     3
    D3DPT_TRIANGLELIST          EQU     4
    D3DPT_TRIANGLESTRIP         EQU     5
    D3DPT_TRIANGLEFAN           EQU     6
    D3DPT_FORCE_DWORD           EQU     07fffffffh  ;/* force 32-bit size enum */
D3DPRIMITIVETYPE               TYPEDEF             DWORD

    D3DTS_VIEW                  EQU     2
    D3DTS_PROJECTION            EQU     3
    D3DTS_TEXTURE0              EQU     16
    D3DTS_TEXTURE1              EQU     17
    D3DTS_TEXTURE2              EQU     18
    D3DTS_TEXTURE3              EQU     19
    D3DTS_TEXTURE4              EQU     20
    D3DTS_TEXTURE5              EQU     21
    D3DTS_TEXTURE6              EQU     22
    D3DTS_TEXTURE7              EQU     23
    D3DTS_FORCE_DWORD           EQU     07fffffffh    ; /* force 32-bit size enum */
D3DTRANSFORMSTATETYPE        TYPEDEF             DWORD

;#define D3DTS_WORLDMATRIX(index) (D3DTRANSFORMSTATETYPE)(index + 256)
D3DTS_WORLDMATRIX MACRO index
	local DefineAs
	DefineAs EQU (D3DTRANSFORMSTATETYPE)(index + 256)
	EXITM DefineAs
ENDM D3DTS_WORLDMATRIX

;#define D3DTS_WORLD  D3DTS_WORLDMATRIX(0)
D3DTS_WORLD EQU D3DTS_WORLDMATRIX 0
;#define D3DTS_WORLD1 D3DTS_WORLDMATRIX(1)
D3DTS_WORLD1 EQU D3DTS_WORLDMATRIX 1
;#define D3DTS_WORLD2 D3DTS_WORLDMATRIX(2)
D3DTS_WORLD2 EQU D3DTS_WORLDMATRIX 2
;#define D3DTS_WORLD3 D3DTS_WORLDMATRIX(3)
D3DTS_WORLD3 EQU D3DTS_WORLDMATRIX 3

    D3DRS_ZENABLE                   EQU    7      ;    /* D3DZBUFFERTYPE (or TRUE/FALSE for legacy) */
    D3DRS_FILLMODE                  EQU    8      ;    /* D3DFILL_MODE        */
    D3DRS_SHADEMODE                 EQU    9      ;    /* D3DSHADEMODE */
    D3DRS_LINEPATTERN               EQU    10      ;   /* D3DLINEPATTERN */
    D3DRS_ZWRITEENABLE              EQU    14      ;   /* TRUE to enable z writes */
    D3DRS_ALPHATESTENABLE           EQU    15      ;   /* TRUE to enable alpha tests */
    D3DRS_LASTPIXEL                 EQU    16      ;   /* TRUE for last-pixel on lines */
    D3DRS_SRCBLEND                  EQU    19      ;   /* D3DBLEND */
    D3DRS_DESTBLEND                 EQU    20      ;   /* D3DBLEND */
    D3DRS_CULLMODE                  EQU    22      ;   /* D3DCULL */
    D3DRS_ZFUNC                     EQU    23      ;   /* D3DCMPFUNC */
    D3DRS_ALPHAREF                  EQU    24      ;   /* D3DFIXED */
    D3DRS_ALPHAFUNC                 EQU    25      ;   /* D3DCMPFUNC */
    D3DRS_DITHERENABLE              EQU    26      ;   /* TRUE to enable dithering */
    D3DRS_ALPHABLENDENABLE          EQU    27      ;   /* TRUE to enable alpha blending */
    D3DRS_FOGENABLE                 EQU    28      ;   /* TRUE to enable fog blending */
    D3DRS_SPECULARENABLE            EQU    29      ;   /* TRUE to enable specular */
    D3DRS_ZVISIBLE                  EQU    30      ;   /* TRUE to enable z checking */
    D3DRS_FOGCOLOR                  EQU    34      ;   /* D3DCOLOR */
    D3DRS_FOGTABLEMODE              EQU    35      ;   /* D3DFOGMODE */
    D3DRS_FOGSTART                  EQU    36      ;   /* Fog start (for both vertex and pixel fog) */
    D3DRS_FOGEND                    EQU    37      ;   /* Fog end      */
    D3DRS_FOGDENSITY                EQU    38      ;   /* Fog density  */
    D3DRS_EDGEANTIALIAS             EQU    40      ;   /* TRUE to enable edge antialiasing */
    D3DRS_ZBIAS                     EQU    47      ;   /* LONG Z bias */
    D3DRS_RANGEFOGENABLE            EQU    48      ;   /* Enables range-based fog */
    D3DRS_STENCILENABLE             EQU    52      ;   /* BOOL enable/disable stenciling */
    D3DRS_STENCILFAIL               EQU    53      ;   /* D3DSTENCILOP to do if stencil test fails */
    D3DRS_STENCILZFAIL              EQU    54      ;   /* D3DSTENCILOP to do if stencil test passes and Z test fails */
    D3DRS_STENCILPASS               EQU    55      ;   /* D3DSTENCILOP to do if both stencil and Z tests pass */
    D3DRS_STENCILFUNC               EQU    56      ;   /* D3DCMPFUNC fn.  Stencil Test passes if ((ref & mask) stencilfn (stencil & mask)) is true */
    D3DRS_STENCILREF                EQU    57      ;   /* Reference value used in stencil test */
    D3DRS_STENCILMASK               EQU    58      ;   /* Mask value used in stencil test */
    D3DRS_STENCILWRITEMASK          EQU    59      ;   /* Write mask applied to values written to stencil buffer */
    D3DRS_TEXTUREFACTOR             EQU    60      ;   /* D3DCOLOR used for multi-texture blend */
    D3DRS_WRAP0                     EQU    128      ;  /* wrap for 1st texture coord. set */
    D3DRS_WRAP1                     EQU    129      ;  /* wrap for 2nd texture coord. set */
    D3DRS_WRAP2                     EQU    130      ;  /* wrap for 3rd texture coord. set */
    D3DRS_WRAP3                     EQU    131      ;  /* wrap for 4th texture coord. set */
    D3DRS_WRAP4                     EQU    132      ;  /* wrap for 5th texture coord. set */
    D3DRS_WRAP5                     EQU    133      ;  /* wrap for 6th texture coord. set */
    D3DRS_WRAP6                     EQU    134      ;  /* wrap for 7th texture coord. set */
    D3DRS_WRAP7                     EQU    135      ;  /* wrap for 8th texture coord. set */
    D3DRS_CLIPPING                  EQU    136      ;
    D3DRS_LIGHTING                  EQU    137      ;
    D3DRS_AMBIENT                   EQU    139      ;
    D3DRS_FOGVERTEXMODE             EQU    140      ;
    D3DRS_COLORVERTEX               EQU    141      ;
    D3DRS_LOCALVIEWER               EQU    142      ;
    D3DRS_NORMALIZENORMALS          EQU    143      ;
    D3DRS_DIFFUSEMATERIALSOURCE     EQU    145      ;
    D3DRS_SPECULARMATERIALSOURCE    EQU    146      ;
    D3DRS_AMBIENTMATERIALSOURCE     EQU    147      ;
    D3DRS_EMISSIVEMATERIALSOURCE    EQU    148      ;
    D3DRS_VERTEXBLEND               EQU    151      ;
    D3DRS_CLIPPLANEENABLE           EQU    152      ;
    D3DRS_SOFTWAREVERTEXPROCESSING  EQU    153      ;
    D3DRS_POINTSIZE                 EQU    154      ;   /* float point size */
    D3DRS_POINTSIZE_MIN             EQU    155      ;   /* float point size min threshold */
    D3DRS_POINTSPRITEENABLE         EQU    156      ;   /* BOOL point texture coord control */
    D3DRS_POINTSCALEENABLE          EQU    157      ;   /* BOOL point size scale enable */
    D3DRS_POINTSCALE_A              EQU    158      ;   /* float point attenuation A value */
    D3DRS_POINTSCALE_B              EQU    159      ;   /* float point attenuation B value */
    D3DRS_POINTSCALE_C              EQU    160      ;   /* float point attenuation C value */
    D3DRS_MULTISAMPLEANTIALIAS      EQU    161      ;  // BOOL - set to do FSAA with multisample buffer
    D3DRS_MULTISAMPLEMASK           EQU    162      ;  // DWORD - per-sample enable/disable
    D3DRS_PATCHEDGESTYLE            EQU    163      ;  // Sets whether patch edges will use float style tessellation
    D3DRS_PATCHSEGMENTS             EQU    164      ;  // Number of segments per edge when drawing patches
    D3DRS_DEBUGMONITORTOKEN         EQU    165      ;  // DEBUG ONLY - token to debug monitor
    D3DRS_POINTSIZE_MAX             EQU    166      ;   /* float point size max threshold */
    D3DRS_INDEXEDVERTEXBLENDENABLE  EQU    167      ;
    D3DRS_COLORWRITEENABLE          EQU    168      ;  // per-channel write enable
    D3DRS_TWEENFACTOR               EQU    170      ;   // float tween factor
    D3DRS_BLENDOP                   EQU    171      ;   // D3DBLENDOP setting
    D3DRS_FORCE_DWORD               EQU    07fffffffh      ; /* force 32-bit size enum */
D3DRENDERSTATETYPE                TYPEDEF             DWORD

;// Values for material source
    D3DMCS_MATERIAL                 EQU    0    ;            // Color from material is used
    D3DMCS_COLOR1                   EQU    1    ;            // Diffuse vertex color is used
    D3DMCS_COLOR2                   EQU    2    ;            // Specular vertex color is used
    D3DMCS_FORCE_DWORD              EQU    07fffffffh   ;,   // force 32-bit size enum
D3DMATERIALCOLORSOURCE               TYPEDEF             DWORD

;// Bias to apply to the texture coordinate set to apply a wrap to.
D3DRENDERSTATE_WRAPBIAS                 EQU     128         ;128UL

;/* Flags to construct the WRAP render states */
D3DWRAP_U                   EQU            00000001h     ;0x00000001L
D3DWRAP_V                   EQU            00000002h     ;0x00000002L
D3DWRAP_W                   EQU            00000004h     ;0x00000004L

;/* Flags to construct the WRAP render states for 1D thru 4D texture coordinates */
D3DWRAPCOORD_0              EQU            00000001h     ;0x00000001L    // same as D3DWRAP_U
D3DWRAPCOORD_1              EQU            00000002h     ;0x00000002L    // same as D3DWRAP_V
D3DWRAPCOORD_2              EQU            00000004h     ;0x00000004L    // same as D3DWRAP_W
D3DWRAPCOORD_3              EQU            00000008h     ;0x00000008L

;/* Flags to construct D3DRS_COLORWRITEENABLE */
;#define D3DCOLORWRITEENABLE_RED     (1L<<0)
D3DCOLORWRITEENABLE_RED MACRO 	;; (1 << 0)
    (1 SHL 0)
ENDM
;#define D3DCOLORWRITEENABLE_GREEN   (1L<<1)
D3DCOLORWRITEENABLE_GREEN MACRO 	;; (1 << 1)
    (1 SHL 1)
ENDM
;#define D3DCOLORWRITEENABLE_BLUE    (1L<<2)
D3DCOLORWRITEENABLE_BLUE MACRO 	;; (1 << 2)
    (1 SHL 2)
ENDM
;#define D3DCOLORWRITEENABLE_ALPHA   (1L<<3)
D3DCOLORWRITEENABLE_ALPHA MACRO 	;; (1 << 3)
    (1 SHL 3)
ENDM


;/*
; * State enumerants for per-stage texture processing.
; */
    D3DTSS_COLOROP            EQU      1      ;/* D3DTEXTUREOP - per-stage blending controls for color channels */
    D3DTSS_COLORARG1          EQU      2      ;/* D3DTA_* (texture arg) */
    D3DTSS_COLORARG2          EQU      3      ;/* D3DTA_* (texture arg) */
    D3DTSS_ALPHAOP            EQU      4      ;/* D3DTEXTUREOP - per-stage blending controls for alpha channel */
    D3DTSS_ALPHAARG1          EQU      5      ;/* D3DTA_* (texture arg) */
    D3DTSS_ALPHAARG2          EQU      6      ;/* D3DTA_* (texture arg) */
    D3DTSS_BUMPENVMAT00       EQU      7      ;/* float (bump mapping matrix) */
    D3DTSS_BUMPENVMAT01       EQU      8      ;/* float (bump mapping matrix) */
    D3DTSS_BUMPENVMAT10       EQU      9      ;/* float (bump mapping matrix) */
    D3DTSS_BUMPENVMAT11       EQU     10      ;/* float (bump mapping matrix) */
    D3DTSS_TEXCOORDINDEX      EQU     11      ;/* identifies which set of texture coordinates index this texture */
    D3DTSS_ADDRESSU           EQU     13      ;/* D3DTEXTUREADDRESS for U coordinate */
    D3DTSS_ADDRESSV           EQU     14      ;/* D3DTEXTUREADDRESS for V coordinate */
    D3DTSS_BORDERCOLOR        EQU     15      ;/* D3DCOLOR */
    D3DTSS_MAGFILTER          EQU     16      ;/* D3DTEXTUREFILTER filter to use for magnification */
    D3DTSS_MINFILTER          EQU     17      ;/* D3DTEXTUREFILTER filter to use for minification */
    D3DTSS_MIPFILTER          EQU     18      ;/* D3DTEXTUREFILTER filter to use between mipmaps during minification */
    D3DTSS_MIPMAPLODBIAS      EQU     19      ;/* float Mipmap LOD bias */
    D3DTSS_MAXMIPLEVEL        EQU     20      ;/* DWORD 0..(n-1) LOD index of largest map to use (0     EQU        EQU     largest) */
    D3DTSS_MAXANISOTROPY      EQU     21      ;/* DWORD maximum anisotropy */
    D3DTSS_BUMPENVLSCALE      EQU     22      ;/* float scale for bump map luminance */
    D3DTSS_BUMPENVLOFFSET     EQU     23      ;/* float offset for bump map luminance */
    D3DTSS_TEXTURETRANSFORMFLAGS     EQU     24      ;/* D3DTEXTURETRANSFORMFLAGS controls texture transform */
    D3DTSS_ADDRESSW           EQU     25      ;/* D3DTEXTUREADDRESS for W coordinate */
    D3DTSS_COLORARG0          EQU     26      ;/* D3DTA_* third arg for triadic ops */
    D3DTSS_ALPHAARG0          EQU     27      ;/* D3DTA_* third arg for triadic ops */
    D3DTSS_RESULTARG          EQU     28      ;/* D3DTA_* arg for result (CURRENT or TEMP) */
    D3DTSS_FORCE_DWORD       EQU     7fffffffh        ;0x7fffffff  /* force 32-bit size enum */
D3DTEXTURESTAGESTATETYPE        TYPEDEF             DWORD

;// Values, used with D3DTSS_TEXCOORDINDEX, to specify that the vertex data(position
;// and normal in the camera space) should be taken as texture coordinates
;// Low 16 bits are used to specify texture coordinate index, to take the WRAP mode from
;//
D3DTSS_TCI_PASSTHRU                         EQU     00000000h    ;  0x00000000
D3DTSS_TCI_CAMERASPACENORMAL                EQU     00010000h    ;  0x00010000
D3DTSS_TCI_CAMERASPACEPOSITION              EQU     00020000h    ;  0x00020000
D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR      EQU     00030000h    ;  0x00030000

;/*
; * Enumerations for COLOROP and ALPHAOP texture blending operations set in
; * texture processing stage controls in D3DRENDERSTATE.
; */
    ;// Control
    D3DTOP_DISABLE                  EQU     1      ;// disables stage
    D3DTOP_SELECTARG1               EQU     2      ;// the default
    D3DTOP_SELECTARG2               EQU     3

    ;// Modulate
    D3DTOP_MODULATE                 EQU     4      ;// multiply args together
    D3DTOP_MODULATE2X               EQU     5      ;// multiply and  1 bit
    D3DTOP_MODULATE4X               EQU     6      ;// multiply and  2 bits

    ;// Add
    D3DTOP_ADD                      EQU      7      ;// add arguments together
    D3DTOP_ADDSIGNED                EQU      8      ;// add with -0.5 bias
    D3DTOP_ADDSIGNED2X              EQU      9      ;// as above but left  1 bit
    D3DTOP_SUBTRACT                 EQU     10      ;// Arg1 - Arg2, with no saturation
    D3DTOP_ADDSMOOTH                EQU     11      ;// add 2 args, subtract product
                                                    ;// Arg1 + Arg2 - Arg1*Arg2
                                                    ;// =Arg1 + (1-Arg1)*Arg2

    ;// Linear alpha blend: Arg1*(Alpha) + Arg2*(1-Alpha)
    D3DTOP_BLENDDIFFUSEALPHA        EQU     12      ;// iterated alpha
    D3DTOP_BLENDTEXTUREALPHA        EQU     13      ;// texture alpha
    D3DTOP_BLENDFACTORALPHA         EQU     14      ;// alpha from D3DRENDERSTATE_TEXTUREFACTOR

    ;// Linear alpha blend with pre-multiplied arg1 input: Arg1 + Arg2*(1-Alpha)
    D3DTOP_BLENDTEXTUREALPHAPM      EQU     15      ;// texture alpha
    D3DTOP_BLENDCURRENTALPHA        EQU     16      ;// by alpha of current color

    ;// Specular mapping
    D3DTOP_PREMODULATE              EQU     17      ;// modulate with next texture before use
    D3DTOP_MODULATEALPHA_ADDCOLOR   EQU     18      ;// Arg1.RGB + Arg1.A*Arg2.RGB
                                            ;// COLOROP only
    D3DTOP_MODULATECOLOR_ADDALPHA   EQU     19     ;// Arg1.RGB*Arg2.RGB + Arg1.A
                                            ;// COLOROP only
    D3DTOP_MODULATEINVALPHA_ADDCOLOR    EQU     20  ;// (1-Arg1.A)*Arg2.RGB + Arg1.RGB
                                            ;// COLOROP only
    D3DTOP_MODULATEINVCOLOR_ADDALPHA    EQU     21  ;// (1-Arg1.RGB)*Arg2.RGB + Arg1.A
                                            ;// COLOROP only

    ;// Bump mapping
    D3DTOP_BUMPENVMAP               EQU     22      ;// per pixel env map perturbation
    D3DTOP_BUMPENVMAPLUMINANCE      EQU     23      ;// with luminance channel

    ;// This can do either diffuse or specular bump mapping with correct input.
    ;// Performs the function (Arg1.R*Arg2.R + Arg1.G*Arg2.G + Arg1.B*Arg2.B)
    ;// where each component has been scaled and offset to make it signed.
    ;// The result is replicated into all four (including alpha) channels.
    ;// This is a valid COLOROP only.
    D3DTOP_DOTPRODUCT3              EQU     24

    ;// Triadic ops
    D3DTOP_MULTIPLYADD              EQU     25      ;// Arg0 + Arg1*Arg2
    D3DTOP_LERP                     EQU     26      ;// (Arg0)*Arg1 + (1-Arg0)*Arg2

    D3DTOP_FORCE_DWORD     EQU     7fffffffh        ;0x7fffffff
D3DTEXTUREOP                TYPEDEF             DWORD 

;/*
; * Values for COLORARG0,1,2, ALPHAARG0,1,2, and RESULTARG texture blending
; * operations set in texture processing stage controls in D3DRENDERSTATE.
; */
D3DTA_SELECTMASK            EQU     0000000fh    ;0x0000000f  ;// mask for arg selector
D3DTA_DIFFUSE               EQU     00000000h    ;0x00000000  ;// select diffuse color (read only)
D3DTA_CURRENT               EQU     00000001h    ;0x00000001  ;// select stage destination register (read/write)
D3DTA_TEXTURE               EQU     00000002h    ;0x00000002  ;// select texture color (read only)
D3DTA_TFACTOR               EQU     00000003h    ;0x00000003  ;// select RENDERSTATE_TEXTUREFACTOR (read only)
D3DTA_SPECULAR              EQU     00000004h    ;0x00000004  ;// select specular color (read only)
D3DTA_TEMP                  EQU     00000005h    ;0x00000005  ;// select temporary register color (read/write)
D3DTA_COMPLEMENT            EQU     00000010h    ;0x00000010  ;// take 1.0 - x (read modifier)
D3DTA_ALPHAREPLICATE        EQU     00000020h    ;0x00000020  ;// replicate alpha to color components (read modifier)

;//
;// Values for D3DTSS_***FILTER texture stage states
;//
    D3DTEXF_NONE            EQU 0    ;// filtering disabled (valid for mip filter only)
    D3DTEXF_POINT           EQU 1    ;// nearest
    D3DTEXF_LINEAR          EQU 2    ;// linear interpolation
    D3DTEXF_ANISOTROPIC     EQU 3    ;// anisotropic
    D3DTEXF_FLATCUBIC       EQU 4    ;// cubic
    D3DTEXF_GAUSSIANCUBIC   EQU 5    ;// different cubic kernel
    D3DTEXF_FORCE_DWORD     EQU 7fffffffh   ;0x7fffffff,   // force 32-bit size enum
D3DTEXTUREFILTERTYPE            TYPEDEF             DWORD 

;/* Bits for Flags in ProcessVertices call */

;#define D3DPV_DONOTCOPYDATA     (1 << 0)
D3DPV_DONOTCOPYDATA MACRO 	;; (1 << 0)
    (1 SHL 0)
ENDM

;//-------------------------------------------------------------------

;// Flexible vertex format bits
;//
D3DFVF_RESERVED0        EQU    001h
D3DFVF_POSITION_MASK    EQU    00Eh
D3DFVF_XYZ              EQU    002h
D3DFVF_XYZRHW           EQU    004h
D3DFVF_XYZB1            EQU    006h
D3DFVF_XYZB2            EQU    008h
D3DFVF_XYZB3            EQU    00ah
D3DFVF_XYZB4            EQU    00ch
D3DFVF_XYZB5            EQU    00eh

D3DFVF_NORMAL           EQU    010h
D3DFVF_PSIZE            EQU    020h
D3DFVF_DIFFUSE          EQU    040h
D3DFVF_SPECULAR         EQU    080h

D3DFVF_TEXCOUNT_MASK    EQU    0f00h
D3DFVF_TEXCOUNT_SHIFT   EQU    8
D3DFVF_TEX0             EQU    000h
D3DFVF_TEX1             EQU    100h
D3DFVF_TEX2             EQU    200h
D3DFVF_TEX3             EQU    300h
D3DFVF_TEX4             EQU    400h
D3DFVF_TEX5             EQU    500h
D3DFVF_TEX6             EQU    600h
D3DFVF_TEX7             EQU    700h
D3DFVF_TEX8             EQU    800h

D3DFVF_LASTBETA_UBYTE4  EQU    1000h

D3DFVF_RESERVED2        EQU    0E000h  // 4 reserved bits

;#######################################################################
;//---------------------------------------------------------------------
;// Vertex Shaders
;//
;#######################################################################

;/*

;Vertex Shader Declaration
;
;The declaration portion of a vertex shader defines the static external
;interface of the shader.  The information in the declaration includes:
;
;- Assignments of vertex shader input registers to data streams.  These
;assignments bind a specific vertex register to a single component within a
;vertex stream.  A vertex stream element is identified by a byte offset
;within the stream and a type.  The type specifies the arithmetic data type
;plus the dimensionality (1, 2, 3, or 4 values).  Stream data which is
;less than 4 values are always expanded out to 4 values with zero or more
;0.F values and one 1.F value.
;
;- Assignment of vertex shader input registers to implicit data from the
;primitive tessellator.  This controls the loading of vertex data which is
;not loaded from a stream, but rather is generated during primitive
;tessellation prior to the vertex shader.
;
;- Loading data into the constant memory at the time a shader is set as the
;current shader.  Each token specifies values for one or more contiguous 4
;DWORD constant registers.  This allows the shader to update an arbitrary
;subset of the constant memory, overwriting the device state (which
;contains the current values of the constant memory).  Note that these
;values can be subsequently overwritten (between DrawPrimitive calls)
;during the time a shader is bound to a device via the
;SetVertexShaderConstant method.
;
;
;Declaration arrays are single-dimensional arrays of DWORDs composed of
;multiple tokens each of which is one or more DWORDs.  The single-DWORD
;token value 0xFFFFFFFF is a special token used to indicate the end of the
;declaration array.  The single DWORD token value 0x00000000 is a NOP token
;with is ignored during the declaration parsing.  Note that 0x00000000 is a
;valid value for DWORDs following the first DWORD for multiple word tokens.
;
;[31:29] TokenType
;    0x0 - NOP (requires all DWORD bits to be zero)
;    0x1 - stream selector
;    0x2 - stream data definition (map to vertex input memory)
;    0x3 - vertex input memory from tessellator
;    0x4 - constant memory from shader
;    0x5 - extension
;    0x6 - reserved
;    0x7 - end-of-array (requires all DWORD bits to be 1)
;
;NOP Token (single DWORD token)
;    [31:29] 0x0
;    [28:00] 0x0
;
;Stream Selector (single DWORD token)
;    [31:29] 0x1
;    [28]    indicates whether this is a tessellator stream
;    [27:04] 0x0
;    [03:00] stream selector (0..15)
;
;Stream Data Definition (single DWORD token)
;    Vertex Input Register Load
;      [31:29] 0x2
;      [28]    0x0
;      [27:20] 0x0
;      [19:16] type (dimensionality and data type)
;      [15:04] 0x0
;      [03:00] vertex register address (0..15)
;    Data Skip (no register load)
;      [31:29] 0x2
;      [28]    0x1
;      [27:20] 0x0
;      [19:16] count of DWORDS to skip over (0..15)
;      [15:00] 0x0
;    Vertex Input Memory from Tessellator Data (single DWORD token)
;      [31:29] 0x3
;      [28]    indicates whether data is normals or u/v
;      [27:24] 0x0
;      [23:20] vertex register address (0..15)
;      [19:16] type (dimensionality)
;      [15:04] 0x0
;      [03:00] vertex register address (0..15)
;
;Constant Memory from Shader (multiple DWORD token)
;    [31:29] 0x4
;    [28:25] count of 4*DWORD constants to load (0..15)
;    [24:07] 0x0
;    [06:00] constant memory address (0..95)
;
;Extension Token (single or multiple DWORD token)
;    [31:29] 0x5
;    [28:24] count of additional DWORDs in token (0..31)
;    [23:00] extension-specific information
;
;End-of-array token (single DWORD token)
;    [31:29] 0x7
;    [28:00] 0x1fffffff
;
;The stream selector token must be immediately followed by a contiguous set of 
;stream data definition tokens.  This token sequence fully defines that stream, 
;including the set of elements within the stream, the order in which the elements 
;appear, the type of each element, and the vertex register into which to load an element.
;Streams are allowed to include data which is not loaded into a vertex register, thus 
;allowing data which is not used for this shader to exist in the vertex stream.  
;This skipped data is defined only by a count of DWORDs to skip over, since the type 
;information is irrelevant.
;The token sequence:
;Stream Select: stream=0
;Stream Data Definition (Load): type=FLOAT3; register=3
;Stream Data Definition (Load): type=FLOAT3; register=4
;Stream Data Definition (Skip): count=2
;Stream Data Definition (Load): type=FLOAT2; register=7
;
;defines stream zero to consist of 4 elements, 3 of which are loaded into registers and 
;the fourth skipped over.  Register 3 is loaded with the first three DWORDs in each vertex 
;interpreted as FLOAT data.  Register 4 is loaded with the 4th, 5th, and 6th DWORDs interpreted 
;as FLOAT data.  The next two DWORDs (7th and 8th) are skipped over and not loaded into any 
;vertex input register.   Register 7 is loaded with the 9th and 10th DWORDS interpreted as FLOAT data.
;Placing of tokens other than NOPs between the Stream Selector and Stream Data Definition tokens is disallowed.
;
;*/

 D3DVSD_TOKENTYPE TYPEDEF DWORD
	D3DVSD_TOKEN_NOP               EQU 0	; NOP or extension
	D3DVSD_TOKEN_STREAM	       EQU 1	; stream selector
	D3DVSD_TOKEN_STREAMDATA        EQU 2	; stream data definition (map to vertex input memory)
	D3DVSD_TOKEN_TESSELLATOR       EQU 3	; vertex input memory from tessellator
	D3DVSD_TOKEN_CONSTMEM          EQU 4	; constant memory from shader
	D3DVSD_TOKEN_EXT               EQU 5	; extension
	;							EQU 6	;?
	D3DVSD_TOKEN_END			EQU 7	; end-of-array (requires all DWORD bits to be 1)
    D3DVSD_FORCE_DWORD EQU 07fffffffh ;// force 32-bit size enum

;###########################################

D3DVSD_TOKENTYPESHIFT       EQU     29
D3DVSD_TOKENTYPEMASK        EQU     (07h SHL D3DVSD_TOKENTYPESHIFT)

D3DVSD_STREAMNUMBERSHIFT    EQU     0
D3DVSD_STREAMNUMBERMASK     EQU     (0Fh SHL D3DVSD_STREAMNUMBERSHIFT)

D3DVSD_DATALOADTYPESHIFT    EQU     28
D3DVSD_DATALOADTYPEMASK     EQU     (01h SHL D3DVSD_DATALOADTYPESHIFT)

D3DVSD_DATATYPESHIFT        EQU     16
D3DVSD_DATATYPEMASK         EQU     (0Fh SHL D3DVSD_DATATYPESHIFT)

D3DVSD_SKIPCOUNTSHIFT       EQU     16
D3DVSD_SKIPCOUNTMASK        EQU     (0Fh SHL D3DVSD_SKIPCOUNTSHIFT)

D3DVSD_VERTEXREGSHIFT       EQU     0
D3DVSD_VERTEXREGMASK        EQU     (01Fh SHL D3DVSD_VERTEXREGSHIFT)

D3DVSD_VERTEXREGINSHIFT     EQU     20
D3DVSD_VERTEXREGINMASK      EQU     (0Fh SHL D3DVSD_VERTEXREGINSHIFT)

D3DVSD_CONSTCOUNTSHIFT      EQU     25
D3DVSD_CONSTCOUNTMASK       EQU     (0Fh SHL D3DVSD_CONSTCOUNTSHIFT)

D3DVSD_CONSTADDRESSSHIFT    EQU     0
D3DVSD_CONSTADDRESSMASK     EQU     (07Fh SHL D3DVSD_CONSTADDRESSSHIFT)

D3DVSD_CONSTRSSHIFT         EQU     16
D3DVSD_CONSTRSMASK          EQU     (01FFFh SHL D3DVSD_CONSTRSSHIFT)

D3DVSD_EXTCOUNTSHIFT        EQU     24
D3DVSD_EXTCOUNTMASK         EQU     (01Fh SHL D3DVSD_EXTCOUNTSHIFT)

D3DVSD_EXTINFOSHIFT         EQU     0
D3DVSD_EXTINFOMASK          EQU     (0FFFFFFh SHL D3DVSD_EXTINFOSHIFT)

;#############################################################

D3DVSD_MAKETOKENTYPE MACRO _tokenType
    LOCAL DefineAs
        DefineAs = ((_tokenType SHL D3DVSD_TOKENTYPESHIFT) AND D3DVSD_TOKENTYPEMASK)
    EXITM %DefineAs
ENDM

; macros for generation of CreateVertexShader Declaration token array

; Set current stream
; _StreamNumber [0..(MaxStreams-1)] stream to get data from
D3DVSD_STREAM MACRO _StreamNumber:REQ
EXITM %(D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_STREAM) OR (&_StreamNumber))
ENDM

D3DVSD_STREAM MACRO _StreamNumber
    LOCAL DefineAs
        DefineAs = (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_STREAM) OR (_StreamNumber))
    EXITM %DefineAs
ENDM


; Set tessellator stream
D3DVSD_STREAMTESSSHIFT          EQU 28
D3DVSD_STREAMTESSMASK           EQU     (1 SHL D3DVSD_STREAMTESSSHIFT)
D3DVSD_STREAM_TESS              EQU     <(D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_STREAM) OR (D3DVSD_STREAMTESSMASK))>

; bind single vertex register to vertex element from vertex stream
;
; _VertexRegister [0..15]     address of the vertex register
;           _Type [D3DVSDT_*] dimensionality and arithmetic data type
D3DVSD_REG MACRO _VertexRegister,_Type
    LOCAL DefineAs
        DefineAs = (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_STREAMDATA) OR ((_Type) SHL D3DVSD_DATATYPESHIFT) OR (_VertexRegister))
    EXITM %DefineAs
ENDM


; Skip _DWORDCount DWORDs in vertex
D3DVSD_SKIP MACRO _DWORDCount
	local DefineAs
	DefineAs = (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_STREAMDATA) OR 010000000h OR ((_DWORDCount) SHL D3DVSD_SKIPCOUNTSHIFT))
	EXITM %DefineAs
ENDM

; load data into vertex shader constant memory
;
; _ConstantAddress [0..95] - address of constant array to begin filling data
; _Count [0..15] - number of constant vectors to load (4 DWORDs each)
; followed by 4*_Count DWORDS of data
D3DVSD_CONST MACRO _ConstantAddress,_Count
    LOCAL DefineAs
        DefineAs = (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_CONSTMEM) OR ((_Count) SHL D3DVSD_CONSTCOUNTSHIFT) OR (_ConstantAddress))
    EXITM %DefineAs
ENDM

;// enable tessellator generated normals
;//
;// _VertexRegisterIn  [0..15] address of vertex register whose input stream
;//                            will be used in normal computation
;// _VertexRegisterOut [0..15] address of vertex register to output the normal to
;//
D3DVSD_TESSNORMAL MACRO _VertexRegisterIn, _VertexRegisterOut
	local DefineAs
	DefineAs = (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_TESSELLATOR)  OR  ((_VertexRegisterIn)  SHL  D3DVSD_VERTEXREGINSHIFT)  OR  ((002h)  SHL  D3DVSD_DATATYPESHIFT)  OR  (_VertexRegisterOut))
	EXITM %DefineAs
ENDM

;// enable tessellator generated surface parameters
;//
;// _VertexRegister [0..15] address of vertex register to output parameters
;//
D3DVSD_TESSUV MACRO _VertexRegister
	local DefineAs
	DefineAs = (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_TESSELLATOR)  OR  010000000h  OR  ((001h)  SHL  D3DVSD_DATATYPESHIFT)  OR  (_VertexRegister))
	EXITM %DefineAs
ENDM

;// Generates END token
;//
D3DVSD_END EQU 0FFFFFFFFh

;// Generates NOP token
D3DVSD_NOP EQU 000000000h


;// bit declarations for _Type fields
D3DVSDT_FLOAT1      EQU    00h    ;// 1D float expanded to (value, 0., 0., 1.)
D3DVSDT_FLOAT2      EQU    01h    ;// 2D float expanded to (value, value, 0., 1.)
D3DVSDT_FLOAT3      EQU    02h    ;// 3D float expanded to (value, value, value, 1.)
D3DVSDT_FLOAT4      EQU    03h    ;// 4D float
D3DVSDT_D3DCOLOR    EQU    04h    ;// 4D packed unsigned bytes mapped to 0. to 1. range
                                  ;// Input is in D3DCOLOR format (ARGB) expanded to (R, G, B, A)
D3DVSDT_UBYTE4      EQU    05h    ;// 4D unsigned byte
D3DVSDT_SHORT2      EQU    06h    ;// 2D signed short expanded to (value, value, 0., 1.)
D3DVSDT_SHORT4      EQU    07h    ;// 4D signed short

;// assignments of vertex input registers for fixed function vertex shader
;//
D3DVSDE_POSITION        EQU    0
D3DVSDE_BLENDWEIGHT     EQU    1
D3DVSDE_BLENDINDICES    EQU    2
D3DVSDE_NORMAL          EQU    3
D3DVSDE_PSIZE           EQU    4
D3DVSDE_DIFFUSE         EQU    5
D3DVSDE_SPECULAR        EQU    6
D3DVSDE_TEXCOORD0       EQU    7
D3DVSDE_TEXCOORD1       EQU    8
D3DVSDE_TEXCOORD2       EQU    9
D3DVSDE_TEXCOORD3       EQU    10
D3DVSDE_TEXCOORD4       EQU    11
D3DVSDE_TEXCOORD5       EQU    12
D3DVSDE_TEXCOORD6       EQU    13
D3DVSDE_TEXCOORD7       EQU    14
D3DVSDE_POSITION2       EQU    15
D3DVSDE_NORMAL2         EQU    16

;// Maximum supported number of texture coordinate sets
D3DDP_MAXTEXCOORD       EQU    8


;//
;// Instruction Token Bit Definitions
;//
;#define D3DSI_OPCODE_MASK       0x0000FFFF
D3DSI_OPCODE_MASK       EQU     0000ffffh

    D3DSIO_NOP          EQU     0       ;// PS/VS
    D3DSIO_MOV          EQU     1       ;// PS/VS
    D3DSIO_ADD          EQU     2       ;// PS/VS
    D3DSIO_SUB          EQU     3       ;// PS
    D3DSIO_MAD          EQU     4       ;// PS/VS
    D3DSIO_MUL          EQU     5       ;// PS/VS
    D3DSIO_RCP          EQU     6       ;// VS
    D3DSIO_RSQ          EQU     7       ;// VS
    D3DSIO_DP3          EQU     8       ;// PS/VS
    D3DSIO_DP4          EQU     9       ;// PS/VS
    D3DSIO_MIN          EQU     10      ;// VS
    D3DSIO_MAX          EQU     11      ;// VS
    D3DSIO_SLT          EQU     12      ;// VS
    D3DSIO_SGE          EQU     13      ;// VS
    D3DSIO_EXP          EQU     14      ;// VS
    D3DSIO_LOG          EQU     15      ;// VS
    D3DSIO_LIT          EQU     16      ;// VS
    D3DSIO_DST          EQU     17      ;// VS
    D3DSIO_LRP          EQU     18      ;// PS
    D3DSIO_FRC          EQU     19      ;// VS
    D3DSIO_M4x4         EQU     20      ;// VS
    D3DSIO_M4x3         EQU     21      ;// VS
    D3DSIO_M3x4         EQU     22      ;// VS
    D3DSIO_M3x3         EQU     23      ;// VS
    D3DSIO_M3x2         EQU     24      ;// VS

    D3DSIO_TEXCOORD     EQU     64      ;// PS
    D3DSIO_TEXKILL      EQU     65      ;// PS
    D3DSIO_TEX          EQU     66      ;// PS
    D3DSIO_TEXBEM       EQU     67      ;// PS
    D3DSIO_TEXBEML      EQU     68      ;// PS
    D3DSIO_TEXREG2AR    EQU     69      ;// PS
    D3DSIO_TEXREG2GB    EQU     70      ;// PS
    D3DSIO_TEXM3x2PAD   EQU     71      ;// PS
    D3DSIO_TEXM3x2TEX   EQU     72      ;// PS
    D3DSIO_TEXM3x3PAD   EQU     73      ;// PS
    D3DSIO_TEXM3x3TEX   EQU     74      ;// PS
    D3DSIO_TEXM3x3DIFF  EQU     75      ;// PS
    D3DSIO_TEXM3x3SPEC  EQU     76      ;// PS
    D3DSIO_TEXM3x3VSPEC EQU     77      ;// PS
    D3DSIO_EXPP         EQU     78      ;// VS
    D3DSIO_LOGP         EQU     79      ;// VS
    D3DSIO_CND          EQU     80      ;// PS
    D3DSIO_DEF          EQU     81      ;// PS
    D3DSIO_COMMENT      EQU     0fffeh  ;// 0xFFFE,
    D3DSIO_END          EQU     0ffffh  ;// 0xFFFF,

    D3DSIO_FORCE_DWORD  EQU     7fffffffh   ;//0x7fffffff,   // force 32-bit size enum
D3DSHADER_INSTRUCTION_OPCODE_TYPE       TYPEDEF     DWORD

;//
;// Co-Issue Instruction Modifier - if set then this instruction is to be
;// issued in parallel with the previous instruction(s) for which this bit
;// is not set.
;//
;#define D3DSI_COISSUE           0x40000000
D3DSI_COISSUE           EQU     40000000h

;//
;// Parameter Token Bit Definitions
;//
;#define D3DSP_REGNUM_MASK       0x00000FFF
D3DSP_REGNUM_MASK       EQU     00000fffh

;// destination parameter write mask
D3DSP_WRITEMASK_0       EQU    00010000h    ;// Component 0 (X;Red)
D3DSP_WRITEMASK_1       EQU    00020000h    ;// Component 1 (Y;Green)
D3DSP_WRITEMASK_2       EQU    00040000h    ;// Component 2 (Z;Blue)
D3DSP_WRITEMASK_3       EQU    00080000h    ;// Component 3 (W;Alpha)
D3DSP_WRITEMASK_ALL     EQU    000f0000h    ;// All Components

;// destination parameter modifiers
D3DSP_DSTMOD_SHIFT      EQU     20
D3DSP_DSTMOD_MASK       EQU    00f00000h

    D3DSPDM_NONE            EQU     (0 SHL D3DSP_DSTMOD_SHIFT)   ; // nop
    D3DSPDM_SATURATE        EQU     (1 SHL D3DSP_DSTMOD_SHIFT)   ; // clamp to 0. to 1. range
    D3DSPDM_FORCE_DWORD     EQU     7fffffffh                    ;      // force 32-bit size enum
D3DSHADER_PARAM_DSTMOD_TYPE     TYPEDEF     DWORD

;// destination parameter 
D3DSP_DSTSHIFT_SHIFT        EQU     24
D3DSP_DSTSHIFT_MASK         EQU     0f000000h

;// destination/source parameter register type
D3DSP_REGTYPE_SHIFT         EQU     28
D3DSP_REGTYPE_MASK          EQU     70000000h

    D3DSPR_TEMP             EQU         (0 SHL D3DSP_REGTYPE_SHIFT)     ;, // Temporary Register File
    D3DSPR_INPUT            EQU         (1 SHL D3DSP_REGTYPE_SHIFT)     ;, // Input Register File
    D3DSPR_CONST            EQU         (2 SHL D3DSP_REGTYPE_SHIFT)     ;, // Constant Register File
    D3DSPR_ADDR             EQU         (3 SHL D3DSP_REGTYPE_SHIFT)     ;, // Address Register (VS)
    D3DSPR_TEXTURE          EQU         (3 SHL D3DSP_REGTYPE_SHIFT)     ;, // Texture Register File (PS)
    D3DSPR_RASTOUT          EQU         (4 SHL D3DSP_REGTYPE_SHIFT)     ;, // Rasterizer Register File
    D3DSPR_ATTROUT          EQU         (5 SHL D3DSP_REGTYPE_SHIFT)     ;, // Attribute Output Register File
    D3DSPR_TEXCRDOUT        EQU         (6 SHL D3DSP_REGTYPE_SHIFT)     ;, // Texture Coordinate Output Register File
    D3DSPR_FORCE_DWORD      EQU         7fffffffh                       ;,         // force 32-bit size enum
D3DSHADER_PARAM_REGISTER_TYPE     TYPEDEF     DWORD



;################################################################################
;################################################################################
;################################################################################
;################################################################################
;################################################################################
;################################################################################
;// Register offsets in the Rasterizer Register File
;//
D3DVS_RASTOUT_OFFSETS TYPEDEF DWORD
;typedef enum _D3DVS_RASTOUT_OFFSETS {
    D3DSRO_POSITION EQU 0
;    D3DSRO_FOG
;    D3DSRO_POINT_SIZE
    D3DSRO_FORCE_DWORD  EQU 07fffffffh         ;// force 32-bit size enum
;} D3DVS_RASTOUT_OFFSETS;

;// Source operand addressing modes

D3DVS_ADDRESSMODE_SHIFT EQU 13
D3DVS_ADDRESSMODE_MASK  EQU (1  SHL  D3DVS_ADDRESSMODE_SHIFT)

D3DVS_ADDRESSMODE_TYPE TYPEDEF DWORD
;typedef enum _D3DVS_ADDRESSMODE_TYPE {
    D3DVS_ADDRMODE_ABSOLUTE  EQU (0  SHL  D3DVS_ADDRESSMODE_SHIFT)
    D3DVS_ADDRMODE_RELATIVE  EQU (1  SHL  D3DVS_ADDRESSMODE_SHIFT)   ;// Relative to register A0
    D3DVS_ADDRMODE_FORCE_DWORD EQU 07fffffffh ;// force 32-bit size enum
;} D3DVS_ADDRESSMODE_TYPE;


;// Source operand swizzle definitions
;//
D3DVS_SWIZZLE_SHIFT     EQU 16
D3DVS_SWIZZLE_MASK      EQU 000FF0000h

;// The following bits define where to take component X:

D3DVS_X_X       EQU (0  SHL  D3DVS_SWIZZLE_SHIFT)
D3DVS_X_Y       EQU (1  SHL  D3DVS_SWIZZLE_SHIFT)
D3DVS_X_Z       EQU (2  SHL  D3DVS_SWIZZLE_SHIFT)
D3DVS_X_W       EQU (3  SHL  D3DVS_SWIZZLE_SHIFT)

;// The following bits define where to take component Y:

D3DVS_Y_X       EQU (0  SHL  (D3DVS_SWIZZLE_SHIFT + 2))
D3DVS_Y_Y       EQU (1  SHL  (D3DVS_SWIZZLE_SHIFT + 2))
D3DVS_Y_Z       EQU (2  SHL  (D3DVS_SWIZZLE_SHIFT + 2))
D3DVS_Y_W       EQU (3  SHL  (D3DVS_SWIZZLE_SHIFT + 2))

;// The following bits define where to take component Z:

D3DVS_Z_X       EQU (0  SHL  (D3DVS_SWIZZLE_SHIFT + 4))
D3DVS_Z_Y       EQU (1  SHL  (D3DVS_SWIZZLE_SHIFT + 4))
D3DVS_Z_Z       EQU (2  SHL  (D3DVS_SWIZZLE_SHIFT + 4))
D3DVS_Z_W       EQU (3  SHL  (D3DVS_SWIZZLE_SHIFT + 4))

;// The following bits define where to take component W:

D3DVS_W_X       EQU (0  SHL  (D3DVS_SWIZZLE_SHIFT + 6))
D3DVS_W_Y       EQU (1  SHL  (D3DVS_SWIZZLE_SHIFT + 6))
D3DVS_W_Z       EQU (2  SHL  (D3DVS_SWIZZLE_SHIFT + 6))
D3DVS_W_W       EQU (3  SHL  (D3DVS_SWIZZLE_SHIFT + 6))

;// Value when there is no swizzle (X is taken from X Y is taken from Y
;// Z is taken from Z W is taken from W
;//
D3DVS_NOSWIZZLE EQU (D3DVS_X_X  OR  D3DVS_Y_Y  OR  D3DVS_Z_Z  OR  D3DVS_W_W)

;// source parameter swizzle
D3DSP_SWIZZLE_SHIFT     EQU 16
D3DSP_SWIZZLE_MASK      EQU 000FF0000h

D3DSP_NOSWIZZLE \
    EQU ( (0  SHL  (D3DSP_SWIZZLE_SHIFT + 0))  OR  \
      (1  SHL  (D3DSP_SWIZZLE_SHIFT + 2))  OR  \
      (2  SHL  (D3DSP_SWIZZLE_SHIFT + 4))  OR  \
      (3  SHL  (D3DSP_SWIZZLE_SHIFT + 6)) )

;// pixel-shader swizzle ops
D3DSP_REPLICATEALPHA \
    EQU ( (3  SHL  (D3DSP_SWIZZLE_SHIFT + 0))  OR  \
      (3  SHL  (D3DSP_SWIZZLE_SHIFT + 2))  OR  \
      (3  SHL  (D3DSP_SWIZZLE_SHIFT + 4))  OR  \
      (3  SHL  (D3DSP_SWIZZLE_SHIFT + 6)) )

;// source parameter modifiers
D3DSP_SRCMOD_SHIFT      EQU 24
D3DSP_SRCMOD_MASK       EQU 00F000000h

D3DSHADER_PARAM_SRCMOD_TYPE EQU DWORD
;typedef enum _D3DSHADER_PARAM_SRCMOD_TYPE {
    D3DSPSM_NONE    EQU 0 SHL D3DSP_SRCMOD_SHIFT ;// nop
    D3DSPSM_NEG     EQU 1 SHL D3DSP_SRCMOD_SHIFT ;// negate
    D3DSPSM_BIAS    EQU 2 SHL D3DSP_SRCMOD_SHIFT ;// bias
    D3DSPSM_BIASNEG EQU 3 SHL D3DSP_SRCMOD_SHIFT ;// bias and negate
    D3DSPSM_SIGN    EQU 4 SHL D3DSP_SRCMOD_SHIFT ;// sign
    D3DSPSM_SIGNNEG EQU 5 SHL D3DSP_SRCMOD_SHIFT ;// sign and negate
    D3DSPSM_COMP    EQU 6 SHL D3DSP_SRCMOD_SHIFT ;// complement
    D3DSPSM_FORCE_DWORD EQU 07fffffffh        ;// force 32-bit size enum
;} D3DSHADER_PARAM_SRCMOD_TYPE;

;// pixel shader version token
D3DPS_VERSION MACRO _Major, _Minor
	local DefineAs
	DefineAs TEXTEQU %(0FFFF0000h OR ((_Major) SHL 8) OR (_Minor))
	EXITM DefineAs
ENDM D3DPS_VERSION

;// vertex shader version token
D3DVS_VERSION MACRO _Major, _Minor
	local DefineAs
	DefineAs TEXTEQU %(0FFFE0000h OR ((_Major) SHL 8) OR (_Minor))
	EXITM DefineAs
ENDM D3DVS_VERSION

;// extract major/minor from version cap
D3DSHADER_VERSION_MAJOR MACRO _Version
	local DefineAs
	DefineAs TEXTEQU %(((_Version) SHR 8) AND 0FFh)
	EXITM DefineAs
ENDM D3DSHADER_VERSION_MAJOR

D3DSHADER_VERSION_MINOR MACRO _Version
	local DefineAs
	DefineAs TEXTEQU %(((_Version) SHR 0) AND 0FFh)
	EXITM DefineAs
ENDM D3DSHADER_VERSION_MINOR

;// destination/source parameter register type
D3DSI_COMMENTSIZE_SHIFT     EQU 16
D3DSI_COMMENTSIZE_MASK      EQU 07FFF0000h
D3DSHADER_COMMENT MACRO _DWordSize
	local DefineAs
	DefineAs TEXTEQU %((((_DWordSize) SHL D3DSI_COMMENTSIZE_SHIFT) AND D3DSI_COMMENTSIZE_MASK) OR D3DSIO_COMMENT)
	EXITM DefineAs
ENDM D3DSHADER_COMMENT

;// pixel/vertex shader end token
D3DPS_END  EQU 00000FFFFh
D3DVS_END  EQU 00000FFFFh

;//---------------------------------------------------------------------

;// High order surfaces
;//
D3DBASISTYPE TYPEDEF DWORD
;typedef enum _D3DBASISTYPE {
   D3DBASIS_BEZIER      EQU 0
   D3DBASIS_BSPLINE     EQU 1
   D3DBASIS_INTERPOLATE EQU 2
   D3DBASIS_FORCE_DWORD EQU 07fffffffh
;} D3DBASISTYPE;

D3DORDERTYPE TYPEDEF DWORD
;typedef enum _D3DORDERTYPE {
   D3DORDER_LINEAR      EQU 1
   D3DORDER_CUBIC       EQU 3
   D3DORDER_QUINTIC     EQU 5
   D3DORDER_FORCE_DWORD EQU 07fffffffh
;} D3DORDERTYPE;

D3DPATCHEDGESTYLE TYPEDEF DWORD
;typedef enum _D3DPATCHEDGESTYLE {
   D3DPATCHEDGE_DISCRETE    EQU 0
   D3DPATCHEDGE_CONTINUOUS  EQU 1
   D3DPATCHEDGE_FORCE_DWORD EQU 07fffffffh
;} D3DPATCHEDGESTYLE;

D3DSTATEBLOCKTYPE TYPEDEF DWORD
;typedef enum _D3DSTATEBLOCKTYPE {
    D3DSBT_ALL           EQU 1 ;// capture all state
    D3DSBT_PIXELSTATE    EQU 2 ;// capture pixel state
    D3DSBT_VERTEXSTATE   EQU 3 ;// capture vertex state
    D3DSBT_FORCE_DWORD   EQU 07fffffffh
;} D3DSTATEBLOCKTYPE;

;// The D3DVERTEXBLENDFLAGS type is used with D3DRS_VERTEXBLEND state.
;//
D3DVERTEXBLENDFLAGS TYPEDEF DWORD
;typedef enum _D3DVERTEXBLENDFLAGS {
    D3DVBF_DISABLE  EQU 0     ;// Disable vertex blending
    D3DVBF_1WEIGHTS EQU 1     ;// 2 matrix blending
    D3DVBF_2WEIGHTS EQU 2     ;// 3 matrix blending
    D3DVBF_3WEIGHTS EQU 3     ;// 4 matrix blending
    D3DVBF_TWEENING EQU 255   ;// blending using D3DRS_TWEENFACTOR
    D3DVBF_0WEIGHTS EQU 256   ;// one matrix is used with weight 1.0
    D3DVBF_FORCE_DWORD EQU 07fffffffh ;// force 32-bit size enum
;} D3DVERTEXBLENDFLAGS;

D3DTEXTURETRANSFORMFLAGS TYPEDEF DWORD
;typedef enum _D3DTEXTURETRANSFORMFLAGS {
    D3DTTFF_DISABLE         EQU 0    ;// texture coordinates are passed directly
    D3DTTFF_COUNT1          EQU 1    ;// rasterizer should expect 1-D texture coords
    D3DTTFF_COUNT2          EQU 2    ;// rasterizer should expect 2-D texture coords
    D3DTTFF_COUNT3          EQU 3    ;// rasterizer should expect 3-D texture coords
    D3DTTFF_COUNT4          EQU 4    ;// rasterizer should expect 4-D texture coords
    D3DTTFF_PROJECTED       EQU 256  ;// texcoords to be divided by COUNTth element
    D3DTTFF_FORCE_DWORD     EQU 07fffffffh
;} D3DTEXTURETRANSFORMFLAGS;

;// Macros to set texture coordinate format bits in the FVF id

D3DFVF_TEXTUREFORMAT2 EQU 0         ;// Two floating point values
D3DFVF_TEXTUREFORMAT1 EQU 3         ;// One floating point value
D3DFVF_TEXTUREFORMAT3 EQU 1         ;// Three floating point values
D3DFVF_TEXTUREFORMAT4 EQU 2         ;// Four floating point values

D3DFVF_TEXCOORDSIZE3 MACRO CoordIndex
	local DefineAs
	DefineAs TEXTEQU %(D3DFVF_TEXTUREFORMAT3  SHL  (CoordIndex*2 + 16))
	EXITM DefineAs
ENDM D3DFVF_TEXTCOORDSIZE3

D3DFVF_TEXCOORDSIZE2 MACRO CoordIndex
	local DefineAs
	DefineAs TEXTEQU %(D3DFVF_TEXTUREFORMAT2)
	EXITM DefineAs
ENDM D3DFVF_TEXTCOORDSIZE2

D3DFVF_TEXCOORDSIZE4 MACRO CoordIndex
	local DefineAs
	DefineAs TEXTEQU %(D3DFVF_TEXTUREFORMAT4  SHL  (CoordIndex*2 + 16))
	EXITM DefineAs
ENDM D3DFVF_TEXTCOORDSIZE4

D3DFVF_TEXCOORDSIZE1 MACRO CoordIndex
	local DefineAs
	DefineAs TEXTEQU %(D3DFVF_TEXTUREFORMAT1  SHL  (CoordIndex*2 + 16))
	EXITM DefineAs
ENDM D3DFVF_TEXTCOORDSIZE1


;//---------------------------------------------------------------------

;/* Direct3D8 Device types */
D3DDEVTYPE TYPEDEF DWORD
;typedef enum _D3DDEVTYPE {
    D3DDEVTYPE_HAL         EQU 1
    D3DDEVTYPE_REF         EQU 2
    D3DDEVTYPE_SW          EQU 3

    D3DDEVTYPE_FORCE_DWORD  EQU 07fffffffh
;} D3DDEVTYPE;

;/* Multi-Sample buffer types */
D3DMULTISAMPLE_TYPE TYPEDEF DWORD
;typedef enum _D3DMULTISAMPLE_TYPE {
    D3DMULTISAMPLE_NONE            EQU  0
    D3DMULTISAMPLE_2_SAMPLES       EQU  2
    D3DMULTISAMPLE_3_SAMPLES       EQU  3
    D3DMULTISAMPLE_4_SAMPLES       EQU  4
    D3DMULTISAMPLE_5_SAMPLES       EQU  5
    D3DMULTISAMPLE_6_SAMPLES       EQU  6
    D3DMULTISAMPLE_7_SAMPLES       EQU  7
    D3DMULTISAMPLE_8_SAMPLES       EQU  8
    D3DMULTISAMPLE_9_SAMPLES       EQU  9
    D3DMULTISAMPLE_10_SAMPLES      EQU 10
    D3DMULTISAMPLE_11_SAMPLES      EQU 11
    D3DMULTISAMPLE_12_SAMPLES      EQU 12
    D3DMULTISAMPLE_13_SAMPLES      EQU 13
    D3DMULTISAMPLE_14_SAMPLES      EQU 14
    D3DMULTISAMPLE_15_SAMPLES      EQU 15
    D3DMULTISAMPLE_16_SAMPLES      EQU 16

    D3DMULTISAMPLE_FORCE_DWORD     EQU 07fffffffh
;} D3DMULTISAMPLE_TYPE;

;/* Formats
; * Most of these names have the following convention:
; *      A EQU Alpha
; *      R EQU Red
; *      G EQU Green
; *      B EQU Blue
; *      X EQU Unused Bits
; *      P EQU Palette
; *      L EQU Luminance
; *      U EQU dU coordinate for BumpMap
; *      V EQU dV coordinate for BumpMap
; *      S EQU Stencil
; *      D EQU Depth (e.g. Z or W buffer)
; *
; *      Further the order of the pieces are from MSB first; hence
; *      D3DFMT_A8L8 indicates that the high byte of this two byte
; *      format is alpha.
; *
; *      D16 indicates:
; *           - An integer 16-bit value.
; *           - An app-lockable surface.
; *
; *      All Depth/Stencil formats except D3DFMT_D16_LOCKABLE indicate:
; *          - no particular bit ordering per pixel and
; *          - are not app lockable and
; *          - the driver is allowed to consume more than the indicated
; *            number of bits per Depth channel (but not Stencil channel).
; */
MAKEFOURCC MACRO ch0, ch1, ch2, ch3
	LOCAL DefineAs
	DefineAs TEXTEQU %((DWORD)(BYTE)(ch0)  OR  ((DWORD)(BYTE)(ch1)  SHL  8)  OR        \
                ((DWORD)(BYTE)(ch2)  SHL  16)  OR  ((DWORD)(BYTE)(ch3)  SHL  24 ))
	EXITM DefineAs
ENDM MAKEFOURCC

D3DFORMAT TYPEDEF DWORD
;typedef enum _D3DFORMAT {
    D3DFMT_UNKNOWN              EQU  0

    D3DFMT_R8G8B8               EQU 20
    D3DFMT_A8R8G8B8             EQU 21
    D3DFMT_X8R8G8B8             EQU 22
    D3DFMT_R5G6B5               EQU 23
    D3DFMT_X1R5G5B5             EQU 24
    D3DFMT_A1R5G5B5             EQU 25
    D3DFMT_A4R4G4B4             EQU 26
    D3DFMT_R3G3B2               EQU 27
    D3DFMT_A8                   EQU 28
    D3DFMT_A8R3G3B2             EQU 29
    D3DFMT_X4R4G4B4             EQU 30

    D3DFMT_A8P8                 EQU 40
    D3DFMT_P8                   EQU 41

    D3DFMT_L8                   EQU 50
    D3DFMT_A8L8                 EQU 51
    D3DFMT_A4L4                 EQU 52

    D3DFMT_V8U8                 EQU 60
    D3DFMT_L6V5U5               EQU 61
    D3DFMT_X8L8V8U8             EQU 62
    D3DFMT_Q8W8V8U8             EQU 63
    D3DFMT_V16U16               EQU 64
    D3DFMT_W11V11U10            EQU 65

    D3DFMT_UYVY                 EQU MAKEFOURCC 'U', 'Y', 'V', 'Y'
    D3DFMT_YUY2                 EQU MAKEFOURCC 'Y', 'U', 'Y', '2'
    D3DFMT_DXT1                 EQU MAKEFOURCC 'D', 'X', 'T', '1'
    D3DFMT_DXT2                 EQU MAKEFOURCC 'D', 'X', 'T', '2'
    D3DFMT_DXT3                 EQU MAKEFOURCC 'D', 'X', 'T', '3'
    D3DFMT_DXT4                 EQU MAKEFOURCC 'D', 'X', 'T', '4'
    D3DFMT_DXT5                 EQU MAKEFOURCC 'D', 'X', 'T', '5'

    D3DFMT_D16_LOCKABLE         EQU 70
    D3DFMT_D32                  EQU 71
    D3DFMT_D15S1                EQU 73
    D3DFMT_D24S8                EQU 75
    D3DFMT_D16                  EQU 80
    D3DFMT_D24X8                EQU 77
    D3DFMT_D24X4S4              EQU 79


    D3DFMT_VERTEXDATA           EQU 100
    D3DFMT_INDEX16              EQU 101
    D3DFMT_INDEX32              EQU 102

    D3DFMT_FORCE_DWORD          EQU 07fffffffh
;} D3DFORMAT;

;/* Display Modes */
D3DDISPLAYMODE STRUCT
    _Width			DWORD ?
    Height			DWORD ?
    RefreshRate	DWORD ?
    Format			D3DFORMAT ?
D3DDISPLAYMODE ENDS

;/* Creation Parameters */
D3DDEVICE_CREATION_PARAMETERS STRUCT
    AdapterOrdinal	UINT ?
    DeviceType			D3DDEVTYPE ?
    hFocusWindow		HWND ?
    BehaviorFlags		DWORD ?
D3DDEVICE_CREATION_PARAMETERS ENDS


;/* SwapEffects */
D3DSWAPEFFECT TYPEDEF DWORD
;typedef enum _D3DSWAPEFFECT {
    D3DSWAPEFFECT_DISCARD           EQU 1
    D3DSWAPEFFECT_FLIP              EQU 2
    D3DSWAPEFFECT_COPY              EQU 3
    D3DSWAPEFFECT_COPY_VSYNC        EQU 4

    D3DSWAPEFFECT_FORCE_DWORD       EQU 07fffffffh
;} D3DSWAPEFFECT;

;/* Pool types */
D3DPOOL TYPEDEF DWORD
;typedef enum _D3DPOOL {
    D3DPOOL_DEFAULT                 EQU 0
    D3DPOOL_MANAGED                 EQU 1
    D3DPOOL_SYSTEMMEM               EQU 2

    D3DPOOL_FORCE_DWORD             EQU 07fffffffh
;} D3DPOOL;


;/* RefreshRate pre-defines */
D3DPRESENT_RATE_DEFAULT         EQU 000000000h
D3DPRESENT_RATE_UNLIMITED       EQU 07fffffffh


;/* Resize Optional Parameters */
D3DPRESENT_PARAMETERS STRUCT
    BackBufferWidth	UINT ?
    BackBufferHeight	UINT ?
    BackBufferFormat	D3DFORMAT ?
    BackBufferCount	UINT ?

    MultiSampleType	D3DMULTISAMPLE_TYPE ?

    SwapEffect			D3DSWAPEFFECT ?
    hDeviceWindow		HWND ?
    Windowed			BOOL ?
    EnableAutoDepthStencil	BOOL ?
    AutoDepthStencilFormat	D3DFORMAT ?
    Flags				DWORD ?

    ;/* Following elements must be zero for Windowed mode */
    FullScreen_RefreshRateInHz		UINT ?
    FullScreen_PresentationInterval	UINT ?

D3DPRESENT_PARAMETERS ENDS

;// Values for D3DPRESENT_PARAMETERS.Flags

D3DPRESENTFLAG_LOCKABLE_BACKBUFFER  EQU 000000001h


;/* Gamma Ramp: Same as DX7 */

D3DGAMMARAMP STRUCT
    red  	WORD 256 DUP (?)
    green	WORD 256 DUP (?)
    blue		WORD 256 DUP (?)
D3DGAMMARAMP ENDS

;/* Back buffer types */
D3DBACKBUFFER_TYPE TYPEDEF DWORD
;typedef enum _D3DBACKBUFFER_TYPE {
    D3DBACKBUFFER_TYPE_MONO         EQU 0
    D3DBACKBUFFER_TYPE_LEFT         EQU 1
    D3DBACKBUFFER_TYPE_RIGHT        EQU 2

    D3DBACKBUFFER_TYPE_FORCE_DWORD  EQU 07fffffffh
;} D3DBACKBUFFER_TYPE;


;/* Types */
D3DRESOURCETYPE TYPEDEF DWORD
;typedef enum _D3DRESOURCETYPE {
    D3DRTYPE_SURFACE                EQU  1
    D3DRTYPE_VOLUME                 EQU  2
    D3DRTYPE_TEXTURE                EQU  3
    D3DRTYPE_VOLUMETEXTURE          EQU  4
    D3DRTYPE_CUBETEXTURE            EQU  5
    D3DRTYPE_VERTEXBUFFER           EQU  6
    D3DRTYPE_INDEXBUFFER            EQU  7

    D3DRTYPE_FORCE_DWORD            EQU 07fffffffh
;} D3DRESOURCETYPE;

;/* Usages */
D3DUSAGE_RENDERTARGET       EQU (000000001h)
D3DUSAGE_DEPTHSTENCIL       EQU (000000002h)

;/* Usages for Vertex/Index buffers */
D3DUSAGE_WRITEONLY          EQU (000000008h)
D3DUSAGE_SOFTWAREPROCESSING EQU (000000010h)
D3DUSAGE_DONOTCLIP          EQU (000000020h)
D3DUSAGE_POINTS             EQU (000000040h)
D3DUSAGE_RTPATCHES          EQU (000000080h)
D3DUSAGE_NPATCHES           EQU (000000100h)
D3DUSAGE_DYNAMIC            EQU (000000200h)









;/* CubeMap Face identifiers */
D3DCUBEMAP_FACES TYPEDEF DWORD
;typedef enum _D3DCUBEMAP_FACES {
    D3DCUBEMAP_FACE_POSITIVE_X     EQU 0
    D3DCUBEMAP_FACE_NEGATIVE_X     EQU 1
    D3DCUBEMAP_FACE_POSITIVE_Y     EQU 2
    D3DCUBEMAP_FACE_NEGATIVE_Y     EQU 3
    D3DCUBEMAP_FACE_POSITIVE_Z     EQU 4
    D3DCUBEMAP_FACE_NEGATIVE_Z     EQU 5

    D3DCUBEMAP_FACE_FORCE_DWORD    EQU 07fffffffh
;} D3DCUBEMAP_FACES;


;/* Lock flags */

D3DLOCK_READONLY           EQU 000000010h
D3DLOCK_DISCARD            EQU 000002000h
D3DLOCK_NOOVERWRITE        EQU 000001000h
D3DLOCK_NOSYSLOCK          EQU 000000800h

D3DLOCK_NO_DIRTY_UPDATE    EQU 000008000h






;/* Vertex Buffer Description */
D3DVERTEXBUFFER_DESC STRUCT
    Format	D3DFORMAT ?
    _Type		D3DRESOURCETYPE ?
    Usage	DWORD ?
    Pool		D3DPOOL ?
    _Size		UINT ?

    FVF		DWORD ?
D3DVERTEXBUFFER_DESC ENDS

;/* Index Buffer Description */
D3DINDEXBUFFER_DESC STRUCT
    Format	D3DFORMAT ?
    _Type		D3DRESOURCETYPE ?
    Usage	DWORD ?
    Pool		D3DPOOL ?
    _Size		UINT ?
D3DINDEXBUFFER_DESC ENDS


;/* Surface Description */
D3DSURFACE_DESC STRUCT
    Format	D3DFORMAT ?
    _Type		D3DRESOURCETYPE ?
    Usage	DWORD ?
    Pool		D3DPOOL ?
    _Size		UINT ?

    MultiSampleType	D3DMULTISAMPLE_TYPE ?
    _Width	UINT ?
    Height	UINT ?
D3DSURFACE_DESC ENDS

D3DVOLUME_DESC STRUCT
    Format		D3DFORMAT ?
    _Type			D3DRESOURCETYPE ?
    Usage		DWORD ?
    Pool			D3DPOOL ?
    _Size			UINT ?


    _Width		UINT ?
    Height		UINT ?
    Depth		UINT ?
D3DVOLUME_DESC ENDS

;/* Structure for LockRect */
D3DLOCKED_RECT STRUCT
    Pitch	DWORD ?
    pBits	DWORD ?
D3DLOCKED_RECT ENDS

;/* Structures for LockBox */
D3DBOX STRUCT
    Left		UINT ?
    Top		UINT ?
    Right	UINT ?
    Bottom	UINT ?
    Front	UINT ?
    Back		UINT ?
D3DBOX ENDS

D3DLOCKED_BOX STRUCT
    RowPitch	DWORD ?
    SlicePitch	DWORD ?
    pBits		DWORD ?
D3DLOCKED_BOX ENDS

;/* Structures for LockRange */
D3DRANGE STRUCT
    _Offset	UINT ?
    _Size		UINT ?
D3DRANGE ENDS

;/* Structures for high order primitives */
D3DRECTPATCH_INFO STRUCT
    StartVertexOffsetWidth		UINT ?
    StartVertexOffsetHeight	UINT ?
    _Width							UINT ?
    Height							UINT ?
    Stride							UINT ?
    Basis							D3DBASISTYPE ?
    Order							D3DORDERTYPE ?
D3DRECTPATCH_INFO ENDS

D3DTRIPATCH_INFO STRUCT
    StartVertexOffset	UINT ?
    NumVertices			UINT ?
    Basis					D3DBASISTYPE ?
    Order					D3DORDERTYPE ?
D3DTRIPATCH_INFO ENDS

;/* Adapter Identifier */

MAX_DEVICE_IDENTIFIER_STRING        EQU 512
D3DADAPTER_IDENTIFIER8 STRUCT
    Driver			BYTE MAX_DEVICE_IDENTIFIER_STRING DUP (?)
    Description	BYTE MAX_DEVICE_IDENTIFIER_STRING DUP (?)

    DriverVersion QWORD ?            ;/* Defined for 32 bit components */

    VendorId	DWORD ?
    DeviceId	DWORD ?
    SubSysId	DWORD ?
    Revision	DWORD ?

    DeviceIdentifier	GUID <?>

    WHQLLevel	DWORD ?

D3DADAPTER_IDENTIFIER8 ENDS


;/* Raster Status structure returned by GetRasterStatus */
D3DRASTER_STATUS STRUCT
    InVBlank	BOOL ?
    ScanLine	UINT ?
D3DRASTER_STATUS ENDS



;/* Debug monitor tokens (DEBUG only)
;
;   Note that if D3DRS_DEBUGMONITORTOKEN is set the call is treated as
;   passing a token to the debug monitor.  For example if after passing
;   D3DDMT_ENABLE/DISABLE to D3DRS_DEBUGMONITORTOKEN other token values
;   are passed in the enabled/disabled state of the debug
;   monitor will still persist.
;
;   The debug monitor defaults to enabled.
;
;   Calling GetRenderState on D3DRS_DEBUGMONITORTOKEN is not of any use.
;*/
D3DDEBUGMONITORTOKENS TYPEDEF DWORD
;typedef enum _D3DDEBUGMONITORTOKENS {
    D3DDMT_ENABLE          EQU 0    ;// enable debug monitor
    D3DDMT_DISABLE         EQU 1    ;// disable debug monitor
    D3DDMT_FORCE_DWORD     EQU 07fffffffh
;} D3DDEBUGMONITORTOKENS;


;
;;#pragma pack()
;;#pragma warning(default:4201)

;#endif /* (DIRECT3D_VERSION >= 0x0800) */
ENDIF ;_D3D8TYPES_INC_

