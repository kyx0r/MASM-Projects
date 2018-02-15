ifndef __D3DX8CORE__

__D3DX8CORE__			equ	1

  D3DXCreateFont		Proto	:DWORD, :DWORD, :DWORD
  D3DXCreateFontIndirect	Proto	:DWORD, :DWORD, :DWORD
  D3DXCreateSprite		Proto	:DWORD, :DWORD
  D3DXCreateRenderToSurface	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateRenderToEnvMap	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXAssembleShaderFromFileA	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXAssembleShaderFromFileW	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXAssembleShader		Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXGetFVFVertexSize		Proto	:DWORD
  D3DXGetErrorStringA		Proto	:DWORD, :DWORD, :DWORD
  D3DXGetErrorStringW		Proto	:DWORD, :DWORD, :DWORD


DECLARE_INTERFACE <ID3DXBuffer_>
;   /*** IUnknown methods ***/
    INHERIT_IUnknown
;   /*** ID3DXBuffer methods ***/

    STDMETHOD	<GetBufferPointer>
    STDMETHOD	<GetBufferSize>

LPD3DXBUFFER typedef PTR
                     
                     
DECLARE_INTERFACE <ID3DXFont_>
;   /*** IUnknown methods ***/
    INHERIT_IUnknown
;   /*** ID3DXFont methods ***/
    STDMETHOD	<GetDevice>
    STDMETHOD	<GetLogFont>

    STDMETHOD	<Begin>

    STDMETHOD	<DrawTextA>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
    STDMETHOD	<DrawTextW>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD

    STDMETHOD	<End>
      
LPD3DXFONT typedef PTR


DECLARE_INTERFACE <ID3DXSprite_>
;   /*** IUnknown methods ***/
    INHERIT_IUnknown
;   /*** ID3DXSprite methods ***/

    STDMETHOD	<GetDevice>

    STDMETHOD	<Begin>

    STDMETHOD	<Draw>, 	 :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
    STDMETHOD	<DrawTransform>, :DWORD, :DWORD, :DWORD, :DWORD

    STDMETHOD	<End>

LPD3DXSPRITE typedef PTR


DECLARE_INTERFACE <ID3DXRenderToSurface_>
;   /*** IUnknown methods ***/
    INHERIT_IUnknown
;   /*** ID3DXRenderToSurface methods ***/

    STDMETHOD	<GetDevice>
    STDMETHOD	<GetDesc>, :DWORD

    STDMETHOD	<BeginScene>, : DWORD, :DWORD
    STDMETHOD	<EndScene>

LPD3DXRENDERTOSURFACE	typedef PTR


DECLARE_INTERFACE <ID3DXRenderToEnvMap_>
;   /*** IUnknown methods ***/
    INHERIT_IUnknown
;   /*** ID3DXRenderToEnvMap methods ***/

    STDMETHOD	<GetDevice>, :DWORD
    STDMETHOD	<GetDesc>, :DWORD

    STDMETHOD	<BeginCube>, :DWORD
    STDMETHOD	<BeginSphere>, :DWORD
    STDMETHOD	<BeginHemiSphere>, :DWORD, :DWORD
    STDMETHOD	<BeginParabolic>, :DWORD, :DWORD

    STDMETHOD	<Face>, : DWORD
    STDMETHOD	<End>
LPD3DXRENDERTOENVMAP typedef PTR


ifdef UNICODE
  ifndef DrawText
    DrawText			equ		DrawTextW
  endif
  D3DXAssembleShaderFromFile	equ		D3DXAssembleShaderFromFileW
  D3DXGetErrorString 		equ		D3DXGetErrorStringW
else
  ifndef DrawText
    DrawText			equ		DrawTextA
  endif
  D3DXAssembleShaderFromFile	equ		D3DXAssembleShaderFromFileA
  D3DXGetErrorString 		equ		D3DXGetErrorStringA
endif


D3DXASM_DEBUG           	equ		1
D3DXASM_SKIPVALIDATION  	equ		2


_D3DXRTS_DESC			STRUCT

    _Width                  DWORD           ?
    Height                  DWORD           ?
    Format                  D3DFORMAT       ?
    DepthStencil            DWORD           ?
    DepthStencilFormat      D3DFORMAT       ?

_D3DXRTS_DESC			ENDS

D3DXRTS_DESC			typedef		D3DXRTS_DESC
LPD3DXRTS_DESC			typedef	ptr	D3DXRTS_DESC


_D3DXRTE_DESC			struct

    _Size			DWORD		?
    Format			D3DFORMAT	?
    DepthStencil		DWORD		?
    DepthStencilFormat		D3DFORMAT	?
   
_D3DXRTE_DESC			ENDS

D3DXRTE_DESC			typedef		D3DXRTE_DESC
LPD3DXRTE_DESC			typedef	ptr	D3DXRTE_DESC

endif