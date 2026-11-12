// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 00668540  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 341 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00668540
// Target (from roc check): EH frame, base ctor call, vptr store, ten 0x20-byte
// members constructed at 0x20..0x140, stores to 0x164/0x460/0x464/0x45c/0x160,
// a 0x3f-count loop filling 0x264.. and 0x360.. with -1, a thiscall on this,
// then three thiscalls on members 0x100/0x120/0x140 with (COLORREF, COLORREF, float).

typedef unsigned long COLORREF;

struct CColorBase {
    CColorBase();
    virtual ~CColorBase();
    char pad4[0x1c];
};

struct CColorGradient {
    CColorGradient();
    void SetStandardValue(COLORREF clrLight, COLORREF clrDark, float fGradientFactor);
    char data[0x20];
};

extern float g_797e9c;

struct CXTTreeBase_Map : public CColorBase {
    CColorGradient grad20;
    CColorGradient grad40;
    CColorGradient grad60;
    CColorGradient grad80;
    CColorGradient gradA0;
    CColorGradient gradC0;
    CColorGradient gradE0;
    CColorGradient grad100;
    CColorGradient grad120;
    CColorGradient grad140;
    int  field160;
    int  field164;
    char pad168[0xfc];
    int  arr264[0x3f];
    int  arr360[0x3f];
    int  field45c;
    int  field460;
    int  field464;

    CXTTreeBase_Map();
    virtual ~CXTTreeBase_Map();
    void RefreshColors();
};

CXTTreeBase_Map::CXTTreeBase_Map()
{
    field164 = 0;
    field460 = 4;
    field464 = 0;
    field45c = 0;
    field160 = 0;
    for (int i = 0; i < 0x3f; i++)
    {
        arr360[i] = -1;
        arr264[i] = -1;
    }
    RefreshColors();
    grad100.SetStandardValue(0x8cd5ff, 0x55adff, g_797e9c);
    grad120.SetStandardValue(0x4b8efe, 0x8bcfff, g_797e9c);
    grad140.SetStandardValue(0xc8f2ff, 0x97d4ff, g_797e9c);
}
