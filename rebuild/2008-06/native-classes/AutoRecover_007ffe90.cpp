// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers available for BoundProp<TextureId,1>; layout from disassembly only.
// Target is a dynamic atexit destructor with no linkable class-member name, so use the fn_ convention.
#include <new>

struct PropObj {
    const void* vtbl;   // +0x00
    char pad[0x1c - 4];
    void* owned;        // +0x1c, deleted in dtor
};

extern PropObj g_0097b128;          // RBX::Sky::prop_SkyRt
extern const char g_0080b730[];     // base descriptor vtable

extern "C" void fn_007ffe90(void)
{
    if (g_0097b128.owned)
        operator delete(g_0097b128.owned);
    g_0097b128.vtbl = g_0080b730;
}
