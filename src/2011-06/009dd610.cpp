// from server: 63% by atomic.potato
struct S
{
    int value;

    void f();
};

extern "C" void __cdecl sub_0080B1D8(int, int, int, const void *);

void S::f()
{
    sub_0080B1D8((int)this + 8, 8, 2, (const void *)0x7736F0);
}
