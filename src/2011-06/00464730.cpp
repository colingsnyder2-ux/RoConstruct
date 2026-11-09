// from server: 65% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    void* vptr;
    char padding[188];
    long value;
    volatile long* refcount;
    void f(long*);
};

void S::f(long* result)
{
    result[0] = value;
    result[1] = (long)refcount;
    if (refcount != 0)
        _InterlockedExchangeAdd(refcount + 1, 1);
}
