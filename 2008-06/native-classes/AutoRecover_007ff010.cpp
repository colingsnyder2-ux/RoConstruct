// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: minimal layout model of BoundProp<TextureId,1> static object.
struct PropBase {
    virtual ~PropBase() {}
    char pad[0x14];
};

struct BoundPropLayout : PropBase {
    void* owned; // at +0x18 (0x979ea4 - 0x979e8c)
    virtual ~BoundPropLayout() {
        if (owned)
            ::operator delete(owned);
    }
};

extern BoundPropLayout g_00979e8c;

// INFERRED: dynamic atexit destructor of Sky::prop_SkyRt
extern "C" void fn_007ff010(void)
{
    g_00979e8c.BoundPropLayout::~BoundPropLayout();
}
