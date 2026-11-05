// from server: 88% by atomic.potato
extern "C" long __stdcall InterlockedIncrement(long *);

struct S_func_004a3330 {
    char pad0[8];
    long m_value;
    long f(long *p);
};

long S_func_004a3330::f(long *p)
{
    S_func_004a3330 *s = (S_func_004a3330 *)((char *)p);
    InterlockedIncrement(&s->m_value);
    return s->m_value <= 1 ? 1 : s->m_value;
}
