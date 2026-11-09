// from server: 83% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);

struct S
{
    S *f(int);
};

extern "C" S *sub_450a60();

S *S::f(int flags)
{
    S *p = this;
    if (flags & 1)
    {
        S *q = sub_450a60();
        EnterCriticalSection(q);
        p->f(0);
        LeaveCriticalSection(q);
    }
    return p;
}
