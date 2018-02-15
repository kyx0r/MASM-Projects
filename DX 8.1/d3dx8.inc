;///////////////////////////////////////////////////////////////////////////
;//
;//  Copyright (C) 1999 Microsoft Corporation.  All Rights Reserved.
;//
;//  File:       d3dx8.h
;//  Content:    D3DX utility library
;//
;///////////////////////////////////////////////////////////////////////////

;#ifndef __D3DX8_H__
;#define __D3DX8_H__
IFNDEF _D3DX8_INC_
_D3DX8_INC_=1

;#include <d3d8.h>
include d3d8.inc

;#include <limits.h>
include limits.inc

;#ifndef D3DXINLINE
IFNDEF D3DXINLINE
    ;#ifdef __cplusplus
    IFDEF __cplusplus
        ;#define D3DXINLINE inline
        D3DXINLINE      equ     inline 
    ;#else
    ELSE
        ;#define D3DXINLINE _inline
        D3DXINLINE      equ     _inline 
    ;#endif
    ENDIF
;#endif
ENDIF

;#define D3DX_DEFAULT ULONG_MAX
D3DX_DEFAULT                equ     ULONG_MAX
;#define D3DX_DEFAULT_FLOAT FLT_MAX
D3DX_DEFAULT_FLOAT          equ     FLT_MAX

;#include "d3dx8math.h"
include d3dx8math.inc
;#include "d3dx8core.h"
include d3dx8core.inc
;#include "d3dx8tex.h"
include d3dx8tex.inc
;#include "d3dx8mesh.h"
include d3dx8mesh.inc
;#include "d3dx8shape.h"
include d3dx8shape.inc
;#include "d3dx8effect.h"
include d3dx8effect.inc

;#endif //__D3DX8_H__
ENDIF ;_D3DX8_INC_
