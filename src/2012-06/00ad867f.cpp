// from server: 65% by atomic.potato
extern "C" void __cdecl Function983270(void *, int, int, const void *);

struct S
{
    int value;
    void f();
};

void S::f()
{
    Function983270((char *)this + 0x108, 0x10, 2, (const void *)0x9611b0);
}
