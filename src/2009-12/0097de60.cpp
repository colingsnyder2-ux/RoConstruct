// from server: 62% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    int value;
};

S* g_00b7a2f4;

void func_0097de60()
{
    S* p = g_00b7a2f4;
    if (p != 0)
    {
        long old = _InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1);
        if (old == 0)
            return;
        p->value;
    }
}
