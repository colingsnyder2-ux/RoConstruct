// from server: 54% by atomic.potato
struct VPlayerFactoryProduct {
    char pad0[0x1c];
    int field1c;
    char pad20[0x10];
    int field30;
    int field34;
    void* ctor(int, int, int, int, int, int);
};

extern "C" int __cdecl sub_7092a0();
extern "C" int __cdecl sub_52cf50(int, int, int, int);

void* VPlayerFactoryProduct::ctor(int a, int b, int c, int d, int e, int f)
{
    sub_52cf50(a, b, c, d);
    *(int*)this = 0xb70734;
    field30 = e;
    field34 = f;
    field1c = sub_7092a0();

    return this;
}
