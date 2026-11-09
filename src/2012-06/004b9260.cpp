// from server: 88% by atomic.potato
extern "C" long __stdcall InterlockedIncrement(long volatile *);

struct S_func_004b9260 {
    char pad0[8];
    long m_value;
    int __stdcall f();
};

int __stdcall S_func_004b9260::f()
{
    long volatile *p = &m_value;
    InterlockedIncrement(p);
    return m_value <= 1 ? 1 : m_value;
}
