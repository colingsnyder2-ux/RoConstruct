// from server: 1% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_func_004cc450 {
    char pad0[2120];
    int m_x;
    int f();
};
int S_func_004cc450::f() { return m_x; }
