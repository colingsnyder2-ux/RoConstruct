// from server: 2% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_func_006b44b0 {
    void f(int a1, int a2, int a3, int a4);
};

void S_func_006b44b0::f(int a1, int a2, int a3, int a4)
{
    char pad[0x28];
    int v = 0;
    (void)pad;
    (void)v;
    (void)a1; (void)a2; (void)a3; (void)a4;
}
