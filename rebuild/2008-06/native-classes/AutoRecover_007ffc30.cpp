// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: BoundProp<TextureId,1> layout from disassembly: object at 0x97b414,
// owned pointer at +0x18, vtable pointer at +0 reset to base descriptor vtable (0x80b730).
// INFERRED: owned type has an empty non-trivial dtor, so delete keeps its null check.
extern "C" char g_vtbl_0080b730[];

struct OwnedValue {
    int v;
    ~OwnedValue() {}
};

struct BoundPropTextureIdLayout {
    void* vtbl;
    int pad[5];
    OwnedValue* owned;
};

BoundPropTextureIdLayout prop_SkyRt;

// dynamic atexit destructor for Sky::prop_SkyRt
extern "C" void fn_007ffc30(void)
{
    delete prop_SkyRt.owned;
    prop_SkyRt.vtbl = g_vtbl_0080b730;
}
