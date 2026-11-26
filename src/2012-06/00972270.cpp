// from server: 100% by Xemicl
// roc 2012-06 00972270  unit: seg_00970000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00972270
//
// 00972270  e8dbfeffff           call 0x972150
// 00972275  84c0                 test al, al
// 00972277  740b                 je 0x972284
// 00972279  a17080e500           mov eax, dword ptr [0xe58070]
// 0097227e  85c0                 test eax, eax
// 00972280  7402                 je 0x972284
// 00972282  ffe0                 jmp eax
// 00972284  33c0                 xor eax, eax
// 00972286  c20400               ret 4
// copied from an identical function in another client (function _Direct3DCreate9@4)

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