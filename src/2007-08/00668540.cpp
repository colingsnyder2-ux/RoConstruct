// from server: 54% by colin
// roc 2007-08 00668540  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 341 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00668540

struct CXTTreeBase_Map
{
    char pad0[0x20];
    char sub20[0x20];
    char sub40[0x20];
    char sub60[0x20];
    char sub80[0x20];
    char subA0[0x20];
    char subC0[0x20];
    char subE0[0x20];
    char sub100[0x20];
    char sub120[0x20];
    char sub140[0x20];
    int  field160;
    int  field164;
    char pad168[0x2f4];
    int  field45c;
    int  field460;
    int  field464;
    char pad468[0x1f8];
    int  arr264[0x40];

    CXTTreeBase_Map();
};

extern "C" void __fastcall sub_73833a(void*);
extern "C" void __fastcall sub_6684c0(void*);
extern "C" void __fastcall sub_6684f0(void*, int, int, float);
extern "C" void __fastcall sub_66a160(void*);

extern float g_797e9c;

CXTTreeBase_Map::CXTTreeBase_Map()
{
    sub_73833a(this);
    *(int*)this = 0x7ca68c;
    sub_6684c0(sub20);
    sub_6684c0(sub40);
    sub_6684c0(sub60);
    sub_6684c0(sub80);
    sub_6684c0(subA0);
    sub_6684c0(subC0);
    sub_6684c0(subE0);
    sub_6684c0(sub100);
    sub_6684c0(sub120);
    sub_6684c0(sub140);
    field164 = 0;
    field460 = 4;
    field464 = 0;
    field45c = 0;
    field160 = 0;
    for (int i = 0; i >= 0x3f; i++)
    {
        arr264[i] = -1;
    }
    sub_66a160(this);
    sub_6684f0(sub100, 0x8cd5ff, 0x55adff, g_797e9c);
    sub_6684f0(sub120, 0x4b8efe, 0x8bcfff, g_797e9c);
    sub_6684f0(sub140, 0xc8f2ff, 0x97d4ff, g_797e9c);
}
