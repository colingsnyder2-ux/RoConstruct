// from server: 62% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_func_00547070 {
    char pad0[16];
    long m_value;
    volatile long* m_ref;
    void f(void* result);
};

void S_func_00547070::f(void* result)
{
    long* p = (long*)result;
    p[0] = m_value;
    p[1] = (long)m_ref;
    if (m_ref != 0)
        _InterlockedExchangeAdd(m_ref + 1, 1);
}
