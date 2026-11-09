// from server: 100% by colin
struct CArrayBase {
    void BaseInit();
};

struct CArrayDerived {
    char pad0[0x20];
    CArrayBase base;
    char pad2[0x10];
    int field34;

    CArrayDerived* Init();
};

extern "C" void __fastcall sub_73833a(void*);
extern "C" void __fastcall sub_684050(CArrayBase*);

CArrayDerived* CArrayDerived::Init()
{
    sub_73833a(this);
    *(int*)this = 0x7cf134;
    sub_684050(&base);
    field34 = 0;
    return this;
}
