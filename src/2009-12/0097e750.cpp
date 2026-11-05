// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    int f();
};

S* g_00b7b484;

int S::f()
{
    S* p = g_00b7b484;
    if (p == 0)
        return 0;

    long old = _InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1);
    if (old != 1)
        return 0;

    return ((int (__thiscall **)(S*))(*(void**)p))[2](p);
}
