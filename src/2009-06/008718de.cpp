// from server: 63% by atomic.potato
struct S {
    char pad[0x58];
    void f();
};

extern "C" void __cdecl sub_719b76(void *, unsigned int, unsigned int, const char *);

void S::f()
{
    sub_719b76((void *)((char *)this + 0x58), 0x20, 4, "SUVW");
}
