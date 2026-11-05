// from server: 71% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    int f();
};

extern "C" void __cdecl helper(S**, int);

int S::f()
{
    S* p = 0;
    helper(&p, 0);
    if (p != 0)
        _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
    return 0;
}
