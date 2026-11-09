// from server: 100% by atomic.potato
extern "C" void __declspec(dllimport) __stdcall LeaveCriticalSection(void *);

struct S
{
    void *m_lock;
    unsigned char m_locked;
    void f();
};

void S::f()
{
    if (m_locked)
    {
        LeaveCriticalSection(m_lock);
        m_locked = 0;
    }
}
