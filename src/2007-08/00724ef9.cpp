// from server: 100% by colin
struct CXTIconHandle {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    CXTIconHandle* construct();
};

struct Sub4018b0 {
    void method();
};

extern "C" void __stdcall sub_4018b0();

CXTIconHandle* CXTIconHandle::construct()
{
    ((Sub4018b0*)((char*)this + 4))->method();
    field20 = 0;
    field24 = 0;
    field28 = 0;
    return this;
}
