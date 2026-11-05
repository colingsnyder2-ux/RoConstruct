// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct IDirect3D9;
typedef IDirect3D9* (__stdcall *PFN_Direct3DCreate9)(unsigned int);
extern PFN_Direct3DCreate9 g_pfnDirect3DCreate9;
bool LoadD3D9();
extern "C" IDirect3D9* __stdcall Direct3DCreate9(unsigned int SDKVersion)
{
    if (LoadD3D9() && g_pfnDirect3DCreate9)
        return g_pfnDirect3DCreate9(SDKVersion);
    return 0;
}
