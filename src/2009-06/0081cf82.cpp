// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O1 /Oy- /hotpatch /GS- /MD
struct D3DXMATRIX;
struct D3DXVECTOR3;
typedef D3DXMATRIX* (__stdcall *PFN)(D3DXMATRIX*, const D3DXVECTOR3*, float);
extern "C" void __stdcall D3DXCpuInit(int);
extern "C" PFN g_pfn43;
extern "C" D3DXMATRIX* __stdcall D3DXFunc43(D3DXMATRIX* pOut, const D3DXVECTOR3* pV, float angle)
{
    D3DXCpuInit(1);
    return g_pfn43(pOut, pV, angle);
}
