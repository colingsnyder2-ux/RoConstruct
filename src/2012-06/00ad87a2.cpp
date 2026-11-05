// from server: 61% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl sub_00983270(void *, int, int, const void *);

void S::f()
{
    sub_00983270((char *)this + 0xe8, 0x10, 2, (const void *)0x9611b0);
}
