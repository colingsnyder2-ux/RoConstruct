// from server: 51% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    long *p;

    void f(long *p);
};

void S::f(long *p)
{
    this->p = p;
    if (p != 0)
        _InterlockedExchangeAdd((volatile long *)(p + 1), 1);
}
