// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the object layout is minimal. It has a vptr at +0 and an owned pointer at +0x1c (0x97d7a0 - 0x97d784).
// INFERRED: 0x80b730 is the base-class vtable that the inlined ~BoundProp/~PropDescriptor chain stores.
// INFERRED: a dynamic atexit destructor can't be written under its mangled name here, so it uses the fn_ convention.
struct PropObj {
    void** vtbl;
    char pad[0x18];
    void* owned;
};

extern PropObj g_prop_SkyRt;        // 0x97d784 (Sky::prop_SkyRt)
extern void* g_vtbl_0080b730[];

extern "C" void fn_008010c0()
{
    if (g_prop_SkyRt.owned)
        operator delete(g_prop_SkyRt.owned);
    g_prop_SkyRt.vtbl = g_vtbl_0080b730;
}
