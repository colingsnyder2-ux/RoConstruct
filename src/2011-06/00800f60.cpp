// from server: 73% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" void __stdcall LeaveCriticalSection(void *);

struct S
{
    int m_0;
    unsigned int m_4;
    char m_cs[0x1c];
    int *m_begin;
    int *m_end;
    bool f(int arg);
};

bool S::f(int arg)
{
    EnterCriticalSection(m_cs);

    unsigned int count = (unsigned int)(m_end - m_begin);
    if (m_4 < count)
    {
        int val = m_begin[m_4];
        bool r = (val != arg);
        LeaveCriticalSection(m_cs);
        return r;
    }

    LeaveCriticalSection(m_cs);
    return true;
}
