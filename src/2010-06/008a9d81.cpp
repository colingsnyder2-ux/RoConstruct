// from server: 61% by atomic.potato
struct CXTIconHandle {
    char pad0[0x14];
    char field14[0x18];
    int field2c;
    int field30;
    int field34;

    CXTIconHandle* f();
};

extern "C" void __fastcall sub_402c20(void*);

CXTIconHandle* CXTIconHandle::f()
{
    sub_402c20(field14);
    field2c = 0;
    field30 = 0;
    field34 = 0;
    return this;
}
