// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: minimal stand-in for BoundProp<TextureId,1> layout: vtable at +0, owned pointer at +0x18.
#include <new>

extern "C" char g_0080b730[]; // INFERRED: base class vtable symbol

struct PropStandIn {
    const void* vtable;
    char pad[0x14];
    void* owned;
};

extern "C" PropStandIn g_00979cd8; // INFERRED: RBX::Sky::prop_SkyRt

extern "C" void __cdecl fn_007fef30()
{
    void* p = g_00979cd8.owned;
    if (p)
        operator delete(p);
    g_00979cd8.vtable = g_0080b730;
}
