InitVB  PROC
LOCAL pVertices:PTR

.CODE

;   Create the vertex buffer. Here we are allocating enough memory
;   (from the default pool) to hold all our 3 custom vertices. We also
;   specify the FVF, so the vertex buffer knows what data it contains.
    mcall [g_pd3dDevice],IDirect3DDevice8_CreateVertexBuffer, sizeof g_Vertices,    \
                                                  0, D3DFVF_CUSTOMVERTEX ,          \
                                                  D3DPOOL_DEFAULT, ADDR g_pVB
    .if eax != D3D_OK
        return E_FAIL
    .endif


;   Now we fill the vertex buffer. To do this, we need to Lock 'g_pVB' to
;   gain access to the vertices.
    mcall [g_pVB],IDirect3DVertexBuffer8_Lock, 0, sizeof g_Vertices, ADDR pVertices, 0
    .if eax != D3D_OK
        return E_FAIL
    .endif

    memcpy pVertices, OFFSET g_Vertices,  sizeof g_Vertices

    mcall [g_pVB],IDirect3DVertexBuffer8_Unlock

    return S_OK
InitVB ENDP