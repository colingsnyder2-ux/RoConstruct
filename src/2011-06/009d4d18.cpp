// from server: 48% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl sub_0080b1D8(void *, int, int, const void *);

void S::f()
{
    char local[16];
    sub_0080b1D8(local, 0x10, 2, (const void *)0x417D60);
}
