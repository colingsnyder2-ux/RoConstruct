// from server: 29% by atomic.potato
extern "C" void __cdecl sub_983c70(int, int);

struct S
{
    void __cdecl f(int, int, int, void (__cdecl *)(int, int));
};

void S::f(int a, int b, int count, void (__cdecl *callback)(int, int))
{
    sub_983c70(0xd34588, 0x14);
    while (--count >= 0)
    {
        a -= b;
        callback(a, b);
    }
}
