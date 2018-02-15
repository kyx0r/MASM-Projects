ifndef __D3DX8TEX__
__D3DX8TEX__			equ	1

  D3DXLoadSurfaceFromFileA		Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXLoadSurfaceFromFileW		Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXLoadSurfaceFromResourceA  	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXLoadSurfaceFromResourceW  	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXLoadSurfaceFromFileInMemory	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXLoadSurfaceFromSurface		Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXLoadSurfaceFromMemory		Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXLoadVolumeFromVolume		Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXLoadVolumeFromMemory		Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCheckTextureRequirements		Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateTexture                     Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateTextureFromFileA		Proto	:DWORD, :DWORD, :DWORD
  D3DXCreateTextureFromFileW		Proto	:DWORD, :DWORD, :DWORD
  D3DXCreateTextureFromResourceA	Proto	:DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateTextureFromResourceW	Proto	:DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateTextureFromFileExA      Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateTextureFromFileExW      Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateTextureFromResourceExA	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateTextureFromResourceExW	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateTextureFromFileInMemory	Proto	:DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateTextureFromFileInMemoryEx	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXFilterTexture			Proto	:DWORD, :DWORD, :DWORD, :DWORD
  D3DXCheckCubeTextureRequirements	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateCubeTexture			Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD 
  D3DXCreateCubeTextureFromFileA	Proto	:DWORD, :DWORD, :DWORD
  D3DXCreateCubeTextureFromFileW	Proto	:DWORD, :DWORD, :DWORD
  D3DXCreateCubeTextureFromFileExA	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateCubeTextureFromFileExW	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateCubeTextureFromFileInMemory	Proto	:DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateCubeTextureFromFileInMemoryEx Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXFilterCubeTexture			Proto	:DWORD, :DWORD, :DWORD, :DWORD
  D3DXCheckVolumeTextureRequirements	Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXCreateVolumeTexture		Proto	:DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  D3DXFilterVolumeTexture		Proto	:DWORD, :DWORD, :DWORD, :DWORD


    D3DXGetImageInfoFromFileA   PROTO :DWORD, :DWORD
    D3DXGetImageInfoFromFileW   PROTO :DWORD, :DWORD


ifdef UNICODE
    D3DXGetImageInfoFromFile        EQU     <D3DXGetImageInfoFromFileW>
else
    D3DXGetImageInfoFromFile        EQU     <D3DXGetImageInfoFromFileA>
endif


    D3DXGetImageInfoFromResourceA   PROTO :DWORD, :DWORD, :DWORD
    D3DXGetImageInfoFromResourceW   PROTO :DWORD, :DWORD, :DWORD
    
ifdef UNICODE
    D3DXGetImageInfoFromResource        EQU     <D3DXGetImageInfoFromResourceW>
else
    D3DXGetImageInfoFromResource        EQU     <D3DXGetImageInfoFromResourceA>
endif


    D3DXGetImageInfoFromFileInMemory   PROTO :DWORD, :DWORD, :DWORD


ifdef UNICODE
  D3DXLoadSurfaceFromFile		equ	D3DXLoadSurfaceFromFileW
  D3DXLoadSurfaceFromResource		equ	D3DXLoadSurfaceFromResourceW
  D3DXCreateTextureFromFile		equ	D3DXCreateTextureFromFileW
  D3DXCreateTextureFromResource 	equ	D3DXCreateTextureFromResourceW
  D3DXCreateTextureFromFileEx   	equ	D3DXCreateTextureFromFileExW
  D3DXCreateTextureFromResourceEx   	equ	D3DXCreateTextureFromResourceExW
  D3DXCreateCubeTextureFromFile		equ	D3DXCreateCubeTextureFromFileW
  D3DXCreateCubeTextureFromFileEx	equ	D3DXCreateCubeTextureFromFileExW
else
    D3DXLoadSurfaceFromFile             equ     <D3DXLoadSurfaceFromFileA>
    D3DXLoadSurfaceFromResource         equ     <D3DXLoadSurfaceFromResourceA>
    D3DXCreateTextureFromFile           equ     <D3DXCreateTextureFromFileA>
    D3DXCreateTextureFromResource       equ     <D3DXCreateTextureFromResourceA>
    D3DXCreateTextureFromFileEx         equ     <D3DXCreateTextureFromFileExA>
    D3DXCreateTextureFromResourceEx     equ     <D3DXCreateTextureFromResourceExA>
    D3DXCreateCubeTextureFromFile       equ     <D3DXCreateCubeTextureFromFileA>
    D3DXCreateCubeTextureFromFileEx     equ     <D3DXCreateCubeTextureFromFileExA>
endif


D3DX_FILTER_NONE		equ	1
D3DX_FILTER_POINT		equ	2
D3DX_FILTER_LINEAR		equ	3
D3DX_FILTER_TRIANGLE		equ	4
D3DX_FILTER_BOX			equ	5

D3DX_FILTER_MIRROR_U		equ	010000h
D3DX_FILTER_MIRROR_V		equ	020000h
D3DX_FILTER_MIRROR_W		equ	040000h
D3DX_FILTER_MIRROR		equ	070000h
D3DX_FILTER_DITHER		equ	080000h


_D3DXIMAGE_INFO		 	struct

  _Width			dword		?
  Height			dword		?
  Depth				dword		?
  MipLevels			dword		?
  Format			D3DFORMAT	?

_D3DXIMAGE_INFO			ends

D3DXIMAGE_INFO			typedef		_D3DXIMAGE_INFO
LPD3DXIMAGE_INFO                typedef ptr	D3DXIMAGE_INFO

endif