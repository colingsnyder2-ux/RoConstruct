// from server: 61% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    unsigned char pad[0xe4];
    long value;
    long* ref;
    int f(long* result);
};

int S::f(long* result)
{
    result[0] = value;
    long* p = ref;
    result[1] = (long)p;
    if (p != 0)
        _InterlockedExchangeAdd((volatile long*)(p + 1), 1);
    return 0;
}
