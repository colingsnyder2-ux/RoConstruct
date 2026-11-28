// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: base with virtual dtor (vtable 0x80b730), derived owns a pointer at +0x18.
// Real BoundProp layout is not available.
struct PropBase {
    int pad[5];
    virtual ~PropBase() {}
};

struct BoundPropTextureId : PropBase {
    int* owned; // INFERRED: offset 0x18 (global 0x97b240 minus 0x97b228)
    ~BoundPropTextureId() { if (owned) delete owned; }
};

BoundPropTextureId prop_SkyRt;

extern "C" void __cdecl fn_007ffe50(void)
{
    prop_SkyRt.~BoundPropTextureId();
}
