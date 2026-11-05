// from server: 86% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" void __cdecl helper1(const void *);
extern "C" void helper2(S *);

int S::f(void *p)
{
    int value = *(int *)p;
    if (value != *(int *)((char *)this + 0xbc))
    {
        *(int *)((char *)this + 0xbc) = value;
        helper1((const void *)0x00cbcfe8);
        helper2(this);
    }
    return 0;
}
