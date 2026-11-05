// from server: 63% by atomic.potato
extern "C" void __cdecl sub_00983270(void *, unsigned int, unsigned int, const void *);

struct S {
    int value;
    void f();
};

void S::f()
{
    sub_00983270((char *)this + 0x38, 0x0c, 5, (const void *)0x008aed40);
}
