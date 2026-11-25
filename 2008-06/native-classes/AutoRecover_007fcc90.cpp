// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout of the static; only the vtable slot and the deleted pointer matter.
struct FakeProp {
    void* vtbl;
    char pad[0x14];
    void* owned;
};

extern FakeProp g_prop_SkyRt;
extern char g_vtbl_80b730[];

// INFERRED: stands in for the compiler-generated atexit destructor.
extern "C" void fn_007fcc90()
{
    if (g_prop_SkyRt.owned)
        operator delete(g_prop_SkyRt.owned);
    g_prop_SkyRt.vtbl = g_vtbl_80b730;
}
