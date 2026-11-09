// from server: 39% by atomic.potato
struct VTaBoundFuncDesc {
    char pad0[0x1c];
    int field1c;
    char pad20[0x10];
    int field30;
    int field34;
    void* field0;
    void* construct(int, int, int, int, int, int);
};

extern "C" void __stdcall sub_67d8b0(int, int, int, int, int, int);
extern "C" int __stdcall sub_7092a0();

void* VTaBoundFuncDesc::construct(int a, int b, int c, int d, int e, int f)
{
    sub_67d8b0(a, b, c, d, e, f);
    field0 = (void*)0xb8e594;
    field30 = c;
    field34 = d;
    field1c = sub_7092a0();

    return this;
}
