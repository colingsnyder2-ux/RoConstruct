// from server: 32% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S005b5e00
{
    long value;
    void f();
};

volatile long g_00e25d84;

void S005b5e00::f()
{
    long old = _InterlockedExchangeAdd(&g_00e25d84, 1);
    value = old;
}
