// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S {
    int value;
    int refs;
    int f();
};

int S::f()
{
    value = 0;
    refs = 0;
    return 0;
}
