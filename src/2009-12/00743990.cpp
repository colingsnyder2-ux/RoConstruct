// from server: 32% by atomic.potato
extern "C" void __stdcall sub_743660();
extern "C" int __stdcall sub_650090();

struct S {
    char pad0[4];
    char pad4[0x14];
    char pad18[4];
    char pad1c[4];
    char pad20[0x74];
    char pad94[4];
    int field20;
    void* ctor();
};

void* S::ctor()
{
    sub_743660();
    *(int*)((char*)this + 0) = 0x9e2cec;
    *(int*)((char*)this + 4) = 0x9e2ce0;
    *(int*)((char*)this + 0x18) = 0x9e2cd4;
    *(int*)((char*)this + 0x1c) = 0x9e2ccc;
    *(int*)((char*)this + 0x94) = 0x9e2cb4;
    field20 = sub_650090();
    ++*(int*)0xb8fd78;

    return this;
}
