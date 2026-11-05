// from server: 56% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);

struct S
{
    int value;
    int f(unsigned char);
};

int S::f(unsigned char value)
{
    S *p = this;
    if ((value & 1) != 0)
    {
        int *q = (int *)0x450a00;
        EnterCriticalSection(q);
        int *old = (int *)((char *)q + 0x18);
        p->value = *old;
        *(int *)((char *)q + 0x18) = (int)p;
        LeaveCriticalSection(q);
    }
    return (int)p;
}
