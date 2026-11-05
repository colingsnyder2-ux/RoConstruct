// from server: 100% by colin
struct CXTPReBar {
    void* vftable;
    int field4;
    char pad8[0x14];
    int field1c;
    int field20;
    int field24;
    int field28;
    char pad2c[0x14];
    int field40;
    int field44;

    CXTPReBar();
    void Init(int);
};

struct Sub8 {
    void* vftable;
    void Init();
};

struct Sub2c {
    void* vftable;
    void Init();
};

void __stdcall sub_632d80();
void __stdcall sub_6a3980();

CXTPReBar::CXTPReBar()
{
    Sub8* p8;
    Sub2c* p2c;

    vftable = (void*)0x7d35a0;

    p8 = (Sub8*)((char*)this + 8);
    p8->Init();
    p8->vftable = (void*)0x7d3570;

    p2c = (Sub2c*)((char*)this + 0x2c);
    p2c->Init();
    p2c->vftable = (void*)0x7d3588;

    field1c = 0;
    field4 = 0;
    field24 = 0;
    field28 = 0;
    field20 = 0;
    field40 = 0;
    field44 = 0;

    Init(1);
}
