;/*==========================================================================;
; *
; *  Copyright (C) 1995-2000 Microsoft Corporation.  All Rights Reserved.
; *
; *  File:       d3d8caps.h
; *  Content:    Direct3D capabilities include file
; *
; ***************************************************************************/

IFNDEF _D3D8CAPS_INC_
_D3D8CAPS_INC_=1

IFNDEF DIRECT3D_VERSION
DIRECT3D_VERSION 	EQU	0800h
ENDIF   ;DIRECT3D_VERSION

;// include this file content only if compiling for DX8 interfaces
;#if(DIRECT3D_VERSION >= 0x0800)

;#pragma pack(4)

_D3DCAPS8   	       STRUCT 4t
;{
    ;/* Device Info */
    DeviceType                  D3DDEVTYPE  ?
    AdapterOrdinal              UINT        ?

    ;/* Caps from DX7 Draw */
    Caps                        DWORD       ?
    Caps2                       DWORD       ?
    Caps3                       DWORD       ?
    PresentationIntervals       DWORD       ?

    ;/* Cursor Caps */
    CursorCaps                  DWORD       ?

    ;/* 3D Device Caps */
    DevCaps                     DWORD       ?

    PrimitiveMiscCaps           DWORD       ?
    RasterCaps                  DWORD       ?
    ZCmpCaps                    DWORD       ?
    SrcBlendCaps                DWORD       ?
    DestBlendCaps               DWORD       ?
    AlphaCmpCaps                DWORD       ?
    ShadeCaps                   DWORD       ?
    TextureCaps                 DWORD       ?
    TextureFilterCaps           DWORD       ?   ;// D3DPTFILTERCAPS for IDirect3DTexture8's
    CubeTextureFilterCaps       DWORD       ?   ;// D3DPTFILTERCAPS for IDirect3DCubeTexture8's
    VolumeTextureFilterCaps     DWORD       ?   ;// D3DPTFILTERCAPS for IDirect3DVolumeTexture8's
    TextureAddressCaps          DWORD       ?   ;// D3DPTADDRESSCAPS for IDirect3DTexture8's
    VolumeTextureAddressCaps    DWORD       ?   ;// D3DPTADDRESSCAPS for IDirect3DVolumeTexture8's

    LineCaps                    DWORD       ?   ;// D3DLINECAPS

    MaxTextureWidth             DWORD       ?
    MaxTextureHeight            DWORD       ?
    MaxVolumeExtent             DWORD       ?

    MaxTextureRepeat            DWORD       ?
    MaxTextureAspectRatio       DWORD       ?
    MaxAnisotropy               DWORD       ?
    MaxVertexW                  FLOAT       ?

    GuardBandLeft               FLOAT       ?
    GuardBandTop                FLOAT       ?
    GuardBandRight              FLOAT       ?
    GuardBandBottom             FLOAT       ?

    ExtentsAdjust               FLOAT       ?
    StencilCaps                 DWORD       ?

    FVFCaps                     DWORD       ?
    TextureOpCaps               DWORD       ?
    MaxTextureBlendStages       DWORD       ?
    MaxSimultaneousTextures     DWORD       ?

    VertexProcessingCaps        DWORD       ?
    MaxActiveLights             DWORD       ?
    MaxUserClipPlanes           DWORD       ?
    MaxVertexBlendMatrices      DWORD       ?
    MaxVertexBlendMatrixIndex   DWORD       ?

    MaxPointSize                FLOAT       ?

    MaxPrimitiveCount           DWORD       ?   ;// max number of primitives per DrawPrimitive call
    MaxVertexIndex              DWORD       ?
    MaxStreams                  DWORD       ?
    MaxStreamStride             DWORD       ?   ;// max stride for SetStreamSource

    VertexShaderVersion         DWORD       ?
    MaxVertexShaderConst        DWORD       ?   ;// number of vertex shader constant registers

    PixelShaderVersion          DWORD       ?
    MaxPixelShaderValue         FLOAT       ?   ;// max value of pixel shader arithmetic component

;} D3DCAPS8;
_D3DCAPS8           ENDS

D3DCAPS8            TYPEDEF     _D3DCAPS8
;//
;// BIT DEFINES FOR D3DCAPS8 DWORD MEMBERS
;//

;//
;// Caps
;//
D3DCAPS_READ_SCANLINE               EQU     020000h     ;0x00020000L

;//
;// Caps2
;//
D3DCAPS2_NO2DDURING3DSCENE          EQU     2           ;0000002L
D3DCAPS2_FULLSCREENGAMMA            EQU     20000       ;0020000L
D3DCAPS2_CANRENDERWINDOWED          EQU     80000       ;0080000L
D3DCAPS2_CANCALIBRATEGAMMA          EQU     100000      ;0100000L
D3DCAPS2_RESERVED                   EQU     2000000     ;2000000L

;//
;// Caps3
;//
D3DCAPS3_RESERVED                   EQU     08000001h     ;0x8000001fL

;//
;// PresentationIntervals
;//
D3DPRESENT_INTERVAL_DEFAULT         EQU     0            ;0000000L
D3DPRESENT_INTERVAL_ONE             EQU     1            ;0000001L
D3DPRESENT_INTERVAL_TWO             EQU     2            ;0000002L
D3DPRESENT_INTERVAL_THREE           EQU     4            ;0000004L
D3DPRESENT_INTERVAL_FOUR            EQU     8            ;0000008L
D3DPRESENT_INTERVAL_IMMEDIATE       EQU     080000000h   ;0x80000000L

;//
;// CursorCaps
;//
;// Driver supports HW color cursor in at least hi-res modes(height >=400)
D3DCURSORCAPS_COLOR                 EQU     1            ;0000001L
;// Driver supports HW cursor also in low-res modes(height < 400)
D3DCURSORCAPS_LOWRES                EQU     2            ;0000002L

;//
;// DevCaps
;//
D3DDEVCAPS_EXECUTESYSTEMMEMORY      EQU     10h             ;0x00000010L /* Device can use execute buffers from system memory */
D3DDEVCAPS_EXECUTEVIDEOMEMORY       EQU     20              ;0000020L /* Device can use execute buffers from video memory */
D3DDEVCAPS_TLVERTEXSYSTEMMEMORY     EQU     40h             ;0x00000040L /* Device can use TL buffers from system memory */
D3DDEVCAPS_TLVERTEXVIDEOMEMORY      EQU     80h             ;0x00000080L /* Device can use TL buffers from video memory */
D3DDEVCAPS_TEXTURESYSTEMMEMORY      EQU     100h            ;0x00000100L /* Device can texture from system memory */
D3DDEVCAPS_TEXTUREVIDEOMEMORY       EQU     200             ;0000200L /* Device can texture from device memory */
D3DDEVCAPS_DRAWPRIMTLVERTEX         EQU     400             ;0000400L /* Device can draw TLVERTEX primitives */
D3DDEVCAPS_CANRENDERAFTERFLIP       EQU     800             ;0000800L /* Device can render without waiting for flip to complete */
D3DDEVCAPS_TEXTURENONLOCALVIDMEM    EQU     1000h           ;0x00001000L /* Device can texture from nonlocal video memory */
D3DDEVCAPS_DRAWPRIMITIVES2          EQU     2000            ;0002000L /* Device can support DrawPrimitives2 */
D3DDEVCAPS_SEPARATETEXTUREMEMORIES  EQU     4000h           ;0x00004000L /* Device is texturing from separate memory pools */
D3DDEVCAPS_DRAWPRIMITIVES2EX        EQU     8000            ;0008000L /* Device can support Extended DrawPrimitives2 i.e. DX7 compliant driver*/
D3DDEVCAPS_HWTRANSFORMANDLIGHT      EQU     10000h          ;0x00010000L /* Device can support transformation and lighting in hardware and DRAWPRIMITIVES2EX must be also */
D3DDEVCAPS_CANBLTSYSTONONLOCAL      EQU     20000h          ;0x00020000L /* Device supports a Tex Blt from system memory to non-local vidmem */
D3DDEVCAPS_HWRASTERIZATION          EQU     80000           ;0080000L /* Device has HW acceleration for rasterization */
D3DDEVCAPS_PUREDEVICE               EQU     100000          ;0100000L /* Device supports D3DCREATE_PUREDEVICE */
D3DDEVCAPS_QUINTICRTPATCHES         EQU     200000          ;0200000L /* Device supports quintic Beziers and BSplines */
D3DDEVCAPS_RTPATCHES                EQU     400000          ;0400000L /* Device supports Rect and Tri patches */
D3DDEVCAPS_RTPATCHHANDLEZERO        EQU     800000          ;0800000L /* Indicates that RT Patches may be drawn efficiently using handle 0 */
D3DDEVCAPS_NPATCHES                 EQU     1000000         ;1000000L /* Device supports N-Patches */

;//
;// PrimitiveMiscCaps
;//
D3DPMISCCAPS_MASKZ                  EQU     2               ;0000002L
D3DPMISCCAPS_LINEPATTERNREP         EQU     4               ;0000004L
D3DPMISCCAPS_CULLNONE               EQU     10              ;0000010L
D3DPMISCCAPS_CULLCW                 EQU     20              ;0000020L
D3DPMISCCAPS_CULLCCW                EQU     40              ;0000040L
D3DPMISCCAPS_COLORWRITEENABLE       EQU     80              ;0000080L
D3DPMISCCAPS_CLIPPLANESCALEDPOINTS  EQU     100h            ;0x00000100L /* Device correctly clips scaled points to clip planes */
D3DPMISCCAPS_CLIPTLVERTS            EQU     200             ;0000200L /* device will clip post-transformed vertex primitives */
D3DPMISCCAPS_TSSARGTEMP             EQU     400             ;0000400L /* device supports D3DTA_TEMP for temporary register */
D3DPMISCCAPS_BLENDOP                EQU     800             ;0000800L /* device supports D3DRS_BLENDOP */

;//
;// LineCaps
;//
D3DLINECAPS_TEXTURE                 EQU     1               ;0000001L
D3DLINECAPS_ZTEST                   EQU     2               ;0000002L
D3DLINECAPS_BLEND                   EQU     4               ;0000004L
D3DLINECAPS_ALPHACMP                EQU     8               ;0000008L
D3DLINECAPS_FOG                     EQU     10              ;0000010L

;//
;// RasterCaps
;//
D3DPRASTERCAPS_DITHER                   EQU     1           ;0000001L
D3DPRASTERCAPS_PAT                      EQU     8           ;0000008L
D3DPRASTERCAPS_ZTEST                    EQU     10          ;0000010L
D3DPRASTERCAPS_FOGVERTEX                EQU     80          ;0000080L
D3DPRASTERCAPS_FOGTABLE                 EQU     100         ;0000100L
D3DPRASTERCAPS_ANTIALIASEDGES           EQU     1000        ;0001000L
D3DPRASTERCAPS_MIPMAPLODBIAS            EQU     2000        ;0002000L
D3DPRASTERCAPS_ZBIAS                    EQU     4000        ;0004000L
D3DPRASTERCAPS_ZBUFFERLESSHSR           EQU     8000        ;0008000L
D3DPRASTERCAPS_FOGRANGE                 EQU     10000       ;0010000L
D3DPRASTERCAPS_ANISOTROPY               EQU     20000       ;0020000L
D3DPRASTERCAPS_WBUFFER                  EQU     40000       ;0040000L
D3DPRASTERCAPS_WFOG                     EQU     100000      ;0100000L
D3DPRASTERCAPS_ZFOG                     EQU     200000      ;0200000L
D3DPRASTERCAPS_COLORPERSPECTIVE         EQU     400000h     ;0x00400000L /* Device iterates colors perspective correct */
D3DPRASTERCAPS_STRETCHBLTMULTISAMPLE    EQU     800000h     ;0x00800000L

;//
;// ZCmpCaps, AlphaCmpCaps
;//
D3DPCMPCAPS_NEVER                       EQU     1           ;0000001L
D3DPCMPCAPS_LESS                        EQU     2           ;0000002L
D3DPCMPCAPS_EQUAL                       EQU     4           ;0000004L
D3DPCMPCAPS_LESSEQUAL                   EQU     8           ;0000008L
D3DPCMPCAPS_GREATER                     EQU     10          ;0000010L
D3DPCMPCAPS_NOTEQUAL                    EQU     20          ;0000020L
D3DPCMPCAPS_GREATEREQUAL                EQU     40          ;0000040L
D3DPCMPCAPS_ALWAYS                      EQU     80          ;0000080L

;//
;// SourceBlendCaps, DestBlendCaps
;//
D3DPBLENDCAPS_ZERO                      EQU     1           ;0000001L
D3DPBLENDCAPS_ONE                       EQU     2           ;0000002L
D3DPBLENDCAPS_SRCCOLOR                  EQU     4           ;0000004L
D3DPBLENDCAPS_INVSRCCOLOR               EQU     8           ;0000008L
D3DPBLENDCAPS_SRCALPHA                  EQU     10          ;0000010L
D3DPBLENDCAPS_INVSRCALPHA               EQU     20          ;0000020L
D3DPBLENDCAPS_DESTALPHA                 EQU     40          ;0000040L
D3DPBLENDCAPS_INVDESTALPHA              EQU     80          ;0000080L
D3DPBLENDCAPS_DESTCOLOR                 EQU     100         ;0000100L
D3DPBLENDCAPS_INVDESTCOLOR              EQU     200         ;0000200L
D3DPBLENDCAPS_SRCALPHASAT               EQU     400         ;0000400L
D3DPBLENDCAPS_BOTHSRCALPHA              EQU     800         ;0000800L
D3DPBLENDCAPS_BOTHINVSRCALPHA           EQU     1000        ;0001000L

;//
;// ShadeCaps
;//
D3DPSHADECAPS_COLORGOURAUDRGB           EQU     8           ;0000008L
D3DPSHADECAPS_SPECULARGOURAUDRGB        EQU     200         ;0000200L
D3DPSHADECAPS_ALPHAGOURAUDBLEND         EQU     400         ;0004000L
D3DPSHADECAPS_FOGGOURAUD                EQU     80000       ;0080000L

;//
;// TextureCaps
;//
D3DPTEXTURECAPS_PERSPECTIVE             EQU     1           ;0000001L /* Perspective-correct texturing is supported */
D3DPTEXTURECAPS_POW2                    EQU     2           ;0000002L /* Power-of-2 texture dimensions are required - applies to non-Cube/Volume textures only. */
D3DPTEXTURECAPS_ALPHA                   EQU     4           ;0000004L /* Alpha in texture pixels is supported */
D3DPTEXTURECAPS_SQUAREONLY              EQU     20          ;0000020L /* Only square textures are supported */
D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE    EQU     40h     ;0x00000040L /* Texture indices are not scaled by the texture size prior to interpolation */
D3DPTEXTURECAPS_ALPHAPALETTE            EQU     80          ;0000080L /* Device can draw alpha from texture palettes */
;// Device can use non-POW2 textures if:
;//  1) D3DTEXTURE_ADDRESS is set to CLAMP for this texture's stage
;//  2) D3DRS_WRAP(N) is zero for this texture's coordinates
;//  3) mip mapping is not enabled (use magnification filter only)
D3DPTEXTURECAPS_NONPOW2CONDITIONAL      EQU     100h        ;0x00000100L
D3DPTEXTURECAPS_PROJECTED               EQU     400         ;0000400L /* Device can do D3DTTFF_PROJECTED */
D3DPTEXTURECAPS_CUBEMAP                 EQU     800         ;0000800L /* Device can do cubemap textures */
D3DPTEXTURECAPS_VOLUMEMAP               EQU     2000        ;0002000L /* Device can do volume textures */
D3DPTEXTURECAPS_MIPMAP                  EQU     4000        ;0004000L /* Device can do mipmapped textures */
D3DPTEXTURECAPS_MIPVOLUMEMAP            EQU     8000        ;0008000L /* Device can do mipmapped volume textures */
D3DPTEXTURECAPS_MIPCUBEMAP              EQU     10000       ;0010000L /* Device can do mipmapped cube maps */
D3DPTEXTURECAPS_CUBEMAP_POW2            EQU     20000       ;0020000L /* Device requires that cubemaps be power-of-2 dimension */
D3DPTEXTURECAPS_VOLUMEMAP_POW2          EQU     40000       ;0040000L /* Device requires that volume maps be power-of-2 dimension */

;//
;// TextureFilterCaps
;//
D3DPTFILTERCAPS_MINFPOINT               EQU     100         ;0000100L /* Min Filter */
D3DPTFILTERCAPS_MINFLINEAR              EQU     200         ;0000200L
D3DPTFILTERCAPS_MINFANISOTROPIC         EQU     400         ;0000400L
D3DPTFILTERCAPS_MIPFPOINT               EQU     10000       ;0010000L /* Mip Filter */
D3DPTFILTERCAPS_MIPFLINEAR              EQU     20000       ;0020000L
D3DPTFILTERCAPS_MAGFPOINT               EQU     1000000     ;1000000L /* Mag Filter */
D3DPTFILTERCAPS_MAGFLINEAR              EQU     2000000     ;2000000L
D3DPTFILTERCAPS_MAGFANISOTROPIC         EQU     4000000     ;4000000L
D3DPTFILTERCAPS_MAGFAFLATCUBIC          EQU     8000000     ;8000000L
D3DPTFILTERCAPS_MAGFGAUSSIANCUBIC       EQU     10000000h   ;0x10000000L

;//
;// TextureAddressCaps
;//
D3DPTADDRESSCAPS_WRAP                   EQU     1           ;0000001L
D3DPTADDRESSCAPS_MIRROR                 EQU     2           ;0000002L
D3DPTADDRESSCAPS_CLAMP                  EQU     4           ;0000004L
D3DPTADDRESSCAPS_BORDER                 EQU     8           ;0000008L
D3DPTADDRESSCAPS_INDEPENDENTUV          EQU     10h         ;0x00000010L
D3DPTADDRESSCAPS_MIRRORONCE             EQU     20          ;0000020L

;//
;// StencilCaps
;//
D3DSTENCILCAPS_KEEP                     EQU     1           ;0000001L
D3DSTENCILCAPS_ZERO                     EQU     2           ;0000002L
D3DSTENCILCAPS_REPLACE                  EQU     4           ;0000004L
D3DSTENCILCAPS_INCRSAT                  EQU     8           ;0000008L
D3DSTENCILCAPS_DECRSAT                  EQU     10          ;0000010L
D3DSTENCILCAPS_INVERT                   EQU     20          ;0000020L
D3DSTENCILCAPS_INCR                     EQU     40          ;0000040L
D3DSTENCILCAPS_DECR                     EQU     80          ;0000080L

;//
;// TextureOpCaps
;//
D3DTEXOPCAPS_DISABLE                    EQU     1           ;0000001L
D3DTEXOPCAPS_SELECTARG1                 EQU     2           ;0000002L
D3DTEXOPCAPS_SELECTARG2                 EQU     4           ;0000004L
D3DTEXOPCAPS_MODULATE                   EQU     8           ;0000008L
D3DTEXOPCAPS_MODULATE2X                 EQU     10          ;0000010L
D3DTEXOPCAPS_MODULATE4X                 EQU     20          ;0000020L
D3DTEXOPCAPS_ADD                        EQU     40          ;0000040L
D3DTEXOPCAPS_ADDSIGNED                  EQU     80          ;0000080L
D3DTEXOPCAPS_ADDSIGNED2X                EQU     100         ;0000100L
D3DTEXOPCAPS_SUBTRACT                   EQU     200         ;0000200L
D3DTEXOPCAPS_ADDSMOOTH                  EQU     400         ;0000400L
D3DTEXOPCAPS_BLENDDIFFUSEALPHA          EQU     800         ;0000800L
D3DTEXOPCAPS_BLENDTEXTUREALPHA          EQU     1000        ;0001000L
D3DTEXOPCAPS_BLENDFACTORALPHA           EQU     2000        ;0002000L
D3DTEXOPCAPS_BLENDTEXTUREALPHAPM        EQU     4000        ;0004000L
D3DTEXOPCAPS_BLENDCURRENTALPHA          EQU     8000        ;0008000L
D3DTEXOPCAPS_PREMODULATE                EQU     10000       ;0010000L
D3DTEXOPCAPS_MODULATEALPHA_ADDCOLOR     EQU     20000       ;0020000L
D3DTEXOPCAPS_MODULATECOLOR_ADDALPHA     EQU     40000       ;0040000L
D3DTEXOPCAPS_MODULATEINVALPHA_ADDCOLOR  EQU     80000h      ;0x00080000L
D3DTEXOPCAPS_MODULATEINVCOLOR_ADDALPHA  EQU     100000h     ;0x00100000L
D3DTEXOPCAPS_BUMPENVMAP                 EQU     200000      ;0200000L
D3DTEXOPCAPS_BUMPENVMAPLUMINANCE        EQU     400000      ;0400000L
D3DTEXOPCAPS_DOTPRODUCT3                EQU     800000      ;0800000L
D3DTEXOPCAPS_MULTIPLYADD                EQU     1000000     ;1000000L
D3DTEXOPCAPS_LERP                       EQU     2000000     ;2000000L

;//
;// FVFCaps
;//
D3DFVFCAPS_TEXCOORDCOUNTMASK            EQU     0ffffh       ;000ffffL /* mask for texture coordinate count field */
D3DFVFCAPS_DONOTSTRIPELEMENTS           EQU     80000       ;0080000L /* Device prefers that vertex elements not be stripped */
D3DFVFCAPS_PSIZE                        EQU     100000      ;0100000L /* Device can receive point size */

;//
;// VertexProcessingCaps
;//
D3DVTXPCAPS_TEXGEN                      EQU     1           ;0000001L /* device can do texgen */
D3DVTXPCAPS_MATERIALSOURCE7             EQU     2           ;0000002L /* device can do DX7-level colormaterialsource ops */
D3DVTXPCAPS_DIRECTIONALLIGHTS           EQU     8           ;0000008L /* device can do directional lights */
D3DVTXPCAPS_POSITIONALLIGHTS            EQU     10          ;0000010L /* device can do positional lights (includes point and spot) */
D3DVTXPCAPS_LOCALVIEWER                 EQU     20          ;0000020L /* device can do local viewer */
D3DVTXPCAPS_TWEENING                    EQU     40          ;0000040L /* device can do vertex tweening */
D3DVTXPCAPS_NO_VSDT_UBYTE4              EQU     80          ;0000080L /* device does not support D3DVSDT_UBYTE4 */

;#pragma pack()

;#endif /* (DIRECT3D_VERSION >= 0x0800) */
ENDIF ;//_D3D8CAPS_INC_

