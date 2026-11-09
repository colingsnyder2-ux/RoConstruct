// from server: 56% by atomic.potato
struct CriticalSection
{
    int value;
};

struct S
{
    int f(int);
};

extern "C" void __stdcall EnterCriticalSection(CriticalSection *);
extern "C" void __stdcall LeaveCriticalSection(CriticalSection *);
extern CriticalSection g_9ea370;
extern CriticalSection g_9ea374;
extern S *sub_775e90(S *, void *);

int S::f(int flags)
{
    S *p = this;
    if (flags & 1)
    {
        S *q = sub_775e90(this, 0);
        EnterCriticalSection(&g_9ea374);
        p->f(0);
        q->f(0);
        LeaveCriticalSection(&g_9ea370);
    }
    return (int)p;
}
