; Direct3D 8 include file for MASM
; /Mic, 2003

; This is not complete. A lot of stuff is missing.


include \masm32\include\windows.inc  



DIRECT3D_VERSION	EQU 800h


; This identifier is passed to Direct3DCreate8 in order to ensure that an
; application was built against the correct header files. This number is
; incremented whenever a header (or other) change would require applications
; to be rebuilt. If the version doesn't match, Direct3DCreate8 will fail.
; (The number itself has no meaning.)
 
 D3D_SDK_VERSION 	EQU 220


;****************************************************************************
;*
;* Flags for IDirect3D8::CreateDevice's BehaviorFlags
;*
;***************************************************************************

D3DCREATE_FPU_PRESERVE                  EQU 00000002h
D3DCREATE_MULTITHREADED                 EQU 00000004h

D3DCREATE_PUREDEVICE                    EQU 00000010h
D3DCREATE_SOFTWARE_VERTEXPROCESSING     EQU 00000020h
D3DCREATE_HARDWARE_VERTEXPROCESSING     EQU 00000040h
D3DCREATE_MIXED_VERTEXPROCESSING        EQU 00000080h

D3DCREATE_DISABLE_DRIVER_MANAGEMENT     EQU 00000100h


;****************************************************************************
;*
;* Parameter for IDirect3D8::CreateDevice's iAdapter
;*
;****************************************************************************

D3DADAPTER_DEFAULT	EQU 0



; Device types
D3DDEVTYPE_HAL         EQU 1
D3DDEVTYPE_REF         EQU 2
D3DDEVTYPE_SW          EQU 3


D3DRTYPE_SURFACE                EQU  1
D3DRTYPE_VOLUME                 EQU  2
D3DRTYPE_TEXTURE                EQU  3
D3DRTYPE_VOLUMETEXTURE          EQU  4
D3DRTYPE_CUBETEXTURE            EQU  5
D3DRTYPE_VERTEXBUFFER           EQU  6
D3DRTYPE_INDEXBUFFER            EQU  7


D3DPOOL_DEFAULT                 EQU 0
D3DPOOL_MANAGED                 EQU 1
D3DPOOL_SYSTEMMEM               EQU 2
D3DPOOL_SCRATCH                 EQU 3
    
D3DUSAGE_RENDERTARGET       EQU 00000001h
D3DUSAGE_DEPTHSTENCIL       EQU 00000002h

; Usages for Vertex/Index buffers 
D3DUSAGE_WRITEONLY          EQU 00000008h
D3DUSAGE_SOFTWAREPROCESSING EQU 00000010h
D3DUSAGE_DONOTCLIP          EQU 00000020h
D3DUSAGE_POINTS             EQU 00000040h
D3DUSAGE_RTPATCHES          EQU 00000080h
D3DUSAGE_NPATCHES           EQU 00000100h
D3DUSAGE_DYNAMIC            EQU 00000200h


; Flexible vertex format bits
D3DFVF_RESERVED0        EQU 0001h
D3DFVF_POSITION_MASK    EQU 000Eh
D3DFVF_XYZ              EQU 0002h
D3DFVF_XYZRHW           EQU 0004h
D3DFVF_XYZB1            EQU 0006h
D3DFVF_XYZB2            EQU 0008h
D3DFVF_XYZB3            EQU 000ah
D3DFVF_XYZB4            EQU 000ch
D3DFVF_XYZB5            EQU 000eh

D3DFVF_NORMAL           EQU 0010h
D3DFVF_PSIZE            EQU 0020h
D3DFVF_DIFFUSE          EQU 0040h
D3DFVF_SPECULAR         EQU 0080h

D3DFVF_TEXCOUNT_MASK    EQU 0f00h
D3DFVF_TEXCOUNT_SHIFT   EQU 8
D3DFVF_TEX0             EQU 0000h
D3DFVF_TEX1             EQU 0100h
D3DFVF_TEX2             EQU 0200h
D3DFVF_TEX3             EQU 0300h
D3DFVF_TEX4             EQU 0400h
D3DFVF_TEX5             EQU 0500h
D3DFVF_TEX6             EQU 0600h
D3DFVF_TEX7             EQU 0700h
D3DFVF_TEX8             EQU 0800h

; D3DFORMAT enumerators
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
D3DFMT_A2B10G10R10          EQU 31
D3DFMT_G16R16               EQU 34
D3DFMT_D16_LOCKABLE         EQU 70
D3DFMT_D32                  EQU 71
D3DFMT_D15S1                EQU 73
D3DFMT_D24S8                EQU 75
D3DFMT_D16                  EQU 80
D3DFMT_D24X8                EQU 77
D3DFMT_D24X4S4              EQU 79


D3DPT_POINTLIST             EQU 1
D3DPT_LINELIST              EQU 2
D3DPT_LINESTRIP             EQU 3
D3DPT_TRIANGLELIST          EQU 4
D3DPT_TRIANGLESTRIP         EQU 5
D3DPT_TRIANGLEFAN           EQU 6


; Swapeffects
   D3DSWAPEFFECT_DISCARD           EQU 1
   D3DSWAPEFFECT_FLIP              EQU 2
   D3DSWAPEFFECT_COPY              EQU 3
   D3DSWAPEFFECT_COPY_VSYNC        EQU 4
    

   D3DLIGHT_POINT          EQU 1
   D3DLIGHT_SPOT           EQU 2
   D3DLIGHT_DIRECTIONAL    EQU 3
    

   D3DTS_VIEW          	EQU 2
   D3DTS_PROJECTION    	EQU 3
   D3DTS_TEXTURE0      	EQU 16
   D3DTS_TEXTURE1      	EQU 17
   D3DTS_TEXTURE2      	EQU 18
   D3DTS_TEXTURE3      	EQU 19
   D3DTS_TEXTURE4      	EQU 20
   D3DTS_TEXTURE5  	EQU 21
   D3DTS_TEXTURE6  	EQU 22
   D3DTS_TEXTURE7  	EQU 23
   D3DTS_WORLD 		EQU 0100h


   D3DTSS_COLOROP        EQU  1 ; D3DTEXTUREOP - per-stage blending controls for color channels 
   D3DTSS_COLORARG1      EQU  2 ; D3DTA_* (texture arg) 
   D3DTSS_COLORARG2      EQU  3 ; D3DTA_* (texture arg) 
   D3DTSS_ALPHAOP        EQU  4 ; D3DTEXTUREOP - per-stage blending controls for alpha channel 
   D3DTSS_ALPHAARG1      EQU  5 ; D3DTA_* (texture arg) 
   D3DTSS_ALPHAARG2      EQU  6 ; D3DTA_* (texture arg) 
   D3DTSS_BUMPENVMAT00   EQU  7 ; float (bump mapping matrix) 
   D3DTSS_BUMPENVMAT01   EQU  8 ; float (bump mapping matrix) 
   D3DTSS_BUMPENVMAT10   EQU  9 ; float (bump mapping matrix) 
   D3DTSS_BUMPENVMAT11   EQU 10 ; float (bump mapping matrix) 
   D3DTSS_TEXCOORDINDEX  EQU 11 ; identifies which set of texture coordinates index this texture 
   D3DTSS_ADDRESSU       EQU 13 ; D3DTEXTUREADDRESS for U coordinate 
   D3DTSS_ADDRESSV       EQU 14 ; D3DTEXTUREADDRESS for V coordinate 
   D3DTSS_BORDERCOLOR    EQU 15 ; D3DCOLOR 
   D3DTSS_MAGFILTER      EQU 16 ; D3DTEXTUREFILTER filter to use for magnification 
   D3DTSS_MINFILTER      EQU 17 ; D3DTEXTUREFILTER filter to use for minification 
   D3DTSS_MIPFILTER      EQU 18 ; D3DTEXTUREFILTER filter to use between mipmaps during minification 
   D3DTSS_MIPMAPLODBIAS  EQU 19 ; float Mipmap LOD bias 
   D3DTSS_MAXMIPLEVEL    EQU 20 ; DWORD 0..(n-1) LOD index of largest map to use (0 EQUEQU largest) 
   D3DTSS_MAXANISOTROPY  EQU 21 ; DWORD maximum anisotropy 
   D3DTSS_BUMPENVLSCALE  EQU 22 ; float scale for bump map luminance 
   D3DTSS_BUMPENVLOFFSET EQU 23 ; float offset for bump map luminance 
   D3DTSS_TEXTURETRANSFORMFLAGS EQU 24 ; D3DTEXTURETRANSFORMFLAGS controls texture transform 
   D3DTSS_ADDRESSW       EQU 25 ; D3DTEXTUREADDRESS for W coordinate 
   D3DTSS_COLORARG0      EQU 26 ; D3DTA_* third arg for triadic ops 
   D3DTSS_ALPHAARG0      EQU 27 ; D3DTA_* third arg for triadic ops 
   D3DTSS_RESULTARG      EQU 28 ; D3DTA_* arg for result (CURRENT or TEMP) 
   D3DTSS_FORCE_DWORD    EQU 07fffffffh ; force 32-bit size enum 
    
    
; Control
   D3DTOP_DISABLE              EQU 1      ; disables stage
   D3DTOP_SELECTARG1           EQU 2      ; the default
   D3DTOP_SELECTARG2           EQU 3

; Modulate
   D3DTOP_MODULATE             EQU 4      ; multiply args together
   D3DTOP_MODULATE2X           EQU 5      ; multiply and  1 bit
   D3DTOP_MODULATE4X           EQU 6      ; multiply and  2 bits

; Add
   D3DTOP_ADD                  EQU  7   ; add arguments together
   D3DTOP_ADDSIGNED            EQU  8   ; add with -0.5 bias
   D3DTOP_ADDSIGNED2X          EQU  9   ; as above but left  1 bit
   D3DTOP_SUBTRACT             EQU 10   ; Arg1 - Arg2, with no saturation
   D3DTOP_ADDSMOOTH            EQU 11   ; add 2 args, subtract product
                                        ; Arg1 + Arg2 - Arg1*Arg2
                                        ; = Arg1 + (1-Arg1)*Arg2

;Values for COLORARG0,1,2, ALPHAARG0,1,2, and RESULTARG texture blending
;operations set in texture processing stage controls in D3DRENDERSTATE.
   D3DTA_SELECTMASK        EQU 00000000Fh  ; mask for arg selector
   D3DTA_DIFFUSE           EQU 000000000h  ; select diffuse color (read only)
   D3DTA_CURRENT           EQU 000000001h  ; select stage destination register (read/write)
   D3DTA_TEXTURE           EQU 000000002h  ; select texture color (read only)
   D3DTA_TFACTOR           EQU 000000003h  ; select D3DRS_TEXTUREFACTOR (read only)
   D3DTA_SPECULAR          EQU 000000004h  ; select specular color (read only)
   D3DTA_TEMP              EQU 000000005h  ; select temporary register color (read/write)
   D3DTA_COMPLEMENT        EQU 000000010h  ; take 1.0 - x (read modifier)
   D3DTA_ALPHAREPLICATE    EQU 000000020h  ; replicate alpha to color components (read modifier)


   D3DTEXF_NONE            EQU 0    ; filtering disabled (valid for mip filter only)
   D3DTEXF_POINT           EQU 1    ; nearest
   D3DTEXF_LINEAR          EQU 2    ; linear interpolation
   D3DTEXF_ANISOTROPIC     EQU 3    ; anisotropic
   D3DTEXF_FLATCUBIC       EQU 4    ; cubic
   D3DTEXF_GAUSSIANCUBIC   EQU 5    ; different cubic kernel
    
    
   D3DCLEAR_TARGET         EQU 00000001h  ; Clear target surface 
   D3DCLEAR_ZBUFFER        EQU 00000002h  ; Clear target z buffer 
   D3DCLEAR_STENCIL        EQU 00000004h  ; Clear stencil planes 


; Shading modes
   D3DSHADE_FLAT           EQU 1
   D3DSHADE_GOURAUD        EQU 2
   D3DSHADE_PHONG          EQU 3


; Fill modes
   D3DFILL_POINT           EQU 1
   D3DFILL_WIREFRAME       EQU 2
   D3DFILL_SOLID           EQU 3


; Light types    
   D3DLIGHT_POINT          EQU 1
   D3DLIGHT_SPOT           EQU 2
   D3DLIGHT_DIRECTIONAL    EQU 3

    
; Rendering states
    D3DRS_ZENABLE                   EQU 7    ; D3DZBUFFERTYPE (or TRUE/FALSE for legacy) 
    D3DRS_FILLMODE                  EQU 8    ; D3DFILLMODE 
    D3DRS_SHADEMODE                 EQU 9    ; D3DSHADEMODE 
    D3DRS_LINEPATTERN               EQU 10   ; D3DLINEPATTERN 
    D3DRS_ZWRITEENABLE              EQU 14   ; TRUE to enable z writes 
    D3DRS_ALPHATESTENABLE           EQU 15   ; TRUE to enable alpha tests 
    D3DRS_LASTPIXEL                 EQU 16   ; TRUE for last-pixel on lines 
    D3DRS_SRCBLEND                  EQU 19   ; D3DBLEND 
    D3DRS_DESTBLEND                 EQU 20   ; D3DBLEND 
    D3DRS_CULLMODE                  EQU 22   ; D3DCULL 
    D3DRS_ZFUNC                     EQU 23   ; D3DCMPFUNC 
    D3DRS_ALPHAREF                  EQU 24   ; D3DFIXED 
    D3DRS_ALPHAFUNC                 EQU 25   ; D3DCMPFUNC 
    D3DRS_DITHERENABLE              EQU 26   ; TRUE to enable dithering 
    D3DRS_ALPHABLENDENABLE          EQU 27   ; TRUE to enable alpha blending 
    D3DRS_FOGENABLE                 EQU 28   ; TRUE to enable fog blending 
    D3DRS_SPECULARENABLE            EQU 29   ; TRUE to enable specular 
    D3DRS_ZVISIBLE                  EQU 30   ; TRUE to enable z checking 
    D3DRS_FOGCOLOR                  EQU 34   ; D3DCOLOR 
    D3DRS_FOGTABLEMODE              EQU 35   ; D3DFOGMODE 
    D3DRS_FOGSTART                  EQU 36   ; Fog start (for both vertex and pixel fog) 
    D3DRS_FOGEND                    EQU 37   ; Fog end      
    D3DRS_FOGDENSITY                EQU 38   ; Fog density  
    D3DRS_EDGEANTIALIAS             EQU 40   ; TRUE to enable edge antialiasing 
    D3DRS_ZBIAS                     EQU 47   ; LONG Z bias 
    D3DRS_RANGEFOGENABLE            EQU 48   ; Enables range-based fog 
    D3DRS_STENCILENABLE             EQU 52   ; BOOL enable/disable stenciling 
    D3DRS_STENCILFAIL               EQU 53   ; D3DSTENCILOP to do if stencil test fails 
    D3DRS_STENCILZFAIL              EQU 54   ; D3DSTENCILOP to do if stencil test passes and Z test fails 
    D3DRS_STENCILPASS               EQU 55   ; D3DSTENCILOP to do if both stencil and Z tests pass 
    D3DRS_STENCILFUNC               EQU 56   ; D3DCMPFUNC fn.  Stencil Test passes if ((ref & mask) stencilfn (stencil & mask)) is true 
    D3DRS_STENCILREF                EQU 57   ; Reference value used in stencil test 
    D3DRS_STENCILMASK               EQU 58   ; Mask value used in stencil test 
    D3DRS_STENCILWRITEMASK          EQU 59   ; Write mask applied to values written to stencil buffer 
    D3DRS_TEXTUREFACTOR             EQU 60   ; D3DCOLOR used for multi-texture blend 
    D3DRS_WRAP0                     EQU 128  ; wrap for 1st texture coord. set 
    D3DRS_WRAP1                     EQU 129  ; wrap for 2nd texture coord. set 
    D3DRS_WRAP2                     EQU 130  ; wrap for 3rd texture coord. set 
    D3DRS_WRAP3                     EQU 131  ; wrap for 4th texture coord. set 
    D3DRS_WRAP4                     EQU 132  ; wrap for 5th texture coord. set 
    D3DRS_WRAP5                     EQU 133  ; wrap for 6th texture coord. set 
    D3DRS_WRAP6                     EQU 134  ; wrap for 7th texture coord. set 
    D3DRS_WRAP7                     EQU 135  ; wrap for 8th texture coord. set 
    D3DRS_CLIPPING                  EQU 136
    D3DRS_LIGHTING                  EQU 137
    D3DRS_AMBIENT                   EQU 139
    D3DRS_FOGVERTEXMODE             EQU 140
    D3DRS_COLORVERTEX               EQU 141
    D3DRS_LOCALVIEWER               EQU 142
    D3DRS_NORMALIZENORMALS          EQU 143
    D3DRS_DIFFUSEMATERIALSOURCE     EQU 145
    D3DRS_SPECULARMATERIALSOURCE    EQU 146
    D3DRS_AMBIENTMATERIALSOURCE     EQU 147
    D3DRS_EMISSIVEMATERIALSOURCE    EQU 148
    D3DRS_VERTEXBLEND               EQU 151
    D3DRS_CLIPPLANEENABLE           EQU 152
    D3DRS_SOFTWAREVERTEXPROCESSING  EQU 153
    D3DRS_POINTSIZE                 EQU 154   ; float point size 
    D3DRS_POINTSIZE_MIN             EQU 155   ; float point size min threshold 
    D3DRS_POINTSPRITEENABLE         EQU 156   ; BOOL point texture coord control 
    D3DRS_POINTSCALEENABLE          EQU 157   ; BOOL point size scale enable 
    D3DRS_POINTSCALE_A              EQU 158   ; float point attenuation A value 
    D3DRS_POINTSCALE_B              EQU 159   ; float point attenuation B value 
    D3DRS_POINTSCALE_C              EQU 160   ; float point attenuation C value 
    D3DRS_MULTISAMPLEANTIALIAS      EQU 161  ; BOOL - set to do FSAA with multisample buffer
    D3DRS_MULTISAMPLEMASK           EQU 162  ; DWORD - per-sample enable/disable
    D3DRS_PATCHEDGESTYLE            EQU 163  ; Sets whether patch edges will use float style tessellation
    D3DRS_PATCHSEGMENTS             EQU 164  ; Number of segments per edge when drawing patches
    D3DRS_DEBUGMONITORTOKEN         EQU 165  ; DEBUG ONLY - token to debug monitor
    D3DRS_POINTSIZE_MAX             EQU 166   ; float point size max threshold 
    D3DRS_INDEXEDVERTEXBLENDENABLE  EQU 167
    D3DRS_COLORWRITEENABLE          EQU 168  ; per-channel write enable
    D3DRS_TWEENFACTOR               EQU 170   ; float tween factor
    D3DRS_BLENDOP                   EQU 171   ; D3DBLENDOP setting
    D3DRS_POSITIONORDER             EQU 172   ; NPatch position interpolation order. D3DORDER_LINEAR or D3DORDER_CUBIC (default)
    D3DRS_NORMALORDER               EQU 173 
    

D3DZB_FALSE                 EQU 0
D3DZB_TRUE                  EQU 1 ; Z buffering
D3DZB_USEW                  EQU 2 ; W buffering
    

D3DCULL_NONE                EQU 1
D3DCULL_CW                  EQU 2
D3DCULL_CCW                 EQU 3
    
    
    

_0ARGS_PROTO	typedef PROTO :DWORD
_1ARGS_PROTO	typedef PROTO :DWORD,:DWORD
_2ARGS_PROTO	typedef PROTO :DWORD,:DWORD,:DWORD
_3ARGS_PROTO	typedef PROTO :DWORD,:DWORD,:DWORD,:DWORD
_4ARGS_PROTO	typedef PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_5ARGS_PROTO	typedef PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_6ARGS_PROTO	typedef PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_7ARGS_PROTO	typedef PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_0ARGS		typedef ptr _0ARGS_PROTO
_1ARGS		typedef ptr _1ARGS_PROTO
_2ARGS		typedef ptr _2ARGS_PROTO
_3ARGS		typedef ptr _3ARGS_PROTO
_4ARGS		typedef ptr _4ARGS_PROTO
_5ARGS		typedef ptr _5ARGS_PROTO
_6ARGS		typedef ptr _6ARGS_PROTO
_7ARGS		typedef ptr _7ARGS_PROTO


IDirect3D8 STRUCT DWORD
    ; IUnknown methods 
    QueryInterface		dd ?
    AddRef			dd ?
    Release			_0ARGS ?

    ; IDirect3D8 methods 
    RegisterSoftwareDevice	dd ?
    GetAdapterCount		dd ?
    GetAdapterIdentifier	dd ?
    GetAdapterModeCount		dd ?
    EnumAdapterModes		dd ?
    GetAdapterDisplayMode	_2ARGS ?
    CheckDeviceType		dd ?
    CheckDeviceFormat		_6ARGS ?
    CheckDeviceMultiSampleType	dd ?
    CheckDepthStencilMatch	dd ?
    GetDeviceCaps		dd ?
    GetAdapterMonitor		dd ?
    CreateDevice		_6ARGS ?
IDirect3D8 ENDS






IDirect3DDevice8 STRUCT DWORD
    ; IUnknown methods 
    QueryInterface 		dd ?
    AddRef 			dd ?
    Release 			_0ARGS ?

    ; IDirect3DDevice8 methods 
    TestCooperativeLevel 	dd ?
    GetAvailableTextureMem 	dd ?
    ResourceManagerDiscardBytes dd ?
    GetDirect3D 		dd ?
    GetDeviceCaps 		dd ?
    GetDisplayMode 		dd ?
    GetCreationParameters 	dd ?
    SetCursorProperties 	dd ?
    SetCursorPosition 		dd ?
    ShowCursor 			dd ?
    CreateAdditionalSwapChain 	dd ?
    Reset 			dd ?
    Present 			_4ARGS ?
    GetBackBuffer 		dd ?
    GetRasterStatus 		dd ?
    SetGammaRamp 		dd ?
    GetGammaRamp 		dd ?
    CreateTexture 		_7ARGS ?
    CreateVolumeTexture 	dd ?
    CreateCubeTexture 		dd ?
    CreateVertexBuffer 		_5ARGS ?
    CreateIndexBuffer 		dd ?
    CreateRenderTarget 		dd ?
    CreateDepthStencilSurface 	dd ?
    CreateImageSurface 		dd ?
    CopyRects 			dd ?
    UpdateTexture 		dd ?
    GetFrontBuffer 		dd ?
    SetRenderTarget 		dd ?
    GetRenderTarget 		dd ?
    GetDepthStencilSurface 	dd ?
    BeginScene 			_0ARGS ?
    EndScene 			_0ARGS ?
    Clear 			_6ARGS ?
    SetTransform 		_2ARGS ?
    GetTransform 		dd ?
    MultiplyTransform 		dd ?
    SetViewport 		dd ?
    GetViewport 		dd ?
    SetMaterial 		_1ARGS ?
    GetMaterial 		dd ?
    SetLight 			_2ARGS ?
    GetLight 			dd ?
    LightEnable 		_2ARGS ?
    GetLightEnable 		dd ?
    SetClipPlane 		dd ?
    GetClipPlane 		dd ?
    SetRenderState 		_2ARGS ?
    GetRenderState 		dd ?
    BeginStateBlock 		dd ?
    EndStateBlock 		dd ?
    ApplyStateBlock 		dd ?
    CaptureStateBlock 		dd ?
    DeleteStateBlock 		dd ?
    CreateStateBlock 		dd ?
    SetClipStatus 		dd ?
    GetClipStatus 		dd ?
    GetTexture 			dd ?
    SetTexture 			_2ARGS ?
    GetTextureStageState 	dd ?
    SetTextureStageState 	_3ARGS ?
    ValidateDevice 		dd ?
    GetInfo 			dd ?
    SetPaletteEntries 		dd ?
    GetPaletteEntries 		dd ?
    SetCurrentTexturePalette 	dd ?
    GetCurrentTexturePalette 	dd ?
    DrawPrimitive 		_3ARGS ?
    DrawIndexedPrimitive 	dd ?
    DrawPrimitiveUP 		_4ARGS ?
    DrawIndexedPrimitiveUP 	dd ?
    ProcessVertices 		dd ?
    CreateVertexShader 		dd ?
    SetVertexShader 		_1ARGS ?
    GetVertexShader 		dd ?
    DeleteVertexShader 		dd ?
    SetVertexShaderConstant 	dd ?
    GetVertexShaderConstant 	dd ?
    GetVertexShaderDeclaration 	dd ?
    GetVertexShaderFunction 	dd ?
    SetStreamSource 		_3ARGS ?
    GetStreamSource 		dd ?
    SetIndices 			dd ?
    GetIndices 			dd ?
    CreatePixelShader 		dd ?
    SetPixelShader 		dd ?
    GetPixelShader 		dd ?
    DeletePixelShader 		dd ?
    SetPixelShaderConstant 	dd ?
    GetPixelShaderConstant 	dd ?
    GetPixelShaderFunction 	dd ?
    DrawRectPatch 		dd ?
    DrawTriPatch 		dd ?
    DeletePatch 		dd ?
IDirect3DDevice8 ENDS



IDirect3DTexture8 STRUCT DWORD
    ; IUnknown methods 
    QueryInterface		dd ?
    AddRef			dd ?
    Release			_0ARGS ?

    ; IDirect3DBaseTexture8 methods 
    GetDevice			_1ARGS ?
    SetPrivateData		dd ?
    GetPrivateData		dd ?
    FreePrivateData		_1ARGS ?
    SetPriority			_1ARGS ?
    GetPriority			dd ?
    PreLoad			dd ?
    GetType			dd ?
    SetLOD			_1ARGS ?
    GetLOD			dd ?
    GetLevelCount		dd ?
    GetLevelDesc		_2ARGS ?
    GetSurfaceLevel		_2ARGS ?
    LockRect			_4ARGS ?
    UnlockRect			_1ARGS ?
    AddDirtyRect		_1ARGS ?
IDirect3DTexture8 ENDS    



IDirect3DVertexBuffer8 STRUCT DWORD
    ; IUnknown methods 
    QueryInterface		_2ARGS ?
    AddRef 			_0ARGS ?
    Release 			_0ARGS ?

    ; IDirect3DResource8 methods 
    GetDevice			_1ARGS ?
    SetPrivateData		_4ARGS ?
    GetPrivateData		_3ARGS ?
    FreePrivateData		_1ARGS ?
    SetPriority			_1ARGS ?
    GetPriority 		_0ARGS ?
    PreLoad 			_0ARGS ?
    GetType 			_0ARGS ?
    Lock_			_4ARGS ?
    Unlock 			_0ARGS ?
    GetDesc			_1ARGS ?
IDirect3DVertexBuffer8 ENDS

    

ID3DXFont STRUCT DWORD
    ; IUnknown
    QueryInterface		dd ?
    AddRef			dd ?
    Release			_0ARGS ?

    ; ID3DXFont
    GetDevice			dd ?
    GetLogFont			dd ?

    Begin			_0ARGS ?
    DrawTextA			_5ARGS ?
    DrawTextW			_5ARGS ?
    End_			_0ARGS ?

    OnLostDevice		dd ?
    OnResetDevice		dd ?
ID3DXFont ENDS



    
D3DDISPLAYMODE STRUCT
	Width_			dd ?
	Height			dd ?
	RefreshRate		dd ?
	Format			dd ?
D3DDISPLAYMODE ENDS



D3DPRESENT_PARAMETERS STRUCT
    BackBufferWidth		dd ?
    BackBufferHeight		dd ?
    BackBufferFormat		dd ?
    BackBufferCount		dd ?

    MultiSampleType		dd ?

    SwapEffect			dd ?
    hDeviceWindow		dd ?
    Windowed			dd ?
    EnableAutoDepthStencil	dd ?
    AutoDepthStencilFormat	dd ?
    Flags			dd ?

    ; Following elements must be zero for Windowed mode 
    FullScreen_RefreshRateInHz	dd ?
    FullScreen_PresentationInterval	dd ?
D3DPRESENT_PARAMETERS ENDS    


D3DLOCKED_RECT STRUCT
    Pitch	dd ?
    pBits	dd ?
D3DLOCKED_RECT ENDS


D3DVECTOR STRUCT
	x			REAL4 ?
	y			REAL4 ?
	z			REAL4 ?
D3DVECTOR ENDS


D3DXVECTOR STRUCT
	x			REAL4 ?
	y			REAL4 ?
	z			REAL4 ?
D3DXVECTOR ENDS


D3DMATRIX STRUCT
        _11			REAL4 ?
        _12			REAL4 ?
        _13			REAL4 ?
        _14			REAL4 ?
        _21			REAL4 ?
        _22			REAL4 ?
        _23			REAL4 ?
        _24			REAL4 ?
        _31			REAL4 ?
        _32			REAL4 ?
        _33			REAL4 ?
        _34			REAL4 ?
        _41			REAL4 ?
        _42			REAL4 ?
        _43			REAL4 ?
        _44			REAL4 ?
D3DMATRIX ENDS


D3DXMATRIX STRUCT
        _11			REAL4 ?
        _12			REAL4 ?
        _13			REAL4 ?
        _14			REAL4 ?
        _21			REAL4 ?
        _22			REAL4 ?
        _23			REAL4 ?
        _24			REAL4 ?
        _31			REAL4 ?
        _32			REAL4 ?
        _33			REAL4 ?
        _34			REAL4 ?
        _41			REAL4 ?
        _42			REAL4 ?
        _43			REAL4 ?
        _44			REAL4 ?
D3DXMATRIX ENDS


D3DCOLORVALUE STRUCT
	r			REAL4 ?
	g			REAL4 ?
	b			REAL4 ?
	a			REAL4 ?
D3DCOLORVALUE ENDS



D3DMATERIAL8 STRUCT
    	Diffuse			D3DCOLORVALUE <?> ; Diffuse color RGBA 
    	Ambient			D3DCOLORVALUE <?> ; Ambient color RGB 
    	Specular		D3DCOLORVALUE <?> ; Specular 'shininess' 
    	Emissive		D3DCOLORVALUE <?> ; Emissive color RGB 
    	Power			REAL4 ?           ; Sharpness if specular highlight 
D3DMATERIAL8 ENDS



D3DLIGHT8 STRUCT
    	Type_			dd ?                ; Type of light source 
    	Diffuse			D3DCOLORVALUE <?>   ; Diffuse color of light 
    	Specular		D3DCOLORVALUE <?>   ; Specular color of ligh
    	Ambient			D3DCOLORVALUE <?>   ; Ambient color of light 
    	Position		D3DVECTOR <?>       ; Position in world space 
    	Direction		D3DVECTOR <?>       ; Direction in world space 
    	Range			REAL4 ?             ; Cutoff range 
    	Falloff			REAL4 ?             ; Falloff 
    	Attenuation0		REAL4 ?             ; Constant attenuation 
    	Attenuation1		REAL4 ?             ; Linear attenuation 
    	Attenuation2		REAL4 ?             ; Quadratic attenuation 
    	Theta			REAL4 ?             ; Inner angle of spotlight cone 
    	Phi			REAL4 ?             ; Outer angle of spotlight cone 
D3DLIGHT8 ENDS




Direct3DCreate8 PROTO :DWORD

D3DXCreateFont PROTO :DWORD,:DWORD,:DWORD
D3DXCreateTextureFromFileA PROTO :DWORD,:DWORD,:DWORD
D3DXCreateTextureFromFile EQU <D3DXCreateTextureFromFileA>
D3DXMatrixMultiply PROTO :DWORD,:DWORD,:DWORD
D3DXMatrixPerspectiveFovLH PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
D3DXMatrixRotationAxis PROTO :DWORD,:DWORD,:DWORD
D3DXMatrixRotationX PROTO :DWORD,:DWORD
D3DXMatrixRotationY PROTO :DWORD,:DWORD
D3DXMatrixRotationZ PROTO :DWORD,:DWORD
D3DXMatrixScaling PROTO :DWORD,:DWORD,:DWORD,:DWORD
D3DXMatrixTranslation PROTO :DWORD,:DWORD,:DWORD,:DWORD



.data

; IID_IDirect3D8 
; {1DD9E8DA-1C77-4d40-B0CF-98FEFDFF9512} 
IID_IDirect3D8		GUID <1DD9E8DAh, 1C77h, 4D40h, <0B0h, 0CFh, 98h, 0FEh, 0FDh, 0FFh, 95h, 12h>>

; IID_IDirect3DDevice8 
; {7385E5DF-8FE8-41D5-86B6-D7B48547B6CF} 
IID_IDirect3DDevice8	GUID <7385E5DFh, 8FE8h, 41D5h, <86h, 0B6h, 0D7h, 0B4h, 85h, 47h, 0B6h, 0CFh>>
