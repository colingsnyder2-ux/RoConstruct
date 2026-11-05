// from server: 62% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_005dfa00
{
    char pad0[16];
    long m_value0;
    long* m_value1;
    void f(long*);
};

void S_005dfa00::f(long* out)
{
    out[0] = m_value0;
    out[1] = (long)m_value1;
    if (m_value1)
        _InterlockedExchangeAdd((volatile long*)((char*)m_value1 + 4), 1);
}
