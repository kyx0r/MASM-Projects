include \ASM\Text ADV\src\Vertice.asm
include \ASM\Text ADV\src\renderX.asm


.CODE
;-----------------------------------------------------------------------------
; Name: InitD3D
; Desc: Initializes Direct3D8
;-----------------------------------------------------------------------------

InitD3D PROC hWnd:DWORD
    LOCAL d3ddm:D3DDISPLAYMODE 
    LOCAL d3dpp:D3DPRESENT_PARAMETERS

;   To create a Direct3D8 device, we must first create a Direct3D8 object.
    invoke Direct3DCreate8, D3D_SDK_VERSION
    mov g_pD3D, eax
    .if eax == NULL
        return 0
    .endif

;   With this Direct3D8 object, we can obtain the current desktop display mode 
    mcall [g_pD3D],IDirect3D8_GetAdapterDisplayMode,D3DADAPTER_DEFAULT,ADDR d3ddm
    .if eax != D3D_OK
        return 0
    .endif
    
;   Next, we initialize the parameters for our Direct3D8 device so that the backbuffer
;   has the same format as the current desktop display.
    ZeroMemory &d3dpp,sizeof(D3DPRESENT_PARAMETERS)
    mov d3dpp.Windowed, TRUE
    mov d3dpp.SwapEffect, D3DSWAPEFFECT_DISCARD
    mov eax, d3ddm.Format
    mov d3dpp.BackBufferFormat, eax

;   Finally, we create the Direct3D8 device. 
    mcall [g_pD3D],IDirect3D8_CreateDevice, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,\
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,\
                                      ADDR d3dpp, ADDR g_pd3dDevice
    .if eax != D3D_OK
        return 0
    .endif


;   Device states would normally be set here

	;mcall [g_pd3dDevice],IDirect3DDevice8_SetRenderState, D3DRS_ZENABLE, TRUE
	
    return S_OK
InitD3D ENDP



;-----------------------------------------------------------------------------
; Name: Cleanup
; Desc: Releases all previously initialized objects
;-----------------------------------------------------------------------------
Cleanup PROC

;   Destroy the Direct3D8 device
    .if g_pd3dDevice != NULL
        mcall [g_pd3dDevice],IUnknown_Release
        xor eax,eax
        mov g_pd3dDevice,eax
    .endif

;   Destroy the Direct3D8 object
    .if g_pD3D != NULL
        mcall [g_pD3D],IUnknown_Release
        xor eax,eax
        mov g_pD3D,eax
    .endif

    ret
Cleanup ENDP


;-----------------------------------------------------------------------------
; Name: MsgProc
; Desc: The window's message handler
;-----------------------------------------------------------------------------
MsgProc PROC hWnd:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
    mov eax,uMsg

    .if uMsg == WM_DESTROY
        invoke PostQuitMessage,0
        mov eax,0
        ret
    .else
        invoke DefWindowProc,hWnd,uMsg,wParam,lParam
    .endif
    
    ret
MsgProc ENDP

;-----------------------------------------------------------------------------
; Name: WinMain
; Desc: The application's entry point
;-----------------------------------------------------------------------------
WinMain PROC hInst:DWORD,prevInstance:DWORD,cmdlinePtr:DWORD,cmdShow:DWORD
LOCAL wc:WNDCLASSEX
LOCAL msg:MSG
LOCAL hWnd:HWND

;   Register the window class
    mov eax,hInst
    mov hInstance, eax
    
    mov wc.cbSize, sizeof WNDCLASSEX 
    mov wc.style, CS_CLASSDC 
    mov wc.lpfnWndProc, MsgProc 
    mov wc.cbClsExtra, 0
    mov wc.cbWndExtra, 0
    mov wc.hInstance, eax 
    invoke LoadIcon, hInst, IDI_ICON
    mov wc.hIcon,eax
    invoke LoadCursor, NULL, IDC_ARROW 
    mov wc.hCursor, eax  
    mov wc.hbrBackground, COLOR_WINDOWFRAME
    mov wc.lpszMenuName, NULL  
    mov wc.lpszClassName, OFFSET MyClassName
    mov wc.hIconSm, NULL 

    invoke RegisterClassEx,ADDR wc
 
;   Create the application's window.
;   Use 'WS_EX_TOPMOST' as the first parameter instead of 'NULL' if you're
;   going to create a full-screen application.
    invoke GetDesktopWindow
    invoke CreateWindowEx,NULL, ADDR MyClassName, ADDR WinTitleString, \
                              WS_OVERLAPPEDWINDOW, 100, 100, 300, 300,\
                              eax, NULL, hInstance, NULL
    mov hWnd, eax
    mov hWindow, eax
    
;   Initialize Direct3D
    invoke InitD3D, hWnd
    .if eax == S_OK
	
    invoke InitVB
	
;	.if eax == S_OK
	
;   Show the window
        invoke ShowWindow, hWnd, SW_SHOWDEFAULT
        invoke UpdateWindow, hWnd  ; send WM_PAINT to the window proc

;   Enter the message loop
            ZeroMemory &msg,sizeof(MSG)
            .WHILE 1
                INVOKE PeekMessage, ADDR msg, NULL, 0, 0, PM_REMOVE
                .IF eax != 0
                    .IF msg.message == WM_QUIT
                        INVOKE PostQuitMessage, msg.wParam
                        .BREAK
                    .ELSE
                        INVOKE TranslateMessage, ADDR msg
                        INVOKE DispatchMessage, ADDR msg
                    .ENDIF
                .ELSE
                
                    INVOKE Render
                    
                .ENDIF
            .ENDW
    
    .endif
    
;   Clean up everything and exit the app
    invoke Cleanup
    
    invoke UnregisterClass,ADDR MyClassName,hInstance
    
    mov eax,msg.wParam
    ret
WinMain ENDP