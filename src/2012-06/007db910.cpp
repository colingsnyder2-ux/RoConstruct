// from server: 48% by atomic.potato
struct S
{
    int f();
    int a[36];
};

extern "C" int __cdecl sub_007dafc0(S*, int, int, int);

int S::f()
{
    return sub_007dafc0((S*)((char*)this + 0x8c), a[32], a[33], a[34]);
}
