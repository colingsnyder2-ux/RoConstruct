// from server: 70% by atomic.potato
struct S
{
    void __cdecl f(int, int, int, int, int);
};

extern "C" void __cdecl sub_423960(int, int);
extern "C" void __cdecl sub_424820(int, int, int, int, int, int, int);

void __cdecl S::f(int a, int b, int c, int d, int e)
{
    sub_423960(1, e);
    sub_424820(b, 0, 0, e, c, 0x9f1740, d);
}
