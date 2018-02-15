ifndef __D3DX8MESH__

__D3DX8MESH__		equ	1
include dx_objbase.def ; macros to define and call COM-objects etc.

  D3DXCreateMesh		Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXCreateMeshFVF		Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXCreateSPMesh		Proto	:Dword, :Dword, :Dword, :Dword, :Dword
  D3DXCleanMesh			Proto	:Dword, :Dword, :Dword
  D3DXValidMesh			Proto	:Dword, :Dword, :Dword
  D3DXGeneratePMesh		Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXSimplifyMesh		Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXComputeBoundingSphere	Proto	:Dword, :Dword, :Dword, :Dword, :Dword
  D3DXComputeBoundingBox	Proto	:Dword, :Dword, :Dword, :Dword, :Dword
  D3DXComputeNormals		Proto	:Dword, :Dword
  D3DXCreateBuffer		Proto	:Dword, :Dword
  D3DXLoadMeshFromX		Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXSaveMeshToX		     Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXCreatePMeshFromStream	Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXCreateSkinMesh		Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :DWord
  D3DXCreateSkinMeshFVF		Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :DWord
  D3DXCreateSkinMeshFromMesh	Proto	:Dword, :Dword, :Dword
  D3DXLoadMeshFromXof		Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :DWord
  D3DXLoadSkinMeshFromXof	Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXTesselateMesh		Proto	:Dword, :Dword, :Dword, :Dword, :Dword
  D3DXTessellateNPatches		Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXDeclaratorFromFVF		Proto	:Dword, :Dword
  D3DXFVFFromDeclarator		Proto	:Dword, :Dword
  D3DXWeldVertices		Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXIntersect			Proto	:Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :Dword, :Dword
  D3DXSphereBoundProbe		Proto	:Dword, :Dword, :Dword, :Dword
  D3DXBoxBoundProbe		Proto	:Dword, :Dword, :Dword, :Dword

DECLARE_INTERFACE <ID3DXBaseMesh_>
; /*** IUnknown methods ***/
  INHERIT_IUnknown
; /*** ID3DXBaseMesh methods ***/

  STDMETHOD	<DrawSubset>, :DWORD
  STDMETHOD	<GetNumFaces>
  STDMETHOD	<GetNumVertices>
  STDMETHOD	<GetFVF>
  STDMETHOD	<GetDeclaration>, :DWORD
  STDMETHOD	<GetOptions>
  STDMETHOD	<GetDevice>, : DWORD
  STDMETHOD	<CloneMeshFVF>, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<CloneMesh>, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<GetVertexBuffer>, :DWORD
  STDMETHOD	<GetIndexBuffer>, :DWORD
  STDMETHOD	<LockVertexBuffer>, :DWORD, :DWORD
  STDMETHOD	<UnlockVertexBuffer>
  STDMETHOD	<LockIndexBuffer>, :DWORD, :DWORD
  STDMETHOD	<UnlockIndexBuffer>
  STDMETHOD	<GetAttributeTable>, :DWORD, :DWORD
                             
LPD3DXBASEMESH	typedef	PTR

DECLARE_INTERFACE <ID3DXMesh_>
; /*** IUnknown methods ***/
  INHERIT_IUnknown
; /*** ID3DXBaseMesh methods ***/
  STDMETHOD	<DrawSubset>, :DWORD
  STDMETHOD	<GetNumFaces>
  STDMETHOD	<GetNumVertices>
  STDMETHOD	<GetFVF>
  STDMETHOD	<GetDeclaration>, :DWORD
  STDMETHOD	<GetOptions>
  STDMETHOD	<GetDevice>, : DWORD
  STDMETHOD	<CloneMeshFVF>, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<CloneMesh>, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<GetVertexBuffer>, :DWORD
  STDMETHOD	<GetIndexBuffer>, :DWORD
  STDMETHOD	<LockVertexBuffer>, :DWORD, :DWORD
  STDMETHOD	<UnlockVertexBuffer>
  STDMETHOD	<LockIndexBuffer>, :DWORD, :DWORD
  STDMETHOD	<UnlockIndexBuffer>
  STDMETHOD	<GetAttributeTable>, :DWORD, :DWORD
; /*** ID3DXMesh ***/
  STDMETHOD	<LockAttributeBuffer>, :DWORD, :DWORD
  STDMETHOD	<UnlockAttributeBuffer>
  STDMETHOD	<ConvertPointRepsToAdjacency>, :DWORD, :DWORD
  STDMETHOD	<ConvertAdjacencyToPointReps>, :DWORD, :DWORD
  STDMETHOD	<GenerateAdjacency>, :FLOAT, :DWORD
  STDMETHOD	<Optimize>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<OptimizeInplace>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD

LPD3DXMESH	typedef	PTR

DECLARE_INTERFACE <ID3DXPMesh_>
; /*** IUnknown methods ***/
  INHERIT_IUnknown
; /*** ID3DXBaseMesh methods ***/
  STDMETHOD	<DrawSubset>, :DWORD
  STDMETHOD	<GetNumFaces>
  STDMETHOD	<GetNumVertices>
  STDMETHOD	<GetFVF>
  STDMETHOD	<GetDeclaration>, :DWORD
  STDMETHOD	<GetOptions>
  STDMETHOD	<GetDevice>, : DWORD
  STDMETHOD	<CloneMeshFVF>, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<CloneMesh>, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<GetVertexBuffer>, :DWORD
  STDMETHOD	<GetIndexBuffer>, :DWORD
  STDMETHOD	<LockVertexBuffer>, :DWORD, :DWORD
  STDMETHOD	<UnlockVertexBuffer>
  STDMETHOD	<LockIndexBuffer>, :DWORD, :DWORD
  STDMETHOD	<UnlockIndexBuffer>
  STDMETHOD	<GetAttributeTable>, :DWORD, :DWORD
; /*** ID3DXPMesh ***/

  STDMETHOD	<ClonePMeshFVF>, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<ClonePMesh>, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<SetNumFaces>, :DWORD
  STDMETHOD	<SetNumVertices>, :DWORD 
  STDMETHOD	<GetMaxFaces>
  STDMETHOD	<GetMinFaces>
  STDMETHOD	<GetMaxVertices>
  STDMETHOD	<GetMinVertices>
  STDMETHOD	<Save>, :DWORD, :DWORD, :DWORD
  STDMETHOD	<Optimize>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<GetAdjacency>, :DWORD

LPD3DXPMESH	typedef	ptr

DECLARE_INTERFACE <ID3DXSPMesh_>
; /*** IUnknown methods ***/
  INHERIT_IUnknown
; /*** ID3DXSPMesh methods ***/
  STDMETHOD	<GetNumFaces>
  STDMETHOD	<GetNumVertices>
  STDMETHOD	<GetFVF>
  STDMETHOD	<GetDeclaration>, :DWORD
  STDMETHOD	<GetOptions>
  STDMETHOD	<GetDevice>, :DWORD
  STDMETHOD	<CloneMeshFVF>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<CloneMesh>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<ClonePMeshFVF>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<ClonePMesh>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<ReduceFaces>, :DWORD
  STDMETHOD	<ReduceVertices>, :DWORD
  STDMETHOD	<GetMaxFaces>
  STDMETHOD	<GetMaxVertices>

LPD3DXSPMESH	typedef	PTR

DECLARE_INTERFACE <ID3DXSkinMesh_>
; /*** IUnknown methods ***/
  INHERIT_IUnknown
; /*** ID3DXSkinMesh methods ***/

  STDMETHOD	<GetNumFaces>
  STDMETHOD	<GetNumVertices>
  STDMETHOD	<GetFVF>
  STDMETHOD	<GetDeclaration>, :DWORD
  STDMETHOD	<GetOptions>
  STDMETHOD	<GetDevice>, :DWORD
  STDMETHOD	<GetVertexBuffer>, :DWORD
  STDMETHOD	<GetIndexBuffer>, :DWORD
  STDMETHOD	<LockVertexBuffer>, :DWORD, :DWORD
  STDMETHOD	<UnlockVertexBuffer>
  STDMETHOD	<LockIndexBuffer>, :DWORD, :DWORD
  STDMETHOD	<UnlockIndexBuffer>
  STDMETHOD	<LockAttributeBuffer> , :DWORD, :DWORD
  STDMETHOD	<UnlockAttributeBuffer>
  STDMETHOD	<GetNumBones>
  STDMETHOD	<GetOriginalMesh>, :DWORD
  STDMETHOD	<SetBoneInfluence>, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<GetNumBoneInfluences>, :DWORD
  STDMETHOD	<GetBoneInfluence>, :DWORD, :DWORD, :DWORD
  STDMETHOD	<GetMaxVertexInfluences>, :DWORD
  STDMETHOD	<GetMaxFaceInfluences>, :DWORD
  STDMETHOD	<ConvertToBlendedMesh>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<ConvertToIndexedBlendedMesh>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<GenerateSkinnedMesh>, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  STDMETHOD	<UpdateSkinnedMesh>, :DWORD, :DWORD


LPD3DXSKINMESH	typedef	PTR

_D3DXMESH 			TYPEDEF		DWORD
D3DXMESH			TYPEDEF		_D3DXMESH

D3DXMESH_32BIT			EQU		00001h
D3DXMESH_DONOTCLIP              EQU		00002h
D3DXMESH_POINTS                 EQU		00004h
D3DXMESH_RTPATCHES              EQU		00008h
D3DXMESH_NPATCHES		EQU		04000h
D3DXMESH_VB_SYSTEMMEM		EQU		00010h
D3DXMESH_VB_MANAGED             EQU		00020h
D3DXMESH_VB_WRITEONLY           EQU		00040h
D3DXMESH_VB_DYNAMIC             EQU		00080h
D3DXMESH_IB_SYSTEMMEM		EQU		00100h
D3DXMESH_IB_MANAGED             EQU		00200h
D3DXMESH_IB_WRITEONLY           EQU		00400h
D3DXMESH_IB_DYNAMIC             EQU		00800h
                                   		
D3DXMESH_VB_SHARE               EQU		01000h
D3DXMESH_USEHWONLY              EQU		02000h
                                   		
D3DXMESH_SYSTEMMEM		EQU		00110h
D3DXMESH_MANAGED                EQU		00220h
D3DXMESH_WRITEONLY              EQU		00440h
D3DXMESH_DYNAMIC                EQU		00880h


_D3DXMESHSIMP 			TYPEDEF		DWORD
D3DXMESHSIMP			TYPEDEF		_D3DXMESHSIMP

D3DXMESHSIMP_VERTEX   		equ		01
D3DXMESHSIMP_FACE     		equ		02


;_MAX_FVF_DECL_SIZE		TYPEDEF		DWORD
;MAX_FVF_DECL_SIZE		TYPEDEF		_MAX_FVF_DECL_SIZE

MAX_FVF_DECL_SIZE 		equ		20


_D3DXATTRIBUTERANGE		struct

  AttribId			dword		?
  FaceStart			dword		?
  FaceCount			dword		?
  VertexStart			dword		?
  VertexCount			dword		?

_D3DXATTRIBUTERANGE		ends

D3DXATTRIBUTERANGE		typedef		_D3DXATTRIBUTERANGE
LPD3DXATTRIBUTERANGE		typedef	ptr	D3DXATTRIBUTERANGE

_D3DXMATERIAL			struct 

  MatD3D			D3DMATERIAL8	<>
  pTextureFilename		DWORD		?

_D3DXMATERIAL			ENDS

D3DXMATERIAL			TYPEDEF		_D3DXMATERIAL
LPD3DXMATERIAL                  TYPEDEF Ptr	D3DXMATERIAL

_D3DXATTRIBUTEWEIGHTS		STRUCT

    Position			FLOAT		?
    Boundary			FLOAT		?
    Normal			FLOAT		?
    Diffuse			FLOAT		?
    Specular			FLOAT		?
    Tex				FLOAT		8	DUP	(?)

_D3DXATTRIBUTEWEIGHTS		ENDS

D3DXATTRIBUTEWEIGHTS		TYPEDEF		_D3DXATTRIBUTEWEIGHTS
LPD3DXATTRIBUTEWEIGHTS		TYPEDEF PTR	D3DXATTRIBUTEWEIGHTS


UNUSED16			equ		0ffffh
UNUSED32			equ		0ffffffffh


_D3DXMESHOPT			typedef		dword
D3DXMESHOPT			typedef		_D3DXMESHOPT

D3DXMESHOPT_COMPACT       	equ		0001h
D3DXMESHOPT_ATTRSORT       	equ		0002h
D3DXMESHOPT_VERTEXCACHE        	equ		0004h
D3DXMESHOPT_STRIPREORDER       	equ		0008h
D3DXMESHOPT_IGNOREVERTS       	equ		0010h
D3DXMESHOPT_SHAREVB       	equ		0020h

_D3DXBONECOMBINATION		struct

  AttribId			dword		?
  FaceStart			dword		?
  FaceCount			dword		?
  VertexStart			dword		?
  VertexCount			dword		?
  BoneId			dword		?
  
_D3DXBONECOMBINATION		ENDS

D3DXBONECOMBINATION		typedef		_D3DXBONECOMBINATION
LPD3DXBONECOMBINATION		typedef ptr	D3DXBONECOMBINATION


_D3DXERR			typedef		DWORD
D3DXERR				typedef		_D3DXERR
               	
MAKE_D3DHRESULT	D3DXERR_CANNOTMODIFYINDEXBUFFER, 2900
MAKE_D3DHRESULT	D3DXERR_INVALIDMESH,		 2901
MAKE_D3DHRESULT	D3DXERR_CANNOTATTRSORT,          2902
MAKE_D3DHRESULT	D3DXERR_SKINNINGNOTSUPPORTED,	 2903
MAKE_D3DHRESULT	D3DXERR_TOOMANYINFLUENCES,	 2904
MAKE_D3DHRESULT	D3DXERR_INVALIDDATA,             2905
MAKE_D3DHRESULT	D3DXERR_LOADEDMESHASNODATA,             2906

endif 

    