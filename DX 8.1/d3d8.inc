;;/*==========================================================================;
; *
; *
; *  File:   d3d8.h
; *  Content:    Direct3D include file
; *
; ****************************************************************************/

IFNDEF __D3D8_INC_
_D3D8_INC_=1

IFNDEF DIRECT3D_VERSION
DIRECT3D_VERSION 	EQU	0800h
ENDIF   ;DIRECT3D_VERSION


;/* This identifier is passed to Direct3DCreate8 in order to ensure that an
; * application was built against the correct header files. This number is
; * incremented whenever a header (or other) change would require applications
; * to be rebuilt. If the version doesn't match, Direct3DCreate8 will fail.
; * (The number itself has no meaning.)*/

D3D_SDK_VERSION     EQU 220

include dx_objbase.def ; macros to define and call COM-objects etc.

D3DAPI  EQU WINAPI

;/*
; * Interface IID's
; */

ifndef _NO_GUIDSEG
 @dxGuids segment dword
endif

;/* IID_IDirect3D8 */
;/* {1DD9E8DA-1C77-4d40-B0CF-98FEFDFF9512} */
IID_IDirect3D8	GUID	{01dd9e8dah,01c77h,04d40h,<0b0h,0cfh,098h,0feh,0fdh,0ffh,095h,012h>}

;/* IID_IDirect3DDevice8 */
;/* {7385E5DF-8FE8-41D5-86B6-D7B48547B6CF} */
IID_IDirect3DDevice8	GUID	{07385e5dfh,08fe8h,041d5h,<086h,0b6h,0d7h,0b4h,085h,047h,0b6h,0cfh>}

;/* IID_IDirect3DResource8 */
;/* {1B36BB7B-09B7-410a-B445-7D1430D7B33F} */
IID_IDirect3DResource8	GUID	{01b36bb7bh,09b7h,0410ah,<0b4h,045h,07dh,014h,030h,0d7h,0b3h,03fh>}

;/* IID_IDirect3DBaseTexture8 */
;/* {B4211CFA-51B9-4a9f-AB78-DB99B2BB678E} */
IID_IDirect3DBaseTexture8	GUID	{0b4211cfah,051b9h,04a9fh,<0abh,078h,0dbh,099h,0b2h,0bbh,067h,08eh>}

;/* IID_IDirect3DTexture8 */
;/* {E4CDD575-2866-4f01-B12E-7EECE1EC9358} */
IID_IDirect3DTexture8	GUID	{0e4cdd575h,02866h,04f01h,<0b1h,02eh,07eh,0ech,0e1h,0ech,093h,058h>}

;/* IID_IDirect3DCubeTexture8 */
;/* {3EE5B968-2ACA-4c34-8BB5-7E0C3D19B750} */
IID_IDirect3DCubeTexture8	GUID	{03ee5b968h,02acah,04c34h,<08bh,0b5h,07eh,00ch,03dh,019h,0b7h,050h>}

;/* IID_IDirect3DVolumeTexture8 */
;/* {4B8AAAFA-140F-42ba-9131-597EAFAA2EAD} */
IID_IDirect3DVolumeTexture8	GUID	{04b8aaafah,0140fh,042bah,<091h,031h,059h,07eh,0afh,0aah,02eh,0adh>}

;/* IID_IDirect3DVertexBuffer8 */
;/* {8AEEEAC7-05F9-44d4-B591-000B0DF1CB95} */
IID_IDirect3DVertexBuffer8	GUID	{08aeeeac7h,005f9h,044d4h,<0b5h,091h,000h,00bh,00dh,0f1h,0cbh,095h>}

;/* IID_IDirect3DIndexBuffer8 */
;/* {0E689C9A-053D-44a0-9D92-DB0E3D750F86} */
IID_IDirect3DIndexBuffer8	GUID	{00e689c9ah,0053dh,044a0h,<09dh,092h,0dbh,00eh,03dh,075h,00fh,086h>}

;/* IID_IDirect3DSurface8 */
;/* {B96EEBCA-B326-4ea5-882F-2FF5BAE021DD} */
IID_IDirect3DSurface8	GUID	{0b96eebcah,0b326h,04ea5h,<088h,02fh,02fh,0f5h,0bah,0e0h,021h,0ddh>}

;/* IID_IDirect3DVolume8 */
;/* {BD7349F5-14F1-42e4-9C79-972380DB40C0} */
IID_IDirect3DVolume8	GUID	{0bd7349f5h,014f1h,042e4h,<09ch,079h,097h,023h,080h,0dbh,040h,0c0h>}

;/* IID_IDirect3DSwapChain8 */
;/* {928C088B-76B9-4C6B-A536-A590853876CD} */
IID_IDirect3DSwapChain8	GUID	{0928c088bh,076b9h,04c6bh,<0a5h,036h,0a5h,090h,085h,038h,076h,0cdh>}

ifndef _NO_GUIDSEG
 @dxGuids ends
endif

;#ifdef __cplusplus

;interface IDirect3D8;
;interface IDirect3DDevice8;

;interface IDirect3DResource8;
;interface IDirect3DBaseTexture8;
;interface IDirect3DTexture8;
;interface IDirect3DVolumeTexture8;
;interface IDirect3DCubeTexture8;

;interface IDirect3DVertexBuffer8;
;interface IDirect3DIndexBuffer8;

;interface IDirect3DSurface8;
;interface IDirect3DVolume8;

;interface IDirect3DSwapChain8;

;#endif


;typedef interface IDirect3D8                IDirect3D8;
;typedef interface IDirect3DDevice8          IDirect3DDevice8;
;typedef interface IDirect3DResource8        IDirect3DResource8;
;typedef interface IDirect3DBaseTexture8     IDirect3DBaseTexture8;
;typedef interface IDirect3DTexture8         IDirect3DTexture8;
;typedef interface IDirect3DVolumeTexture8   IDirect3DVolumeTexture8;
;typedef interface IDirect3DCubeTexture8     IDirect3DCubeTexture8;
;typedef interface IDirect3DVertexBuffer8    IDirect3DVertexBuffer8;
;typedef interface IDirect3DIndexBuffer8     IDirect3DIndexBuffer8;
;typedef interface IDirect3DSurface8         IDirect3DSurface8;
;typedef interface IDirect3DVolume8          IDirect3DVolume8;
;typedef interface IDirect3DSwapChain8       IDirect3DSwapChain8;

include d3d8types.inc
include d3d8caps.inc

;/*
; * DLL Function for creating a Direct3D8 object. This object supports
; * enumeration and allows the creation of Direct3DDevice8 objects.
; * Pass the value of the constant D3D_SDK_VERSION to this function, so
; * that the run-time can validate that your application was compiled
; * against the right headers.
; */

;IDirect3D8 * WINAPI Direct3DCreate8(UINT SDKVersion);
Direct3DCreate8 PROTO :UINT

;/*
; * Direct3D interfaces
; */

;#undef INTERFACE
;#define INTERFACE IDirect3D8

DECLARE_INTERFACE <IDirect3D8_>
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3D8 methods ***/
    STDMETHOD <RegisterSoftwareDevice>,:DWORD                                   ;,(THIS_ void* pInitializeFunction) PURE;
    STDMETHOD <GetAdapterCount>                                                 ;(THIS) PURE;
    STDMETHOD <GetAdapterIdentifier>,:DWORD,:DWORD,:DWORD                       ;(THIS_ UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER8* pIdentifier) PURE;
    STDMETHOD <GetAdapterModeCount>,:DWORD                                      ;(THIS_ UINT Adapter) PURE;
    STDMETHOD <EnumAdapterModes>,:DWORD,:DWORD,:DWORD                           ;(THIS_ UINT Adapter,UINT Mode,D3DDISPLAYMODE* pMode) PURE;
    STDMETHOD <GetAdapterDisplayMode>,:DWORD,:DWORD                             ;(THIS_ UINT Adapter,D3DDISPLAYMODE* pMode) PURE;
    STDMETHOD <CheckDeviceType>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD              ;(THIS_ UINT Adapter,D3DDEVTYPE CheckType,D3DFORMAT DisplayFormat,D3DFORMAT BackBufferFormat,BOOL Windowed) PURE;
    STDMETHOD <CheckDeviceFormat>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD     ;(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat) PURE;
    STDMETHOD <CheckDeviceMultiSampleType>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD   ;(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType) PURE;
    STDMETHOD <CheckDepthStencilMatch>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD       ;(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat) PURE;
    STDMETHOD <GetDeviceCaps>,:DWORD,:DWORD,:DWORD                              ;(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS8* pCaps) PURE;
    STDMETHOD <GetAdapterMonitor>,:DWORD                                        ;(THIS_ UINT Adapter) PURE;
    STDMETHOD <CreateDevice>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD          ;(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice8** ppReturnedDeviceInterface) PURE;
;};

LPDIRECT3D8 typedef PTR
PDIRECT3D8 typedef PTR
;typedef struct IDirect3D8 *LPDIRECT3D8, *PDIRECT3D8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3D8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3D8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3D8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3D8_RegisterSoftwareDevice(p,a) (p)->lpVtbl->RegisterSoftwareDevice(p,a)
;#define IDirect3D8_GetAdapterCount(p) (p)->lpVtbl->GetAdapterCount(p)
;#define IDirect3D8_GetAdapterIdentifier(p,a,b,c) (p)->lpVtbl->GetAdapterIdentifier(p,a,b,c)
;#define IDirect3D8_GetAdapterModeCount(p,a) (p)->lpVtbl->GetAdapterModeCount(p,a)
;#define IDirect3D8_EnumAdapterModes(p,a,b,c) (p)->lpVtbl->EnumAdapterModes(p,a,b,c)
;#define IDirect3D8_GetAdapterDisplayMode(p,a,b) (p)->lpVtbl->GetAdapterDisplayMode(p,a,b)
;#define IDirect3D8_CheckDeviceType(p,a,b,c,d,e) (p)->lpVtbl->CheckDeviceType(p,a,b,c,d,e)
;#define IDirect3D8_CheckDeviceFormat(p,a,b,c,d,e,f) (p)->lpVtbl->CheckDeviceFormat(p,a,b,c,d,e,f)
;#define IDirect3D8_CheckDeviceMultiSampleType(p,a,b,c,d,e) (p)->lpVtbl->CheckDeviceMultiSampleType(p,a,b,c,d,e)
;#define IDirect3D8_CheckDepthStencilMatch(p,a,b,c,d,e) (p)->lpVtbl->CheckDepthStencilMatch(p,a,b,c,d,e)
;#define IDirect3D8_GetDeviceCaps(p,a,b,c) (p)->lpVtbl->GetDeviceCaps(p,a,b,c)
;#define IDirect3D8_GetAdapterMonitor(p,a) (p)->lpVtbl->GetAdapterMonitor(p,a)
;#define IDirect3D8_CreateDevice(p,a,b,c,d,e,f) (p)->lpVtbl->CreateDevice(p,a,b,c,d,e,f)
;#else
;#define IDirect3D8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3D8_AddRef(p) (p)->AddRef()
;#define IDirect3D8_Release(p) (p)->Release()
;#define IDirect3D8_RegisterSoftwareDevice(p,a) (p)->RegisterSoftwareDevice(a)
;#define IDirect3D8_GetAdapterCount(p) (p)->GetAdapterCount()
;#define IDirect3D8_GetAdapterIdentifier(p,a,b,c) (p)->GetAdapterIdentifier(a,b,c)
;#define IDirect3D8_GetAdapterModeCount(p,a) (p)->GetAdapterModeCount(a)
;#define IDirect3D8_EnumAdapterModes(p,a,b,c) (p)->EnumAdapterModes(a,b,c)
;#define IDirect3D8_GetAdapterDisplayMode(p,a,b) (p)->GetAdapterDisplayMode(a,b)
;#define IDirect3D8_CheckDeviceType(p,a,b,c,d,e) (p)->CheckDeviceType(a,b,c,d,e)
;#define IDirect3D8_CheckDeviceFormat(p,a,b,c,d,e,f) (p)->CheckDeviceFormat(a,b,c,d,e,f)
;#define IDirect3D8_CheckDeviceMultiSampleType(p,a,b,c,d,e) (p)->CheckDeviceMultiSampleType(a,b,c,d,e)
;#define IDirect3D8_CheckDepthStencilMatch(p,a,b,c,d,e) (p)->CheckDepthStencilMatch(a,b,c,d,e)
;#define IDirect3D8_GetDeviceCaps(p,a,b,c) (p)->GetDeviceCaps(a,b,c)
;#define IDirect3D8_GetAdapterMonitor(p,a) (p)->GetAdapterMonitor(a)
;#define IDirect3D8_CreateDevice(p,a,b,c,d,e,f) (p)->CreateDevice(a,b,c,d,e,f)
;#endif

;#undef INTERFACE
;#define INTERFACE IDirect3DDevice8

DECLARE_INTERFACE <IDirect3DDevice8_>
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3DDevice8 methods ***/
    STDMETHOD <TestCooperativeLevel>                                                            ;(THIS) PURE;
    STDMETHOD <GetAvailableTextureMem>                                                          ;(THIS) PURE;
    STDMETHOD <ResourceManagerDiscardBytes>,:DWORD                                              ;(THIS_ DWORD Bytes) PURE;
    STDMETHOD <GetDirect3D>,:DWORD                                                              ;(THIS_ IDirect3D8** ppD3D8) PURE;
    STDMETHOD <GetDeviceCaps>,:DWORD                                                            ;(THIS_ D3DCAPS8* pCaps) PURE;
    STDMETHOD <GetDisplayMode>,:DWORD                                                           ;(THIS_ D3DDISPLAYMODE* pMode) PURE;
    STDMETHOD <GetCreationParameters>,:DWORD                                                    ;(THIS_ D3DDEVICE_CREATION_PARAMETERS *pParameters) PURE;
    STDMETHOD <SetCursorProperties>,:DWORD,:DWORD,:DWORD                                        ;(THIS_ UINT XHotSpot,UINT YHotSpot,IDirect3DSurface8* pCursorBitmap) PURE;
    STDMETHOD <SetCursorPosition>,:DWORD,:DWORD,:DWORD                                          ;(THIS_ UINT XScreenSpace,UINT YScreenSpace,DWORD Flags) PURE;
    STDMETHOD <ShowCursor>,:DWORD                                                               ;(THIS_ BOOL bShow) PURE;
    STDMETHOD <CreateAdditionalSwapChain>,:DWORD,:DWORD                                         ;(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain8** pSwapChain) PURE;
    STDMETHOD <Reset>,:DWORD                                                                    ;(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters) PURE;
    STDMETHOD <Present>,:DWORD,:DWORD,:DWORD,:DWORD                                             ;(THIS_ CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion) PURE;
    STDMETHOD <GetBackBuffer>,:DWORD,:DWORD,:DWORD                                              ;(THIS_ UINT BackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface8** ppBackBuffer) PURE;
    STDMETHOD <GetRasterStatus>,:DWORD                                                          ;(THIS_ D3DRASTER_STATUS* pRasterStatus) PURE;
    STDMETHOD <SetGammaRamp>,:DWORD,:DWORD                                                      ;(THIS_ DWORD Flags,CONST D3DGAMMARAMP* pRamp) PURE;
    STDMETHOD <GetGammaRamp>,:DWORD                                                             ;(THIS_ D3DGAMMARAMP* pRamp) PURE;
    STDMETHOD <CreateTexture>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                  ;(THIS_ UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture8** ppTexture) PURE;
    STDMETHOD <CreateVolumeTexture>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD     ;(THIS_ UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture8** ppVolumeTexture) PURE;
    STDMETHOD <CreateCubeTexture>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                     ;(THIS_ UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture8** ppCubeTexture) PURE;
    STDMETHOD <CreateVertexBuffer>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                           ;(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer8** ppVertexBuffer) PURE;
    STDMETHOD <CreateIndexBuffer>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                            ;(THIS_ UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer8** ppIndexBuffer) PURE;
    STDMETHOD <CreateRenderTarget>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                    ;(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,BOOL Lockable,IDirect3DSurface8** ppSurface) PURE;
    STDMETHOD <CreateDepthStencilSurface>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                    ;(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,IDirect3DSurface8** ppSurface) PURE;
    STDMETHOD <CreateImageSurface>,:DWORD,:DWORD,:DWORD,:DWORD                                  ;(THIS_ UINT Width,UINT Height,D3DFORMAT Format,IDirect3DSurface8** ppSurface) PURE;
    STDMETHOD <CopyRects>,:DWORD                                                                ;(THIS_ IDirect3DSurface8* pSourceSurface,CONST RECT* pSourceRectsArray,UINT cRects,IDirect3DSurface8* pDestinationSurface,CONST POINT* pDestPointsArray) PURE;
    STDMETHOD <UpdateTexture>,:DWORD                                                            ;(THIS_ IDirect3DBaseTexture8* pSourceTexture,IDirect3DBaseTexture8* pDestinationTexture) PURE;
    STDMETHOD <GetFrontBuffer>,:DWORD                                                           ;(THIS_ IDirect3DSurface8* pDestSurface) PURE;
    STDMETHOD <SetRenderTarget>,:DWORD ,:DWORD                                                         ;(THIS_ IDirect3DSurface8* pRenderTarget,IDirect3DSurface8* pNewZStencil) PURE;
    STDMETHOD <GetRenderTarget>,:DWORD                                                          ;(THIS_ IDirect3DSurface8** ppRenderTarget) PURE;
    STDMETHOD <GetDepthStencilSurface>,:DWORD                                                   ;(THIS_ IDirect3DSurface8** ppZStencilSurface) PURE;
    STDMETHOD <BeginScene>                                                                      ;(THIS) PURE;
    STDMETHOD <EndScene>                                                                        ;(THIS) PURE;
    STDMETHOD <Clear>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                                 ;(THIS_ DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil) PURE;
    STDMETHOD <SetTransform>,:DWORD,:DWORD                                                      ;(THIS_ D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix) PURE;
    STDMETHOD <GetTransform>,:DWORD,:DWORD                                                      ;(THIS_ D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix) PURE;
    STDMETHOD <MultiplyTransform>,:DWORD,:DWORD                                                 ;(THIS_ D3DTRANSFORMSTATETYPE,CONST D3DMATRIX*) PURE;
    STDMETHOD <SetViewport>,:DWORD                                                              ;(THIS_ CONST D3DVIEWPORT8* pViewport) PURE;
    STDMETHOD <GetViewport>,:DWORD                                                              ;(THIS_ D3DVIEWPORT8* pViewport) PURE;
    STDMETHOD <SetMaterial>,:DWORD                                                              ;(THIS_ CONST D3DMATERIAL8* pMaterial) PURE;
    STDMETHOD <GetMaterial>,:DWORD                                                              ;(THIS_ D3DMATERIAL8* pMaterial) PURE;
    STDMETHOD <SetLight>,:DWORD,:DWORD                                                          ;(THIS_ DWORD Index,CONST D3DLIGHT8*) PURE;
    STDMETHOD <GetLight>,:DWORD,:DWORD                                                          ;(THIS_ DWORD Index,D3DLIGHT8*) PURE;
    STDMETHOD <LightEnable>,:DWORD,:DWORD                                                       ;(THIS_ DWORD Index,BOOL Enable) PURE;
    STDMETHOD <GetLightEnable>,:DWORD,:DWORD                                                    ;(THIS_ DWORD Index,BOOL* pEnable) PURE;
    STDMETHOD <SetClipPlane>,:DWORD,:DWORD                                                      ;(THIS_ DWORD Index,CONST float* pPlane) PURE;
    STDMETHOD <GetClipPlane>,:DWORD,:DWORD                                                      ;(THIS_ DWORD Index,float* pPlane) PURE;
    STDMETHOD <SetRenderState>,:DWORD,:DWORD                                                    ;(THIS_ D3DRENDERSTATETYPE State,DWORD Value) PURE;
    STDMETHOD <GetRenderState>,:DWORD,:DWORD                                                    ;(THIS_ D3DRENDERSTATETYPE State,DWORD* pValue) PURE;
    STDMETHOD <BeginStateBlock>                                                                 ;(THIS) PURE;
    STDMETHOD <EndStateBlock>,:DWORD                                                            ;(THIS_ DWORD* pToken) PURE;
    STDMETHOD <ApplyStateBlock>,:DWORD                                                          ;(THIS_ DWORD Token) PURE;
    STDMETHOD <CaptureStateBlock>,:DWORD                                                        ;(THIS_ DWORD Token) PURE;
    STDMETHOD <DeleteStateBlock>,:DWORD                                                         ;(THIS_ DWORD Token) PURE;
    STDMETHOD <CreateStateBlock>,:DWORD,:DWORD                                                  ;(THIS_ D3DSTATEBLOCKTYPE Type,DWORD* pToken) PURE;
    STDMETHOD <SetClipStatus>,:DWORD                                                             ; <THIS_ CONST D3DCLIPSTATUS8* pClipStatus) PURE;
    STDMETHOD <GetClipStatus>,:DWORD                                                             ; <THIS_ D3DCLIPSTATUS8* pClipStatus) PURE;
    STDMETHOD <GetTexture>,:DWORD,:DWORD                                                         ; <THIS_ DWORD Stage,IDirect3DBaseTexture8** ppTexture) PURE;
    STDMETHOD <SetTexture>,:DWORD,:DWORD                                                         ; <THIS_ DWORD Stage,IDirect3DBaseTexture8* pTexture) PURE;
    STDMETHOD <GetTextureStageState>,:DWORD,:DWORD,:DWORD                                        ; <THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue) PURE;
    STDMETHOD <SetTextureStageState>,:DWORD,:DWORD,:DWORD                                        ; <THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value) PURE;
    STDMETHOD <ValidateDevice>,:DWORD                                                            ; <THIS_ DWORD* pNumPasses) PURE;
    STDMETHOD <GetInfo>,:DWORD,:DWORD,:DWORD                                                     ; <THIS_ DWORD DevInfoID,void* pDevInfoStruct,DWORD DevInfoStructSize) PURE;
    STDMETHOD <SetPaletteEntries>,:DWORD,:DWORD                                                  ; <THIS_ UINT PaletteNumber,CONST PALETTEENTRY* pEntries) PURE;
    STDMETHOD <GetPaletteEntries>,:DWORD,:DWORD                                                  ; <THIS_ UINT PaletteNumber,PALETTEENTRY* pEntries) PURE;
    STDMETHOD <SetCurrentTexturePalette>,:DWORD                                                  ; <THIS_ UINT PaletteNumber) PURE;
    STDMETHOD <GetCurrentTexturePalette>,:DWORD                                                  ; <THIS_ UINT *PaletteNumber) PURE;
    STDMETHOD <DrawPrimitive>,:DWORD,:DWORD,:DWORD                                               ; <THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount) PURE;
    STDMETHOD <DrawIndexedPrimitive>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                          ; <THIS_ D3DPRIMITIVETYPE,UINT minIndex,UINT NumVertices,UINT startIndex,UINT primCount) PURE;
    STDMETHOD <DrawPrimitiveUP>,:DWORD,:DWORD,:DWORD,:DWORD                                      ; <THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) PURE;
    STDMETHOD <DrawIndexedPrimitiveUP>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD   
        ; <THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertexIndices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) PURE;
    STDMETHOD <ProcessVertices>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                               ; <THIS_ UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer8* pDestBuffer,DWORD Flags) PURE;
    STDMETHOD <CreateVertexShader>,:DWORD,:DWORD,:DWORD,:DWORD                                   ; <THIS_ CONST DWORD* pDeclaration,CONST DWORD* pFunction,DWORD* pHandle,DWORD Usage) PURE;
    STDMETHOD <SetVertexShader>,:DWORD                                                           ; <THIS_ DWORD Handle) PURE;
    STDMETHOD <GetVertexShader>,:DWORD                                                           ; <THIS_ DWORD* pHandle) PURE;
    STDMETHOD <DeleteVertexShader>,:DWORD                                                        ; <THIS_ DWORD Handle) PURE;
    STDMETHOD <SetVertexShaderConstant>,:DWORD,:DWORD,:DWORD                                     ; <THIS_ DWORD Register,CONST void* pConstantData,DWORD ConstantCount) PURE;
    STDMETHOD <GetVertexShaderConstant>,:DWORD,:DWORD,:DWORD                                     ; <THIS_ DWORD Register,void* pConstantData,DWORD ConstantCount) PURE;
    STDMETHOD <GetVertexShaderDeclaration>,:DWORD,:DWORD,:DWORD                                  ; <THIS_ DWORD Handle,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <GetVertexShaderFunction>,:DWORD,:DWORD,:DWORD                                     ; <THIS_ DWORD Handle,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <SetStreamSource>,:DWORD,:DWORD,:DWORD                                             ; <THIS_ UINT StreamNumber,IDirect3DVertexBuffer8* pStreamData,UINT Stride) PURE;
    STDMETHOD <GetStreamSource>,:DWORD,:DWORD,:DWORD                                             ; <THIS_ UINT StreamNumber,IDirect3DVertexBuffer8** ppStreamData,UINT* pStride) PURE;
    STDMETHOD <SetIndices>,:DWORD,:DWORD                                                         ; <THIS_ IDirect3DIndexBuffer8* pIndexData,UINT BaseVertexIndex) PURE;
    STDMETHOD <GetIndices>,:DWORD,:DWORD                                                         ; <THIS_ IDirect3DIndexBuffer8** ppIndexData,UINT* pBaseVertexIndex) PURE;
    STDMETHOD <CreatePixelShader>,:DWORD,:DWORD                                                  ; <THIS_ CONST DWORD* pFunction,DWORD* pHandle) PURE;
    STDMETHOD <SetPixelShader>,:DWORD                                                            ; <THIS_ DWORD Handle) PURE;
    STDMETHOD <GetPixelShader>,:DWORD                                                            ; <THIS_ DWORD* pHandle) PURE;
    STDMETHOD <DeletePixelShader>,:DWORD                                                         ; <THIS_ DWORD Handle) PURE;
    STDMETHOD <SetPixelShaderConstant>,:DWORD,:DWORD,:DWORD                                      ; <THIS_ DWORD Register,CONST void* pConstantData,DWORD ConstantCount) PURE;
    STDMETHOD <GetPixelShaderConstant>,:DWORD,:DWORD,:DWORD                                      ; <THIS_ DWORD Register,void* pConstantData,DWORD ConstantCount) PURE;
    STDMETHOD <GetPixelShaderFunction>,:DWORD,:DWORD,:DWORD                                      ; <THIS_ DWORD Handle,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <DrawRectPatch>,:DWORD,:DWORD,:DWORD                                               ; <THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo) PURE;
    STDMETHOD <DrawTriPatch>,:DWORD,:DWORD,:DWORD                                                ; <THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo) PURE;
    STDMETHOD <DeletePatch>,:DWORD                                                               ;(THIS_ UINT Handle) PURE;
;};

LPDIRECT3DDEVICE8 typedef PTR
PDIRECT3DDEVICE8 typedef PTR
;typedef struct IDirect3DDevice8 *LPDIRECT3DDEVICE8, *PDIRECT3DDEVICE8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3DDevice8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3DDevice8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3DDevice8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3DDevice8_TestCooperativeLevel(p) (p)->lpVtbl->TestCooperativeLevel(p)
;#define IDirect3DDevice8_GetAvailableTextureMem(p) (p)->lpVtbl->GetAvailableTextureMem(p)
;#define IDirect3DDevice8_ResourceManagerDiscardBytes(p,a) (p)->lpVtbl->ResourceManagerDiscardBytes(p,a)
;#define IDirect3DDevice8_GetDirect3D(p,a) (p)->lpVtbl->GetDirect3D(p,a)
;#define IDirect3DDevice8_GetDeviceCaps(p,a) (p)->lpVtbl->GetDeviceCaps(p,a)
;#define IDirect3DDevice8_GetDisplayMode(p,a) (p)->lpVtbl->GetDisplayMode(p,a)
;#define IDirect3DDevice8_GetCreationParameters(p,a) (p)->lpVtbl->GetCreationParameters(p,a)
;#define IDirect3DDevice8_SetCursorProperties(p,a,b,c) (p)->lpVtbl->SetCursorProperties(p,a,b,c)
;#define IDirect3DDevice8_SetCursorPosition(p,a,b,c) (p)->lpVtbl->SetCursorPosition(p,a,b,c)
;#define IDirect3DDevice8_ShowCursor(p,a) (p)->lpVtbl->ShowCursor(p,a)
;#define IDirect3DDevice8_CreateAdditionalSwapChain(p,a,b) (p)->lpVtbl->CreateAdditionalSwapChain(p,a,b)
;#define IDirect3DDevice8_Reset(p,a) (p)->lpVtbl->Reset(p,a)
;#define IDirect3DDevice8_Present(p,a,b,c,d) (p)->lpVtbl->Present(p,a,b,c,d)
;#define IDirect3DDevice8_GetBackBuffer(p,a,b,c) (p)->lpVtbl->GetBackBuffer(p,a,b,c)
;#define IDirect3DDevice8_GetRasterStatus(p,a) (p)->lpVtbl->GetRasterStatus(p,a)
;#define IDirect3DDevice8_SetGammaRamp(p,a,b) (p)->lpVtbl->SetGammaRamp(p,a,b)
;#define IDirect3DDevice8_GetGammaRamp(p,a) (p)->lpVtbl->GetGammaRamp(p,a)
;#define IDirect3DDevice8_CreateTexture(p,a,b,c,d,e,f,g) (p)->lpVtbl->CreateTexture(p,a,b,c,d,e,f,g)
;#define IDirect3DDevice8_CreateVolumeTexture(p,a,b,c,d,e,f,g,h) (p)->lpVtbl->CreateVolumeTexture(p,a,b,c,d,e,f,g,h)
;#define IDirect3DDevice8_CreateCubeTexture(p,a,b,c,d,e,f) (p)->lpVtbl->CreateCubeTexture(p,a,b,c,d,e,f)
;#define IDirect3DDevice8_CreateVertexBuffer(p,a,b,c,d,e) (p)->lpVtbl->CreateVertexBuffer(p,a,b,c,d,e)
;#define IDirect3DDevice8_CreateIndexBuffer(p,a,b,c,d,e) (p)->lpVtbl->CreateIndexBuffer(p,a,b,c,d,e)
;#define IDirect3DDevice8_CreateRenderTarget(p,a,b,c,d,e,f) (p)->lpVtbl->CreateRenderTarget(p,a,b,c,d,e,f)
;#define IDirect3DDevice8_CreateDepthStencilSurface(p,a,b,c,d,e) (p)->lpVtbl->CreateDepthStencilSurface(p,a,b,c,d,e)
;#define IDirect3DDevice8_CreateImageSurface(p,a,b,c,d) (p)->lpVtbl->CreateImageSurface(p,a,b,c,d)
;#define IDirect3DDevice8_CopyRects(p,a,b,c,d,e) (p)->lpVtbl->CopyRects(p,a,b,c,d,e)
;#define IDirect3DDevice8_UpdateTexture(p,a,b) (p)->lpVtbl->UpdateTexture(p,a,b)
;#define IDirect3DDevice8_GetFrontBuffer(p,a) (p)->lpVtbl->GetFrontBuffer(p,a)
;#define IDirect3DDevice8_SetRenderTarget(p,a,b) (p)->lpVtbl->SetRenderTarget(p,a,b)
;#define IDirect3DDevice8_GetRenderTarget(p,a) (p)->lpVtbl->GetRenderTarget(p,a)
;#define IDirect3DDevice8_GetDepthStencilSurface(p,a) (p)->lpVtbl->GetDepthStencilSurface(p,a)
;#define IDirect3DDevice8_BeginScene(p) (p)->lpVtbl->BeginScene(p)
;#define IDirect3DDevice8_EndScene(p) (p)->lpVtbl->EndScene(p)
;#define IDirect3DDevice8_Clear(p,a,b,c,d,e,f) (p)->lpVtbl->Clear(p,a,b,c,d,e,f)
;#define IDirect3DDevice8_SetTransform(p,a,b) (p)->lpVtbl->SetTransform(p,a,b)
;#define IDirect3DDevice8_GetTransform(p,a,b) (p)->lpVtbl->GetTransform(p,a,b)
;#define IDirect3DDevice8_MultiplyTransform(p,a,b) (p)->lpVtbl->MultiplyTransform(p,a,b)
;#define IDirect3DDevice8_SetViewport(p,a) (p)->lpVtbl->SetViewport(p,a)
;#define IDirect3DDevice8_GetViewport(p,a) (p)->lpVtbl->GetViewport(p,a)
;#define IDirect3DDevice8_SetMaterial(p,a) (p)->lpVtbl->SetMaterial(p,a)
;#define IDirect3DDevice8_GetMaterial(p,a) (p)->lpVtbl->GetMaterial(p,a)
;#define IDirect3DDevice8_SetLight(p,a,b) (p)->lpVtbl->SetLight(p,a,b)
;#define IDirect3DDevice8_GetLight(p,a,b) (p)->lpVtbl->GetLight(p,a,b)
;#define IDirect3DDevice8_LightEnable(p,a,b) (p)->lpVtbl->LightEnable(p,a,b)
;#define IDirect3DDevice8_GetLightEnable(p,a,b) (p)->lpVtbl->GetLightEnable(p,a,b)
;#define IDirect3DDevice8_SetClipPlane(p,a,b) (p)->lpVtbl->SetClipPlane(p,a,b)
;#define IDirect3DDevice8_GetClipPlane(p,a,b) (p)->lpVtbl->GetClipPlane(p,a,b)
;#define IDirect3DDevice8_SetRenderState(p,a,b) (p)->lpVtbl->SetRenderState(p,a,b)
;#define IDirect3DDevice8_GetRenderState(p,a,b) (p)->lpVtbl->GetRenderState(p,a,b)
;#define IDirect3DDevice8_BeginStateBlock(p) (p)->lpVtbl->BeginStateBlock(p)
;#define IDirect3DDevice8_EndStateBlock(p,a) (p)->lpVtbl->EndStateBlock(p,a)
;#define IDirect3DDevice8_ApplyStateBlock(p,a) (p)->lpVtbl->ApplyStateBlock(p,a)
;#define IDirect3DDevice8_CaptureStateBlock(p,a) (p)->lpVtbl->CaptureStateBlock(p,a)
;#define IDirect3DDevice8_DeleteStateBlock(p,a) (p)->lpVtbl->DeleteStateBlock(p,a)
;#define IDirect3DDevice8_CreateStateBlock(p,a,b) (p)->lpVtbl->CreateStateBlock(p,a,b)
;#define IDirect3DDevice8_SetClipStatus(p,a) (p)->lpVtbl->SetClipStatus(p,a)
;#define IDirect3DDevice8_GetClipStatus(p,a) (p)->lpVtbl->GetClipStatus(p,a)
;#define IDirect3DDevice8_GetTexture(p,a,b) (p)->lpVtbl->GetTexture(p,a,b)
;#define IDirect3DDevice8_SetTexture(p,a,b) (p)->lpVtbl->SetTexture(p,a,b)
;#define IDirect3DDevice8_GetTextureStageState(p,a,b,c) (p)->lpVtbl->GetTextureStageState(p,a,b,c)
;#define IDirect3DDevice8_SetTextureStageState(p,a,b,c) (p)->lpVtbl->SetTextureStageState(p,a,b,c)
;#define IDirect3DDevice8_ValidateDevice(p,a) (p)->lpVtbl->ValidateDevice(p,a)
;#define IDirect3DDevice8_GetInfo(p,a,b,c) (p)->lpVtbl->GetInfo(p,a,b,c)
;#define IDirect3DDevice8_SetPaletteEntries(p,a,b) (p)->lpVtbl->SetPaletteEntries(p,a,b)
;#define IDirect3DDevice8_GetPaletteEntries(p,a,b) (p)->lpVtbl->GetPaletteEntries(p,a,b)
;#define IDirect3DDevice8_SetCurrentTexturePalette(p,a) (p)->lpVtbl->SetCurrentTexturePalette(p,a)
;#define IDirect3DDevice8_GetCurrentTexturePalette(p,a) (p)->lpVtbl->GetCurrentTexturePalette(p,a)
;#define IDirect3DDevice8_DrawPrimitive(p,a,b,c) (p)->lpVtbl->DrawPrimitive(p,a,b,c)
;#define IDirect3DDevice8_DrawIndexedPrimitive(p,a,b,c,d,e) (p)->lpVtbl->DrawIndexedPrimitive(p,a,b,c,d,e)
;#define IDirect3DDevice8_DrawPrimitiveUP(p,a,b,c,d) (p)->lpVtbl->DrawPrimitiveUP(p,a,b,c,d)
;#define IDirect3DDevice8_DrawIndexedPrimitiveUP(p,a,b,c,d,e,f,g,h) (p)->lpVtbl->DrawIndexedPrimitiveUP(p,a,b,c,d,e,f,g,h)
;#define IDirect3DDevice8_ProcessVertices(p,a,b,c,d,e) (p)->lpVtbl->ProcessVertices(p,a,b,c,d,e)
;#define IDirect3DDevice8_CreateVertexShader(p,a,b,c,d) (p)->lpVtbl->CreateVertexShader(p,a,b,c,d)
;#define IDirect3DDevice8_SetVertexShader(p,a) (p)->lpVtbl->SetVertexShader(p,a)
;#define IDirect3DDevice8_GetVertexShader(p,a) (p)->lpVtbl->GetVertexShader(p,a)
;#define IDirect3DDevice8_DeleteVertexShader(p,a) (p)->lpVtbl->DeleteVertexShader(p,a)
;#define IDirect3DDevice8_SetVertexShaderConstant(p,a,b,c) (p)->lpVtbl->SetVertexShaderConstant(p,a,b,c)
;#define IDirect3DDevice8_GetVertexShaderConstant(p,a,b,c) (p)->lpVtbl->GetVertexShaderConstant(p,a,b,c)
;#define IDirect3DDevice8_GetVertexShaderDeclaration(p,a,b,c) (p)->lpVtbl->GetVertexShaderDeclaration(p,a,b,c)
;#define IDirect3DDevice8_GetVertexShaderFunction(p,a,b,c) (p)->lpVtbl->GetVertexShaderFunction(p,a,b,c)
;#define IDirect3DDevice8_SetStreamSource(p,a,b,c) (p)->lpVtbl->SetStreamSource(p,a,b,c)
;#define IDirect3DDevice8_GetStreamSource(p,a,b,c) (p)->lpVtbl->GetStreamSource(p,a,b,c)
;#define IDirect3DDevice8_SetIndices(p,a,b) (p)->lpVtbl->SetIndices(p,a,b)
;#define IDirect3DDevice8_GetIndices(p,a,b) (p)->lpVtbl->GetIndices(p,a,b)
;#define IDirect3DDevice8_CreatePixelShader(p,a,b) (p)->lpVtbl->CreatePixelShader(p,a,b)
;#define IDirect3DDevice8_SetPixelShader(p,a) (p)->lpVtbl->SetPixelShader(p,a)
;#define IDirect3DDevice8_GetPixelShader(p,a) (p)->lpVtbl->GetPixelShader(p,a)
;#define IDirect3DDevice8_DeletePixelShader(p,a) (p)->lpVtbl->DeletePixelShader(p,a)
;#define IDirect3DDevice8_SetPixelShaderConstant(p,a,b,c) (p)->lpVtbl->SetPixelShaderConstant(p,a,b,c)
;#define IDirect3DDevice8_GetPixelShaderConstant(p,a,b,c) (p)->lpVtbl->GetPixelShaderConstant(p,a,b,c)
;#define IDirect3DDevice8_GetPixelShaderFunction(p,a,b,c) (p)->lpVtbl->GetPixelShaderFunction(p,a,b,c)
;#define IDirect3DDevice8_DrawRectPatch(p,a,b,c) (p)->lpVtbl->DrawRectPatch(p,a,b,c)
;#define IDirect3DDevice8_DrawTriPatch(p,a,b,c) (p)->lpVtbl->DrawTriPatch(p,a,b,c)
;#define IDirect3DDevice8_DeletePatch(p,a) (p)->lpVtbl->DeletePatch(p,a)
;#else
;#define IDirect3DDevice8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3DDevice8_AddRef(p) (p)->AddRef()
;#define IDirect3DDevice8_Release(p) (p)->Release()
;#define IDirect3DDevice8_TestCooperativeLevel(p) (p)->TestCooperativeLevel()
;#define IDirect3DDevice8_GetAvailableTextureMem(p) (p)->GetAvailableTextureMem()
;#define IDirect3DDevice8_ResourceManagerDiscardBytes(p,a) (p)->ResourceManagerDiscardBytes(a)
;#define IDirect3DDevice8_GetDirect3D(p,a) (p)->GetDirect3D(a)
;#define IDirect3DDevice8_GetDeviceCaps(p,a) (p)->GetDeviceCaps(a)
;#define IDirect3DDevice8_GetDisplayMode(p,a) (p)->GetDisplayMode(a)
;#define IDirect3DDevice8_GetCreationParameters(p,a) (p)->GetCreationParameters(a)
;#define IDirect3DDevice8_SetCursorProperties(p,a,b,c) (p)->SetCursorProperties(a,b,c)
;#define IDirect3DDevice8_SetCursorPosition(p,a,b,c) (p)->SetCursorPosition(a,b,c)
;#define IDirect3DDevice8_ShowCursor(p,a) (p)->ShowCursor(a)
;#define IDirect3DDevice8_CreateAdditionalSwapChain(p,a,b) (p)->CreateAdditionalSwapChain(a,b)
;#define IDirect3DDevice8_Reset(p,a) (p)->Reset(a)
;#define IDirect3DDevice8_Present(p,a,b,c,d) (p)->Present(a,b,c,d)
;#define IDirect3DDevice8_GetBackBuffer(p,a,b,c) (p)->GetBackBuffer(a,b,c)
;#define IDirect3DDevice8_GetRasterStatus(p,a) (p)->GetRasterStatus(a)
;#define IDirect3DDevice8_SetGammaRamp(p,a,b) (p)->SetGammaRamp(a,b)
;#define IDirect3DDevice8_GetGammaRamp(p,a) (p)->GetGammaRamp(a)
;#define IDirect3DDevice8_CreateTexture(p,a,b,c,d,e,f,g) (p)->CreateTexture(a,b,c,d,e,f,g)
;#define IDirect3DDevice8_CreateVolumeTexture(p,a,b,c,d,e,f,g,h) (p)->CreateVolumeTexture(a,b,c,d,e,f,g,h)
;#define IDirect3DDevice8_CreateCubeTexture(p,a,b,c,d,e,f) (p)->CreateCubeTexture(a,b,c,d,e,f)
;#define IDirect3DDevice8_CreateVertexBuffer(p,a,b,c,d,e) (p)->CreateVertexBuffer(a,b,c,d,e)
;#define IDirect3DDevice8_CreateIndexBuffer(p,a,b,c,d,e) (p)->CreateIndexBuffer(a,b,c,d,e)
;#define IDirect3DDevice8_CreateRenderTarget(p,a,b,c,d,e,f) (p)->CreateRenderTarget(a,b,c,d,e,f)
;#define IDirect3DDevice8_CreateDepthStencilSurface(p,a,b,c,d,e) (p)->CreateDepthStencilSurface(a,b,c,d,e)
;#define IDirect3DDevice8_CreateImageSurface(p,a,b,c,d) (p)->CreateImageSurface(a,b,c,d)
;#define IDirect3DDevice8_CopyRects(p,a,b,c,d,e) (p)->CopyRects(a,b,c,d,e)
;#define IDirect3DDevice8_UpdateTexture(p,a,b) (p)->UpdateTexture(a,b)
;#define IDirect3DDevice8_GetFrontBuffer(p,a) (p)->GetFrontBuffer(a)
;#define IDirect3DDevice8_SetRenderTarget(p,a,b) (p)->SetRenderTarget(a,b)
;#define IDirect3DDevice8_GetRenderTarget(p,a) (p)->GetRenderTarget(a)
;#define IDirect3DDevice8_GetDepthStencilSurface(p,a) (p)->GetDepthStencilSurface(a)
;#define IDirect3DDevice8_BeginScene(p) (p)->BeginScene()
;#define IDirect3DDevice8_EndScene(p) (p)->EndScene()
;#define IDirect3DDevice8_Clear(p,a,b,c,d,e,f) (p)->Clear(a,b,c,d,e,f)
;#define IDirect3DDevice8_SetTransform(p,a,b) (p)->SetTransform(a,b)
;#define IDirect3DDevice8_GetTransform(p,a,b) (p)->GetTransform(a,b)
;#define IDirect3DDevice8_MultiplyTransform(p,a,b) (p)->MultiplyTransform(a,b)
;#define IDirect3DDevice8_SetViewport(p,a) (p)->SetViewport(a)
;#define IDirect3DDevice8_GetViewport(p,a) (p)->GetViewport(a)
;#define IDirect3DDevice8_SetMaterial(p,a) (p)->SetMaterial(a)
;#define IDirect3DDevice8_GetMaterial(p,a) (p)->GetMaterial(a)
;#define IDirect3DDevice8_SetLight(p,a,b) (p)->SetLight(a,b)
;#define IDirect3DDevice8_GetLight(p,a,b) (p)->GetLight(a,b)
;#define IDirect3DDevice8_LightEnable(p,a,b) (p)->LightEnable(a,b)
;#define IDirect3DDevice8_GetLightEnable(p,a,b) (p)->GetLightEnable(a,b)
;#define IDirect3DDevice8_SetClipPlane(p,a,b) (p)->SetClipPlane(a,b)
;#define IDirect3DDevice8_GetClipPlane(p,a,b) (p)->GetClipPlane(a,b)
;#define IDirect3DDevice8_SetRenderState(p,a,b) (p)->SetRenderState(a,b)
;#define IDirect3DDevice8_GetRenderState(p,a,b) (p)->GetRenderState(a,b)
;#define IDirect3DDevice8_BeginStateBlock(p) (p)->BeginStateBlock()
;#define IDirect3DDevice8_EndStateBlock(p,a) (p)->EndStateBlock(a)
;#define IDirect3DDevice8_ApplyStateBlock(p,a) (p)->ApplyStateBlock(a)
;#define IDirect3DDevice8_CaptureStateBlock(p,a) (p)->CaptureStateBlock(a)
;#define IDirect3DDevice8_DeleteStateBlock(p,a) (p)->DeleteStateBlock(a)
;#define IDirect3DDevice8_CreateStateBlock(p,a,b) (p)->CreateStateBlock(a,b)
;#define IDirect3DDevice8_SetClipStatus(p,a) (p)->SetClipStatus(a)
;#define IDirect3DDevice8_GetClipStatus(p,a) (p)->GetClipStatus(a)
;#define IDirect3DDevice8_GetTexture(p,a,b) (p)->GetTexture(a,b)
;#define IDirect3DDevice8_SetTexture(p,a,b) (p)->SetTexture(a,b)
;#define IDirect3DDevice8_GetTextureStageState(p,a,b,c) (p)->GetTextureStageState(a,b,c)
;#define IDirect3DDevice8_SetTextureStageState(p,a,b,c) (p)->SetTextureStageState(a,b,c)
;#define IDirect3DDevice8_ValidateDevice(p,a) (p)->ValidateDevice(a)
;#define IDirect3DDevice8_GetInfo(p,a,b,c) (p)->GetInfo(a,b,c)
;#define IDirect3DDevice8_SetPaletteEntries(p,a,b) (p)->SetPaletteEntries(a,b)
;#define IDirect3DDevice8_GetPaletteEntries(p,a,b) (p)->GetPaletteEntries(a,b)
;#define IDirect3DDevice8_SetCurrentTexturePalette(p,a) (p)->SetCurrentTexturePalette(a)
;#define IDirect3DDevice8_GetCurrentTexturePalette(p,a) (p)->GetCurrentTexturePalette(a)
;#define IDirect3DDevice8_DrawPrimitive(p,a,b,c) (p)->DrawPrimitive(a,b,c)
;#define IDirect3DDevice8_DrawIndexedPrimitive(p,a,b,c,d,e) (p)->DrawIndexedPrimitive(a,b,c,d,e)
;#define IDirect3DDevice8_DrawPrimitiveUP(p,a,b,c,d) (p)->DrawPrimitiveUP(a,b,c,d)
;#define IDirect3DDevice8_DrawIndexedPrimitiveUP(p,a,b,c,d,e,f,g,h) (p)->DrawIndexedPrimitiveUP(a,b,c,d,e,f,g,h)
;#define IDirect3DDevice8_ProcessVertices(p,a,b,c,d,e) (p)->ProcessVertices(a,b,c,d,e)
;#define IDirect3DDevice8_CreateVertexShader(p,a,b,c,d) (p)->CreateVertexShader(a,b,c,d)
;#define IDirect3DDevice8_SetVertexShader(p,a) (p)->SetVertexShader(a)
;#define IDirect3DDevice8_GetVertexShader(p,a) (p)->GetVertexShader(a)
;#define IDirect3DDevice8_DeleteVertexShader(p,a) (p)->DeleteVertexShader(a)
;#define IDirect3DDevice8_SetVertexShaderConstant(p,a,b,c) (p)->SetVertexShaderConstant(a,b,c)
;#define IDirect3DDevice8_GetVertexShaderConstant(p,a,b,c) (p)->GetVertexShaderConstant(a,b,c)
;#define IDirect3DDevice8_GetVertexShaderDeclaration(p,a,b,c) (p)->GetVertexShaderDeclaration(a,b,c)
;#define IDirect3DDevice8_GetVertexShaderFunction(p,a,b,c) (p)->GetVertexShaderFunction(a,b,c)
;#define IDirect3DDevice8_SetStreamSource(p,a,b,c) (p)->SetStreamSource(a,b,c)
;#define IDirect3DDevice8_GetStreamSource(p,a,b,c) (p)->GetStreamSource(a,b,c)
;#define IDirect3DDevice8_SetIndices(p,a,b) (p)->SetIndices(a,b)
;#define IDirect3DDevice8_GetIndices(p,a,b) (p)->GetIndices(a,b)
;#define IDirect3DDevice8_CreatePixelShader(p,a,b) (p)->CreatePixelShader(a,b)
;#define IDirect3DDevice8_SetPixelShader(p,a) (p)->SetPixelShader(a)
;#define IDirect3DDevice8_GetPixelShader(p,a) (p)->GetPixelShader(a)
;#define IDirect3DDevice8_DeletePixelShader(p,a) (p)->DeletePixelShader(a)
;#define IDirect3DDevice8_SetPixelShaderConstant(p,a,b,c) (p)->SetPixelShaderConstant(a,b,c)
;#define IDirect3DDevice8_GetPixelShaderConstant(p,a,b,c) (p)->GetPixelShaderConstant(a,b,c)
;#define IDirect3DDevice8_GetPixelShaderFunction(p,a,b,c) (p)->GetPixelShaderFunction(a,b,c)
;#define IDirect3DDevice8_DrawRectPatch(p,a,b,c) (p)->DrawRectPatch(a,b,c)
;#define IDirect3DDevice8_DrawTriPatch(p,a,b,c) (p)->DrawTriPatch(a,b,c)
;#define IDirect3DDevice8_DeletePatch(p,a) (p)->DeletePatch(a)
;#endif



;#undef INTERFACE
;#define INTERFACE IDirect3DSwapChain8

DECLARE_INTERFACE <IDirect3DSwapChain8_>
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3DSwapChain8 methods ***/
    STDMETHOD <Present>,:DWORD,:DWORD,:DWORD,:DWORD  ;,(THIS_ CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion) PURE;
    STDMETHOD <GetBackBuffer>,:DWORD,:DWORD,:DWORD  ;(THIS_ UINT BackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface8** ppBackBuffer) PURE;
;};

LPDIRECT3DSWAPCHAIN8 typedef PTR
PDIRECT3DSWAPCHAIN8 typedef PTR
;typedef struct IDirect3DSwapChain8 *LPDIRECT3DSWAPCHAIN8, *PDIRECT3DSWAPCHAIN8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3DSwapChain8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3DSwapChain8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3DSwapChain8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3DSwapChain8_Present(p,a,b,c,d) (p)->lpVtbl->Present(p,a,b,c,d)
;#define IDirect3DSwapChain8_GetBackBuffer(p,a,b,c) (p)->lpVtbl->GetBackBuffer(p,a,b,c)
;#else
;#define IDirect3DSwapChain8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3DSwapChain8_AddRef(p) (p)->AddRef()
;#define IDirect3DSwapChain8_Release(p) (p)->Release()
;#define IDirect3DSwapChain8_Present(p,a,b,c,d) (p)->Present(a,b,c,d)
;#define IDirect3DSwapChain8_GetBackBuffer(p,a,b,c) (p)->GetBackBuffer(a,b,c)
;#endif



;#undef INTERFACE
;#define INTERFACE IDirect3DResource8

DECLARE_INTERFACE <IDirect3DResource8_>
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3DResource8 methods ***/
    STDMETHOD <GetDevice>,:DWORD                                ;(THIS_ IDirect3DDevice8** ppDevice) PURE;
    STDMETHOD <SetPrivateData>,:DWORD,:DWORD,:DWORD,:DWORD      ;(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
    STDMETHOD <GetPrivateData>,:DWORD,:DWORD,:DWORD             ;(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <FreePrivateData>,:DWORD                          ;(THIS_ REFGUID refguid) PURE;
    STDMETHOD <SetPriority>,:DWORD                              ;(THIS_ DWORD PriorityNew) PURE;
    STDMETHOD <GetPriority>                                     ;(THIS) PURE;
    STDMETHOD <PreLoad>                                         ;(THIS) PURE;
    STDMETHOD <GetType>                                         ;(THIS) PURE;
;};

LPDIRECT3DRESOURCE8 typedef PTR
PDIRECT3DRESOURCE8 typedef PTR
;typedef struct IDirect3DResource8 *LPDIRECT3DRESOURCE8, *PDIRECT3DRESOURCE8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3DResource8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3DResource8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3DResource8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3DResource8_GetDevice(p,a) (p)->lpVtbl->GetDevice(p,a)
;#define IDirect3DResource8_SetPrivateData(p,a,b,c,d) (p)->lpVtbl->SetPrivateData(p,a,b,c,d)
;#define IDirect3DResource8_GetPrivateData(p,a,b,c) (p)->lpVtbl->GetPrivateData(p,a,b,c)
;#define IDirect3DResource8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
;#define IDirect3DResource8_SetPriority(p,a) (p)->lpVtbl->SetPriority(p,a)
;#define IDirect3DResource8_GetPriority(p) (p)->lpVtbl->GetPriority(p)
;#define IDirect3DResource8_PreLoad(p) (p)->lpVtbl->PreLoad(p)
;#define IDirect3DResource8_GetType(p) (p)->lpVtbl->GetType(p)
;#else
;#define IDirect3DResource8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3DResource8_AddRef(p) (p)->AddRef()
;#define IDirect3DResource8_Release(p) (p)->Release()
;#define IDirect3DResource8_GetDevice(p,a) (p)->GetDevice(a)
;#define IDirect3DResource8_SetPrivateData(p,a,b,c,d) (p)->SetPrivateData(a,b,c,d)
;#define IDirect3DResource8_GetPrivateData(p,a,b,c) (p)->GetPrivateData(a,b,c)
;#define IDirect3DResource8_FreePrivateData(p,a) (p)->FreePrivateData(a)
;#define IDirect3DResource8_SetPriority(p,a) (p)->SetPriority(a)
;#define IDirect3DResource8_GetPriority(p) (p)->GetPriority()
;#define IDirect3DResource8_PreLoad(p) (p)->PreLoad()
;#define IDirect3DResource8_GetType(p) (p)->GetType()
;#endif




;#undef INTERFACE
;#define INTERFACE IDirect3DBaseTexture8

DECLARE_INTERFACE <IDirect3DBaseTexture8_>       ;, IDirect3DResource8)
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3DResource8 methods ***/
    STDMETHOD <GetDevice>,:DWORD                                    ;(THIS_ IDirect3DDevice8** ppDevice) PURE;
    STDMETHOD <SetPrivateData>,:DWORD,:DWORD,:DWORD,:DWORD          ;(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
    STDMETHOD <GetPrivateData>,:DWORD,:DWORD,:DWORD                 ;(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <FreePrivateData>,:DWORD                              ;(THIS_ REFGUID refguid) PURE;
    STDMETHOD <SetPriority>,:DWORD                                  ;(THIS_ DWORD PriorityNew) PURE;
    STDMETHOD <GetPriority>                                         ;(THIS) PURE;
    STDMETHOD <PreLoad>                                             ;(THIS) PURE;
    STDMETHOD <GetType>                                             ;(THIS) PURE;
    STDMETHOD <SetLOD>,:DWORD                                       ;(THIS_ DWORD LODNew) PURE;
    STDMETHOD <GetLOD>                                              ;(THIS) PURE;
    STDMETHOD <GetLevelCount>                                       ;(THIS) PURE;
;};

LPDIRECT3DBASETEXTURE8  typedef PTR
PDIRECT3DBASETEXTURE8  typedef PTR
;typedef struct IDirect3DBaseTexture8 *LPDIRECT3DBASETEXTURE8, *PDIRECT3DBASETEXTURE8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3DBaseTexture8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3DBaseTexture8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3DBaseTexture8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3DBaseTexture8_GetDevice(p,a) (p)->lpVtbl->GetDevice(p,a)
;#define IDirect3DBaseTexture8_SetPrivateData(p,a,b,c,d) (p)->lpVtbl->SetPrivateData(p,a,b,c,d)
;#define IDirect3DBaseTexture8_GetPrivateData(p,a,b,c) (p)->lpVtbl->GetPrivateData(p,a,b,c)
;#define IDirect3DBaseTexture8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
;#define IDirect3DBaseTexture8_SetPriority(p,a) (p)->lpVtbl->SetPriority(p,a)
;#define IDirect3DBaseTexture8_GetPriority(p) (p)->lpVtbl->GetPriority(p)
;#define IDirect3DBaseTexture8_PreLoad(p) (p)->lpVtbl->PreLoad(p)
;#define IDirect3DBaseTexture8_GetType(p) (p)->lpVtbl->GetType(p)
;#define IDirect3DBaseTexture8_SetLOD(p,a) (p)->lpVtbl->SetLOD(p,a)
;#define IDirect3DBaseTexture8_GetLOD(p) (p)->lpVtbl->GetLOD(p)
;#define IDirect3DBaseTexture8_GetLevelCount(p) (p)->lpVtbl->GetLevelCount(p)
;#else
;#define IDirect3DBaseTexture8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3DBaseTexture8_AddRef(p) (p)->AddRef()
;#define IDirect3DBaseTexture8_Release(p) (p)->Release()
;#define IDirect3DBaseTexture8_GetDevice(p,a) (p)->GetDevice(a)
;#define IDirect3DBaseTexture8_SetPrivateData(p,a,b,c,d) (p)->SetPrivateData(a,b,c,d)
;#define IDirect3DBaseTexture8_GetPrivateData(p,a,b,c) (p)->GetPrivateData(a,b,c)
;#define IDirect3DBaseTexture8_FreePrivateData(p,a) (p)->FreePrivateData(a)
;#define IDirect3DBaseTexture8_SetPriority(p,a) (p)->SetPriority(a)
;#define IDirect3DBaseTexture8_GetPriority(p) (p)->GetPriority()
;#define IDirect3DBaseTexture8_PreLoad(p) (p)->PreLoad()
;#define IDirect3DBaseTexture8_GetType(p) (p)->GetType()
;#define IDirect3DBaseTexture8_SetLOD(p,a) (p)->SetLOD(a)
;#define IDirect3DBaseTexture8_GetLOD(p) (p)->GetLOD()
;#define IDirect3DBaseTexture8_GetLevelCount(p) (p)->GetLevelCount()
;#endif





;#undef INTERFACE
;#define INTERFACE IDirect3DTexture8

DECLARE_INTERFACE <IDirect3DTexture8_>           ;, IDirect3DBaseTexture8)
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3DBaseTexture8 methods ***/
    STDMETHOD <GetDevice>,:DWORD                                            ;(THIS_ IDirect3DDevice8** ppDevice) PURE;
    STDMETHOD <SetPrivateData>,:DWORD,:DWORD,:DWORD,:DWORD                  ;(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
    STDMETHOD <GetPrivateData>,:DWORD,:DWORD,:DWORD                         ;(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <FreePrivateData>,:DWORD                                      ;(THIS_ REFGUID refguid) PURE;
    STDMETHOD <SetPriority>,:DWORD                                          ;(THIS_ DWORD PriorityNew) PURE;
    STDMETHOD <GetPriority>                                                 ;(THIS) PURE;
    STDMETHOD <PreLoad>                                                     ;(THIS) PURE;
    STDMETHOD <GetType>                                                     ;(THIS) PURE;
    STDMETHOD <SetLOD>,:DWORD                                               ;(THIS_ DWORD LODNew) PURE;
    STDMETHOD <GetLOD>                                                      ;(THIS) PURE;
    STDMETHOD <GetLevelCount>                                               ;(THIS) PURE;
    STDMETHOD <GetLevelDesc>,:DWORD,:DWORD                                  ;(THIS_ UINT Level,D3DSURFACE_DESC *pDesc) PURE;
    STDMETHOD <GetSurfaceLevel>,:DWORD,:DWORD                               ;(THIS_ UINT Level,IDirect3DSurface8** ppSurfaceLevel) PURE;
    STDMETHOD <LockRect>,:DWORD,:DWORD,:DWORD,:DWORD                        ;(THIS_ UINT Level,D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) PURE;
    STDMETHOD <UnlockRect>,:DWORD                                           ;(THIS_ UINT Level) PURE;
    STDMETHOD <AddDirtyRect>,:DWORD                                         ;(THIS_ CONST RECT* pDirtyRect) PURE;
;};

LPDIRECT3DTEXTURE8  typedef PTR
PDIRECT3DTEXTURE8 typedef PTR
;typedef struct IDirect3DTexture8 *LPDIRECT3DTEXTURE8, *PDIRECT3DTEXTURE8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3DTexture8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3DTexture8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3DTexture8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3DTexture8_GetDevice(p,a) (p)->lpVtbl->GetDevice(p,a)
;#define IDirect3DTexture8_SetPrivateData(p,a,b,c,d) (p)->lpVtbl->SetPrivateData(p,a,b,c,d)
;#define IDirect3DTexture8_GetPrivateData(p,a,b,c) (p)->lpVtbl->GetPrivateData(p,a,b,c)
;#define IDirect3DTexture8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
;#define IDirect3DTexture8_SetPriority(p,a) (p)->lpVtbl->SetPriority(p,a)
;#define IDirect3DTexture8_GetPriority(p) (p)->lpVtbl->GetPriority(p)
;#define IDirect3DTexture8_PreLoad(p) (p)->lpVtbl->PreLoad(p)
;#define IDirect3DTexture8_GetType(p) (p)->lpVtbl->GetType(p)
;#define IDirect3DTexture8_SetLOD(p,a) (p)->lpVtbl->SetLOD(p,a)
;#define IDirect3DTexture8_GetLOD(p) (p)->lpVtbl->GetLOD(p)
;#define IDirect3DTexture8_GetLevelCount(p) (p)->lpVtbl->GetLevelCount(p)
;#define IDirect3DTexture8_GetLevelDesc(p,a,b) (p)->lpVtbl->GetLevelDesc(p,a,b)
;#define IDirect3DTexture8_GetSurfaceLevel(p,a,b) (p)->lpVtbl->GetSurfaceLevel(p,a,b)
;#define IDirect3DTexture8_LockRect(p,a,b,c,d) (p)->lpVtbl->LockRect(p,a,b,c,d)
;#define IDirect3DTexture8_UnlockRect(p,a) (p)->lpVtbl->UnlockRect(p,a)
;#define IDirect3DTexture8_AddDirtyRect(p,a) (p)->lpVtbl->AddDirtyRect(p,a)
;#else
;#define IDirect3DTexture8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3DTexture8_AddRef(p) (p)->AddRef()
;#define IDirect3DTexture8_Release(p) (p)->Release()
;#define IDirect3DTexture8_GetDevice(p,a) (p)->GetDevice(a)
;#define IDirect3DTexture8_SetPrivateData(p,a,b,c,d) (p)->SetPrivateData(a,b,c,d)
;#define IDirect3DTexture8_GetPrivateData(p,a,b,c) (p)->GetPrivateData(a,b,c)
;#define IDirect3DTexture8_FreePrivateData(p,a) (p)->FreePrivateData(a)
;#define IDirect3DTexture8_SetPriority(p,a) (p)->SetPriority(a)
;#define IDirect3DTexture8_GetPriority(p) (p)->GetPriority()
;#define IDirect3DTexture8_PreLoad(p) (p)->PreLoad()
;#define IDirect3DTexture8_GetType(p) (p)->GetType()
;#define IDirect3DTexture8_SetLOD(p,a) (p)->SetLOD(a)
;#define IDirect3DTexture8_GetLOD(p) (p)->GetLOD()
;#define IDirect3DTexture8_GetLevelCount(p) (p)->GetLevelCount()
;#define IDirect3DTexture8_GetLevelDesc(p,a,b) (p)->GetLevelDesc(a,b)
;#define IDirect3DTexture8_GetSurfaceLevel(p,a,b) (p)->GetSurfaceLevel(a,b)
;#define IDirect3DTexture8_LockRect(p,a,b,c,d) (p)->LockRect(a,b,c,d)
;#define IDirect3DTexture8_UnlockRect(p,a) (p)->UnlockRect(a)
;#define IDirect3DTexture8_AddDirtyRect(p,a) (p)->AddDirtyRect(a)
;#endif





;#undef INTERFACE
;#define INTERFACE IDirect3DVolumeTexture8

DECLARE_INTERFACE <IDirect3DVolumeTexture8_>     ;, IDirect3DBaseTexture8)
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3DBaseTexture8 methods ***/
    STDMETHOD <GetDevice>,:DWORD                                ;(THIS_ IDirect3DDevice8** ppDevice) PURE;
    STDMETHOD <SetPrivateData>,:DWORD,:DWORD,:DWORD,:DWORD      ;(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
    STDMETHOD <GetPrivateData>,:DWORD,:DWORD,:DWORD             ;(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <FreePrivateData>,:DWORD                          ;(THIS_ REFGUID refguid) PURE;
    STDMETHOD <SetPriority>,:DWORD                              ;(THIS_ DWORD PriorityNew) PURE;
    STDMETHOD <GetPriority>                                     ;(THIS) PURE;
    STDMETHOD <PreLoad>                                         ;(THIS) PURE;
    STDMETHOD <GetType>                                         ;(THIS) PURE;
    STDMETHOD <SetLOD>,:DWORD                                   ;(THIS_ DWORD LODNew) PURE;
    STDMETHOD <GetLOD>                                          ;(THIS) PURE;
    STDMETHOD <GetLevelCount>                                   ;(THIS) PURE;
    STDMETHOD <GetLevelDesc>,:DWORD,:DWORD                      ;(THIS_ UINT Level,D3DVOLUME_DESC *pDesc) PURE;
    STDMETHOD <GetVolumeLevel>,:DWORD,:DWORD                    ;(THIS_ UINT Level,IDirect3DVolume8** ppVolumeLevel) PURE;
    STDMETHOD <LockBox>,:DWORD,:DWORD,:DWORD,:DWORD             ;(THIS_ UINT Level,D3DLOCKED_BOX* pLockedVolume,CONST D3DBOX* pBox,DWORD Flags) PURE;
    STDMETHOD <UnlockBox>,:DWORD                                ;(THIS_ UINT Level) PURE;
    STDMETHOD <AddDirtyBox>,:DWORD                              ;(THIS_ CONST D3DBOX* pDirtyBox) PURE;
;};

LPDIRECT3DVOLUMETEXTURE8    typedef PTR
PDIRECT3DVOLUMETEXTURE8    typedef PTR
;typedef struct IDirect3DVolumeTexture8 *LPDIRECT3DVOLUMETEXTURE8, *PDIRECT3DVOLUMETEXTURE8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3DVolumeTexture8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3DVolumeTexture8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3DVolumeTexture8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3DVolumeTexture8_GetDevice(p,a) (p)->lpVtbl->GetDevice(p,a)
;#define IDirect3DVolumeTexture8_SetPrivateData(p,a,b,c,d) (p)->lpVtbl->SetPrivateData(p,a,b,c,d)
;#define IDirect3DVolumeTexture8_GetPrivateData(p,a,b,c) (p)->lpVtbl->GetPrivateData(p,a,b,c)
;#define IDirect3DVolumeTexture8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
;#define IDirect3DVolumeTexture8_SetPriority(p,a) (p)->lpVtbl->SetPriority(p,a)
;#define IDirect3DVolumeTexture8_GetPriority(p) (p)->lpVtbl->GetPriority(p)
;#define IDirect3DVolumeTexture8_PreLoad(p) (p)->lpVtbl->PreLoad(p)
;#define IDirect3DVolumeTexture8_GetType(p) (p)->lpVtbl->GetType(p)
;#define IDirect3DVolumeTexture8_SetLOD(p,a) (p)->lpVtbl->SetLOD(p,a)
;#define IDirect3DVolumeTexture8_GetLOD(p) (p)->lpVtbl->GetLOD(p)
;#define IDirect3DVolumeTexture8_GetLevelCount(p) (p)->lpVtbl->GetLevelCount(p)
;#define IDirect3DVolumeTexture8_GetLevelDesc(p,a,b) (p)->lpVtbl->GetLevelDesc(p,a,b)
;#define IDirect3DVolumeTexture8_GetVolumeLevel(p,a,b) (p)->lpVtbl->GetVolumeLevel(p,a,b)
;#define IDirect3DVolumeTexture8_LockBox(p,a,b,c,d) (p)->lpVtbl->LockBox(p,a,b,c,d)
;#define IDirect3DVolumeTexture8_UnlockBox(p,a) (p)->lpVtbl->UnlockBox(p,a)
;#define IDirect3DVolumeTexture8_AddDirtyBox(p,a) (p)->lpVtbl->AddDirtyBox(p,a)
;#else
;#define IDirect3DVolumeTexture8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3DVolumeTexture8_AddRef(p) (p)->AddRef()
;#define IDirect3DVolumeTexture8_Release(p) (p)->Release()
;#define IDirect3DVolumeTexture8_GetDevice(p,a) (p)->GetDevice(a)
;#define IDirect3DVolumeTexture8_SetPrivateData(p,a,b,c,d) (p)->SetPrivateData(a,b,c,d)
;#define IDirect3DVolumeTexture8_GetPrivateData(p,a,b,c) (p)->GetPrivateData(a,b,c)
;#define IDirect3DVolumeTexture8_FreePrivateData(p,a) (p)->FreePrivateData(a)
;#define IDirect3DVolumeTexture8_SetPriority(p,a) (p)->SetPriority(a)
;#define IDirect3DVolumeTexture8_GetPriority(p) (p)->GetPriority()
;#define IDirect3DVolumeTexture8_PreLoad(p) (p)->PreLoad()
;#define IDirect3DVolumeTexture8_GetType(p) (p)->GetType()
;#define IDirect3DVolumeTexture8_SetLOD(p,a) (p)->SetLOD(a)
;#define IDirect3DVolumeTexture8_GetLOD(p) (p)->GetLOD()
;#define IDirect3DVolumeTexture8_GetLevelCount(p) (p)->GetLevelCount()
;#define IDirect3DVolumeTexture8_GetLevelDesc(p,a,b) (p)->GetLevelDesc(a,b)
;#define IDirect3DVolumeTexture8_GetVolumeLevel(p,a,b) (p)->GetVolumeLevel(a,b)
;#define IDirect3DVolumeTexture8_LockBox(p,a,b,c,d) (p)->LockBox(a,b,c,d)
;#define IDirect3DVolumeTexture8_UnlockBox(p,a) (p)->UnlockBox(a)
;#define IDirect3DVolumeTexture8_AddDirtyBox(p,a) (p)->AddDirtyBox(a)
;#endif





;#undef INTERFACE
;#define INTERFACE IDirect3DCubeTexture8

DECLARE_INTERFACE <IDirect3DCubeTexture8_>       ;, IDirect3DBaseTexture8)
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3DBaseTexture8 methods ***/
    STDMETHOD <GetDevice>,:DWORD                                ;THIS_ IDirect3DDevice8** ppDevice) PURE;
    STDMETHOD <SetPrivateData>,:DWORD,:DWORD,:DWORD,:DWORD      ;THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
    STDMETHOD <GetPrivateData>,:DWORD,:DWORD,:DWORD             ;THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <FreePrivateData>,:DWORD                          ;THIS_ REFGUID refguid) PURE;
    STDMETHOD <SetPriority>,:DWORD                              ;THIS_ DWORD PriorityNew) PURE;
    STDMETHOD <GetPriority>                                     ;THIS) PURE;
    STDMETHOD <PreLoad>                                         ;THIS) PURE;
    STDMETHOD <GetType>                                         ;THIS) PURE;
    STDMETHOD <SetLOD>,:DWORD                                   ;THIS_ DWORD LODNew) PURE;
    STDMETHOD <GetLOD>                                          ;THIS) PURE;
    STDMETHOD <GetLevelCount>                                   ;THIS) PURE;
    STDMETHOD <GetLevelDesc>,:DWORD,:DWORD                      ;THIS_ UINT Level,D3DSURFACE_DESC *pDesc) PURE;
    STDMETHOD <GetCubeMapSurface>,:DWORD,:DWORD,:DWORD          ;THIS_ D3DCUBEMAP_FACES FaceType,UINT Level,IDirect3DSurface8** ppCubeMapSurface) PURE;
    STDMETHOD <LockRect>,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD     ;THIS_ D3DCUBEMAP_FACES FaceType,UINT Level,D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) PURE;
    STDMETHOD <UnlockRect>,:DWORD,:DWORD                        ;THIS_ D3DCUBEMAP_FACES FaceType,UINT Level) PURE;
    STDMETHOD <AddDirtyRect>,:DWORD,:DWORD                      ;THIS_ D3DCUBEMAP_FACES FaceType,CONST RECT* pDirtyRect) PURE;
;};

LPDIRECT3DCUBETEXTURE8  typedef PTR
PDIRECT3DCUBETEXTURE8  typedef PTR
;typedef struct IDirect3DCubeTexture8 *LPDIRECT3DCUBETEXTURE8, *PDIRECT3DCUBETEXTURE8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3DCubeTexture8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3DCubeTexture8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3DCubeTexture8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3DCubeTexture8_GetDevice(p,a) (p)->lpVtbl->GetDevice(p,a)
;#define IDirect3DCubeTexture8_SetPrivateData(p,a,b,c,d) (p)->lpVtbl->SetPrivateData(p,a,b,c,d)
;#define IDirect3DCubeTexture8_GetPrivateData(p,a,b,c) (p)->lpVtbl->GetPrivateData(p,a,b,c)
;#define IDirect3DCubeTexture8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
;#define IDirect3DCubeTexture8_SetPriority(p,a) (p)->lpVtbl->SetPriority(p,a)
;#define IDirect3DCubeTexture8_GetPriority(p) (p)->lpVtbl->GetPriority(p)
;#define IDirect3DCubeTexture8_PreLoad(p) (p)->lpVtbl->PreLoad(p)
;#define IDirect3DCubeTexture8_GetType(p) (p)->lpVtbl->GetType(p)
;#define IDirect3DCubeTexture8_SetLOD(p,a) (p)->lpVtbl->SetLOD(p,a)
;#define IDirect3DCubeTexture8_GetLOD(p) (p)->lpVtbl->GetLOD(p)
;#define IDirect3DCubeTexture8_GetLevelCount(p) (p)->lpVtbl->GetLevelCount(p)
;#define IDirect3DCubeTexture8_GetLevelDesc(p,a,b) (p)->lpVtbl->GetLevelDesc(p,a,b)
;#define IDirect3DCubeTexture8_GetCubeMapSurface(p,a,b,c) (p)->lpVtbl->GetCubeMapSurface(p,a,b,c)
;#define IDirect3DCubeTexture8_LockRect(p,a,b,c,d,e) (p)->lpVtbl->LockRect(p,a,b,c,d,e)
;#define IDirect3DCubeTexture8_UnlockRect(p,a,b) (p)->lpVtbl->UnlockRect(p,a,b)
;#define IDirect3DCubeTexture8_AddDirtyRect(p,a,b) (p)->lpVtbl->AddDirtyRect(p,a,b)
;#else
;#define IDirect3DCubeTexture8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3DCubeTexture8_AddRef(p) (p)->AddRef()
;#define IDirect3DCubeTexture8_Release(p) (p)->Release()
;#define IDirect3DCubeTexture8_GetDevice(p,a) (p)->GetDevice(a)
;#define IDirect3DCubeTexture8_SetPrivateData(p,a,b,c,d) (p)->SetPrivateData(a,b,c,d)
;#define IDirect3DCubeTexture8_GetPrivateData(p,a,b,c) (p)->GetPrivateData(a,b,c)
;#define IDirect3DCubeTexture8_FreePrivateData(p,a) (p)->FreePrivateData(a)
;#define IDirect3DCubeTexture8_SetPriority(p,a) (p)->SetPriority(a)
;#define IDirect3DCubeTexture8_GetPriority(p) (p)->GetPriority()
;#define IDirect3DCubeTexture8_PreLoad(p) (p)->PreLoad()
;#define IDirect3DCubeTexture8_GetType(p) (p)->GetType()
;#define IDirect3DCubeTexture8_SetLOD(p,a) (p)->SetLOD(a)
;#define IDirect3DCubeTexture8_GetLOD(p) (p)->GetLOD()
;#define IDirect3DCubeTexture8_GetLevelCount(p) (p)->GetLevelCount()
;#define IDirect3DCubeTexture8_GetLevelDesc(p,a,b) (p)->GetLevelDesc(a,b)
;#define IDirect3DCubeTexture8_GetCubeMapSurface(p,a,b,c) (p)->GetCubeMapSurface(a,b,c)
;#define IDirect3DCubeTexture8_LockRect(p,a,b,c,d,e) (p)->LockRect(a,b,c,d,e)
;#define IDirect3DCubeTexture8_UnlockRect(p,a,b) (p)->UnlockRect(a,b)
;#define IDirect3DCubeTexture8_AddDirtyRect(p,a,b) (p)->AddDirtyRect(a,b)
;#endif




;#undef INTERFACE
;#define INTERFACE IDirect3DVertexBuffer8

DECLARE_INTERFACE <IDirect3DVertexBuffer8_>      ;, IDirect3DResource8)
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3DResource8 methods ***/
    STDMETHOD <GetDevice>,:DWORD                                ;THIS_ IDirect3DDevice8** ppDevice) PURE;
    STDMETHOD <SetPrivateData>,:DWORD,:DWORD,:DWORD,:DWORD      ;THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
    STDMETHOD <GetPrivateData>,:DWORD,:DWORD,:DWORD             ;THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <FreePrivateData>,:DWORD                          ;THIS_ REFGUID refguid) PURE;
    STDMETHOD <SetPriority>,:DWORD                              ;THIS_ DWORD PriorityNew) PURE;
    STDMETHOD <GetPriority>                                     ;THIS) PURE;
    STDMETHOD <PreLoad>                                         ;THIS) PURE;
    STDMETHOD <GetType>                                         ;THIS) PURE;
    STDMETHOD <Lock>,:DWORD,:DWORD,:DWORD,:DWORD                ;THIS_ UINT OffsetToLock,UINT SizeToLock,BYTE** ppbData,DWORD Flags) PURE;
    STDMETHOD <Unlock>                                          ;THIS) PURE;
    STDMETHOD <GetDesc>,:DWORD                                  ;THIS_ D3DVERTEXBUFFER_DESC *pDesc) PURE;
;};

LPDIRECT3DVERTEXBUFFER8 typedef PTR
PDIRECT3DVERTEXBUFFER8 typedef PTR
;typedef struct IDirect3DVertexBuffer8 *LPDIRECT3DVERTEXBUFFER8, *PDIRECT3DVERTEXBUFFER8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3DVertexBuffer8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3DVertexBuffer8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3DVertexBuffer8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3DVertexBuffer8_GetDevice(p,a) (p)->lpVtbl->GetDevice(p,a)
;#define IDirect3DVertexBuffer8_SetPrivateData(p,a,b,c,d) (p)->lpVtbl->SetPrivateData(p,a,b,c,d)
;#define IDirect3DVertexBuffer8_GetPrivateData(p,a,b,c) (p)->lpVtbl->GetPrivateData(p,a,b,c)
;#define IDirect3DVertexBuffer8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
;#define IDirect3DVertexBuffer8_SetPriority(p,a) (p)->lpVtbl->SetPriority(p,a)
;#define IDirect3DVertexBuffer8_GetPriority(p) (p)->lpVtbl->GetPriority(p)
;#define IDirect3DVertexBuffer8_PreLoad(p) (p)->lpVtbl->PreLoad(p)
;#define IDirect3DVertexBuffer8_GetType(p) (p)->lpVtbl->GetType(p)
;#define IDirect3DVertexBuffer8_Lock(p,a,b,c,d) (p)->lpVtbl->Lock(p,a,b,c,d)
;#define IDirect3DVertexBuffer8_Unlock(p) (p)->lpVtbl->Unlock(p)
;#define IDirect3DVertexBuffer8_GetDesc(p,a) (p)->lpVtbl->GetDesc(p,a)
;#else
;#define IDirect3DVertexBuffer8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3DVertexBuffer8_AddRef(p) (p)->AddRef()
;#define IDirect3DVertexBuffer8_Release(p) (p)->Release()
;#define IDirect3DVertexBuffer8_GetDevice(p,a) (p)->GetDevice(a)
;#define IDirect3DVertexBuffer8_SetPrivateData(p,a,b,c,d) (p)->SetPrivateData(a,b,c,d)
;#define IDirect3DVertexBuffer8_GetPrivateData(p,a,b,c) (p)->GetPrivateData(a,b,c)
;#define IDirect3DVertexBuffer8_FreePrivateData(p,a) (p)->FreePrivateData(a)
;#define IDirect3DVertexBuffer8_SetPriority(p,a) (p)->SetPriority(a)
;#define IDirect3DVertexBuffer8_GetPriority(p) (p)->GetPriority()
;#define IDirect3DVertexBuffer8_PreLoad(p) (p)->PreLoad()
;#define IDirect3DVertexBuffer8_GetType(p) (p)->GetType()
;#define IDirect3DVertexBuffer8_Lock(p,a,b,c,d) (p)->Lock(a,b,c,d)
;#define IDirect3DVertexBuffer8_Unlock(p) (p)->Unlock()
;#define IDirect3DVertexBuffer8_GetDesc(p,a) (p)->GetDesc(a)
;#endif




;#undef INTERFACE
;#define INTERFACE IDirect3DIndexBuffer8

DECLARE_INTERFACE <IDirect3DIndexBuffer8_>       ;, IDirect3DResource8)
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3DResource8 methods ***/
    STDMETHOD <GetDevice>,:DWORD                                ;THIS_ IDirect3DDevice8** ppDevice) PURE;
    STDMETHOD <SetPrivateData>,:DWORD,:DWORD,:DWORD,:DWORD      ;THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
    STDMETHOD <GetPrivateData>,:DWORD,:DWORD,:DWORD             ;THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <FreePrivateData>,:DWORD                          ;THIS_ REFGUID refguid) PURE;
    STDMETHOD <SetPriority>,:DWORD                              ;THIS_ DWORD PriorityNew) PURE;
    STDMETHOD <GetPriority>                                     ;THIS) PURE;
    STDMETHOD <PreLoad>                                         ;THIS) PURE;
    STDMETHOD <GetType>                                         ;THIS) PURE;
    STDMETHOD <Lock>,:DWORD,:DWORD,:DWORD,:DWORD                ;THIS_ UINT OffsetToLock,UINT SizeToLock,BYTE** ppbData,DWORD Flags) PURE;
    STDMETHOD <Unlock>                                          ;THIS) PURE;
    STDMETHOD <GetDesc>,:DWORD                                  ;THIS_ D3DINDEXBUFFER_DESC *pDesc) PURE;
;};

LPDIRECT3DINDEXBUFFER8  typedef PTR
PDIRECT3DINDEXBUFFER8  typedef PTR
;typedef struct IDirect3DIndexBuffer8 *LPDIRECT3DINDEXBUFFER8, *PDIRECT3DINDEXBUFFER8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3DIndexBuffer8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3DIndexBuffer8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3DIndexBuffer8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3DIndexBuffer8_GetDevice(p,a) (p)->lpVtbl->GetDevice(p,a)
;#define IDirect3DIndexBuffer8_SetPrivateData(p,a,b,c,d) (p)->lpVtbl->SetPrivateData(p,a,b,c,d)
;#define IDirect3DIndexBuffer8_GetPrivateData(p,a,b,c) (p)->lpVtbl->GetPrivateData(p,a,b,c)
;#define IDirect3DIndexBuffer8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
;#define IDirect3DIndexBuffer8_SetPriority(p,a) (p)->lpVtbl->SetPriority(p,a)
;#define IDirect3DIndexBuffer8_GetPriority(p) (p)->lpVtbl->GetPriority(p)
;#define IDirect3DIndexBuffer8_PreLoad(p) (p)->lpVtbl->PreLoad(p)
;#define IDirect3DIndexBuffer8_GetType(p) (p)->lpVtbl->GetType(p)
;#define IDirect3DIndexBuffer8_Lock(p,a,b,c,d) (p)->lpVtbl->Lock(p,a,b,c,d)
;#define IDirect3DIndexBuffer8_Unlock(p) (p)->lpVtbl->Unlock(p)
;#define IDirect3DIndexBuffer8_GetDesc(p,a) (p)->lpVtbl->GetDesc(p,a)
;#else
;#define IDirect3DIndexBuffer8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3DIndexBuffer8_AddRef(p) (p)->AddRef()
;#define IDirect3DIndexBuffer8_Release(p) (p)->Release()
;#define IDirect3DIndexBuffer8_GetDevice(p,a) (p)->GetDevice(a)
;#define IDirect3DIndexBuffer8_SetPrivateData(p,a,b,c,d) (p)->SetPrivateData(a,b,c,d)
;#define IDirect3DIndexBuffer8_GetPrivateData(p,a,b,c) (p)->GetPrivateData(a,b,c)
;#define IDirect3DIndexBuffer8_FreePrivateData(p,a) (p)->FreePrivateData(a)
;#define IDirect3DIndexBuffer8_SetPriority(p,a) (p)->SetPriority(a)
;#define IDirect3DIndexBuffer8_GetPriority(p) (p)->GetPriority()
;#define IDirect3DIndexBuffer8_PreLoad(p) (p)->PreLoad()
;#define IDirect3DIndexBuffer8_GetType(p) (p)->GetType()
;#define IDirect3DIndexBuffer8_Lock(p,a,b,c,d) (p)->Lock(a,b,c,d)
;#define IDirect3DIndexBuffer8_Unlock(p) (p)->Unlock()
;#define IDirect3DIndexBuffer8_GetDesc(p,a) (p)->GetDesc(a)
;#endif




;#undef INTERFACE
;#define INTERFACE IDirect3DSurface8

DECLARE_INTERFACE <IDirect3DSurface8_>       ;, IUnknown)
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3DSurface8 methods ***/
    STDMETHOD <GetDevice>,:DWORD                                ;THIS_ IDirect3DDevice8** ppDevice) PURE;
    STDMETHOD <SetPrivateData>,:DWORD,:DWORD,:DWORD,:DWORD      ;THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
    STDMETHOD <GetPrivateData>,:DWORD,:DWORD,:DWORD             ;THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <FreePrivateData>,:DWORD                          ;THIS_ REFGUID refguid) PURE;
    STDMETHOD <GetContainer>,:DWORD,:DWORD                      ;THIS_ REFIID riid,void** ppContainer) PURE;
    STDMETHOD <GetDesc>,:DWORD                                  ;THIS_ D3DSURFACE_DESC *pDesc) PURE;
    STDMETHOD <LockRect>,:DWORD,:DWORD,:DWORD                   ;THIS_ D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) PURE;
    STDMETHOD <UnlockRect>                                      ;THIS) PURE;
;};

LPDIRECT3DSURFACE8  typedef PTR
PDIRECT3DSURFACE8  typedef PTR
;typedef struct IDirect3DSurface8 *LPDIRECT3DSURFACE8, *PDIRECT3DSURFACE8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3DSurface8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3DSurface8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3DSurface8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3DSurface8_GetDevice(p,a) (p)->lpVtbl->GetDevice(p,a)
;#define IDirect3DSurface8_SetPrivateData(p,a,b,c,d) (p)->lpVtbl->SetPrivateData(p,a,b,c,d)
;#define IDirect3DSurface8_GetPrivateData(p,a,b,c) (p)->lpVtbl->GetPrivateData(p,a,b,c)
;#define IDirect3DSurface8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
;#define IDirect3DSurface8_GetContainer(p,a,b) (p)->lpVtbl->GetContainer(p,a,b)
;#define IDirect3DSurface8_GetDesc(p,a) (p)->lpVtbl->GetDesc(p,a)
;#define IDirect3DSurface8_LockRect(p,a,b,c) (p)->lpVtbl->LockRect(p,a,b,c)
;#define IDirect3DSurface8_UnlockRect(p) (p)->lpVtbl->UnlockRect(p)
;#else
;#define IDirect3DSurface8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3DSurface8_AddRef(p) (p)->AddRef()
;#define IDirect3DSurface8_Release(p) (p)->Release()
;#define IDirect3DSurface8_GetDevice(p,a) (p)->GetDevice(a)
;#define IDirect3DSurface8_SetPrivateData(p,a,b,c,d) (p)->SetPrivateData(a,b,c,d)
;#define IDirect3DSurface8_GetPrivateData(p,a,b,c) (p)->GetPrivateData(a,b,c)
;#define IDirect3DSurface8_FreePrivateData(p,a) (p)->FreePrivateData(a)
;#define IDirect3DSurface8_GetContainer(p,a,b) (p)->GetContainer(a,b)
;#define IDirect3DSurface8_GetDesc(p,a) (p)->GetDesc(a)
;#define IDirect3DSurface8_LockRect(p,a,b,c) (p)->LockRect(a,b,c)
;#define IDirect3DSurface8_UnlockRect(p) (p)->UnlockRect()
;#endif




;#undef INTERFACE
;#define INTERFACE IDirect3DVolume8

DECLARE_INTERFACE <IDirect3DVolume8_>       ;, IUnknown)
;{
    ;/*** IUnknown methods ***/
    INHERIT_IUnknown
    ;STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    ;STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    ;STDMETHOD_(ULONG,Release)(THIS) PURE;

    ;/*** IDirect3DVolume8 methods ***/
    STDMETHOD <GetDevice>,:DWORD                                ;(THIS_ IDirect3DDevice8** ppDevice) PURE;
    STDMETHOD <SetPrivateData>,:DWORD,:DWORD,:DWORD,:DWORD      ;(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
    STDMETHOD <GetPrivateData>,:DWORD,:DWORD,:DWORD             ;(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD <FreePrivateData>,:DWORD                          ;(THIS_ REFGUID refguid) PURE;
    STDMETHOD <GetContainer>,:DWORD,:DWORD                      ;(THIS_ REFIID riid,void** ppContainer) PURE;
    STDMETHOD <GetDesc>,:DWORD                                  ;(THIS_ D3DVOLUME_DESC *pDesc) PURE;
    STDMETHOD <LockBox>,:DWORD,:DWORD,:DWORD                    ;(THIS_ D3DLOCKED_BOX * pLockedVolume,CONST D3DBOX* pBox,DWORD Flags) PURE;
    STDMETHOD <UnlockBox>                                ;(THIS) PURE;
;};

LPDIRECT3DVOLUME8   typedef PTR
PDIRECT3DVOLUME8   typedef PTR
;typedef struct IDirect3DVolume8 *LPDIRECT3DVOLUME8, *PDIRECT3DVOLUME8;

;#if !defined(__cplusplus) || defined(CINTERFACE)
;#define IDirect3DVolume8_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
;#define IDirect3DVolume8_AddRef(p) (p)->lpVtbl->AddRef(p)
;#define IDirect3DVolume8_Release(p) (p)->lpVtbl->Release(p)
;#define IDirect3DVolume8_GetDevice(p,a) (p)->lpVtbl->GetDevice(p,a)
;#define IDirect3DVolume8_SetPrivateData(p,a,b,c,d) (p)->lpVtbl->SetPrivateData(p,a,b,c,d)
;#define IDirect3DVolume8_GetPrivateData(p,a,b,c) (p)->lpVtbl->GetPrivateData(p,a,b,c)
;#define IDirect3DVolume8_FreePrivateData(p,a) (p)->lpVtbl->FreePrivateData(p,a)
;#define IDirect3DVolume8_GetContainer(p,a,b) (p)->lpVtbl->GetContainer(p,a,b)
;#define IDirect3DVolume8_GetDesc(p,a) (p)->lpVtbl->GetDesc(p,a)
;#define IDirect3DVolume8_LockBox(p,a,b,c) (p)->lpVtbl->LockBox(p,a,b,c)
;#define IDirect3DVolume8_UnlockBox(p) (p)->lpVtbl->UnlockBox(p)
;#else
;#define IDirect3DVolume8_QueryInterface(p,a,b) (p)->QueryInterface(a,b)
;#define IDirect3DVolume8_AddRef(p) (p)->AddRef()
;#define IDirect3DVolume8_Release(p) (p)->Release()
;#define IDirect3DVolume8_GetDevice(p,a) (p)->GetDevice(a)
;#define IDirect3DVolume8_SetPrivateData(p,a,b,c,d) (p)->SetPrivateData(a,b,c,d)
;#define IDirect3DVolume8_GetPrivateData(p,a,b,c) (p)->GetPrivateData(a,b,c)
;#define IDirect3DVolume8_FreePrivateData(p,a) (p)->FreePrivateData(a)
;#define IDirect3DVolume8_GetContainer(p,a,b) (p)->GetContainer(a,b)
;#define IDirect3DVolume8_GetDesc(p,a) (p)->GetDesc(a)
;#define IDirect3DVolume8_LockBox(p,a,b,c) (p)->LockBox(a,b,c)
;#define IDirect3DVolume8_UnlockBox(p) (p)->UnlockBox()
;#endif

;/****************************************************************************
; * Flags for SetPrivateData method on all D3D8 interfaces
; *
; * The passed pointer is an IUnknown ptr. The SizeOfData argument to SetPrivateData
; * must be set to sizeof(IUnknown*). Direct3D will call AddRef through this
; * pointer and Release when the private data is destroyed. The data will be
; * destroyed when another SetPrivateData with the same GUID is set, when
; * FreePrivateData is called, or when the D3D8 object is freed.
; ****************************************************************************/
D3DSPD_IUNKNOWN                         EQU         01h         ;0x00000001L

;/****************************************************************************
; *
; * Parameter for IDirect3D8 Enum and GetCaps8 functions to get the info for
; * the current mode only.
; *
; ****************************************************************************/

D3DCURRENT_DISPLAY_MODE                 EQU         0EFFFFFh    ;0x00EFFFFFL

;/****************************************************************************
; *
; * Flags for IDirect3D8::CreateDevice's BehaviorFlags
; *
; ****************************************************************************/

D3DCREATE_FPU_PRESERVE                  EQU         02h         ;0x00000002L
D3DCREATE_MULTITHREADED                 EQU         04h         ;0x00000004L

D3DCREATE_PUREDEVICE                    EQU         010h        ;0x00000010L
D3DCREATE_SOFTWARE_VERTEXPROCESSING     EQU         020h        ;0x00000020L
D3DCREATE_HARDWARE_VERTEXPROCESSING     EQU         040h        ;0x00000040L
D3DCREATE_MIXED_VERTEXPROCESSING        EQU         080h        ;0x00000080L


;/****************************************************************************
; *
; * Parameter for IDirect3D8::CreateDevice's iAdapter
; *
; ****************************************************************************/

D3DADAPTER_DEFAULT                      EQU         0           ;0

;/****************************************************************************
; *
; * Flags for IDirect3D8::EnumAdapters
; *
; ****************************************************************************/

D3DENUM_NO_WHQL_LEVEL                   EQU         02h         ;0x00000002L

;/****************************************************************************
; *
; * Maximum number of back-buffers supported in DX8
; *
; ****************************************************************************/

D3DPRESENT_BACK_BUFFERS_MAX             EQU         3           ;3L

;/****************************************************************************
; *
; * Flags for IDirect3DDevice8::SetGammaRamp
; *
; ****************************************************************************/

D3DSGR_NO_CALIBRATION                   EQU         00h         ;0x00000000L
D3DSGR_CALIBRATE                        EQU         01h         ;0x00000001L

;/****************************************************************************
; *
; * Flags for IDirect3DDevice8::SetCursorPosition
; *
; ****************************************************************************/

D3DCURSOR_IMMEDIATE_UPDATE              EQU         01h         ;0x00000001L

;/****************************************************************************
; *
; * Flags for DrawPrimitive/DrawIndexedPrimitive
; *   Also valid for Begin/BeginIndexed
; *   Also valid for VertexBuffer::CreateVertexBuffer
; ****************************************************************************/


;/*
; *  DirectDraw error codes
; */
_FACD3D                                 EQU         0876h       ;0x876

;#define MAKE_D3DHRESULT( code )  MAKE_HRESULT( 1, _FACD3D, code )
MAKE_D3DHRESULT MACRO hres_name,code
 MAKE_HRESULT hres_name,1,_FACD3D,code
ENDM

;/*
; * Direct3D Errors
; */
D3D_OK                                  EQU         S_OK

MAKE_D3DHRESULT    D3DERR_WRONGTEXTUREFORMAT               ,2072
MAKE_D3DHRESULT    D3DERR_UNSUPPORTEDCOLOROPERATION        ,2073
MAKE_D3DHRESULT    D3DERR_UNSUPPORTEDCOLORARG              ,2074
MAKE_D3DHRESULT    D3DERR_UNSUPPORTEDALPHAOPERATION        ,2075
MAKE_D3DHRESULT    D3DERR_UNSUPPORTEDALPHAARG              ,2076
MAKE_D3DHRESULT    D3DERR_TOOMANYOPERATIONS                ,2077
MAKE_D3DHRESULT    D3DERR_CONFLICTINGTEXTUREFILTER         ,2078
MAKE_D3DHRESULT    D3DERR_UNSUPPORTEDFACTORVALUE           ,2079
MAKE_D3DHRESULT    D3DERR_CONFLICTINGRENDERSTATE           ,2081
MAKE_D3DHRESULT    D3DERR_UNSUPPORTEDTEXTUREFILTER         ,2082
MAKE_D3DHRESULT    D3DERR_CONFLICTINGTEXTUREPALETTE        ,2086
MAKE_D3DHRESULT    D3DERR_DRIVERINTERNALERROR              ,2087

MAKE_D3DHRESULT    D3DERR_NOTFOUND                         ,2150
MAKE_D3DHRESULT    D3DERR_MOREDATA                         ,2151
MAKE_D3DHRESULT    D3DERR_DEVICELOST                       ,2152
MAKE_D3DHRESULT    D3DERR_DEVICENOTRESET                   ,2153
MAKE_D3DHRESULT    D3DERR_NOTAVAILABLE                     ,2154
MAKE_D3DHRESULT    D3DERR_OUTOFVIDEOMEMORY                 ,380
MAKE_D3DHRESULT    D3DERR_INVALIDDEVICE                    ,2155
MAKE_D3DHRESULT    D3DERR_INVALIDCALL                      ,2156
MAKE_D3DHRESULT    D3DERR_DRIVERINVALIDCALL                ,2157

;#ifdef __cplusplus
;};
;#endif

;#endif ;/* (DIRECT3D_VERSION >= 0x0800) */
    endif ;/* __D3D8_INC_ */

