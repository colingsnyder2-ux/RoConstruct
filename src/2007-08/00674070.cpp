// from server: 100% by tester
extern "C" void __stdcall UnhookWindowsHookEx(void*);

typedef void* (__stdcall *FreeFn)(void*);

struct CXTPCustomizeSheet
{
    void* m_p0;
    char pad[8];
    void* m_pC;
    char pad2[8];
    void* m_p18;
    void Cleanup();
};

void CXTPCustomizeSheet::Cleanup()
{
    FreeFn freeFn = *(FreeFn*)0x77ee38;

    if (m_p0 != 0)
    {
        freeFn(m_p0);
        m_p0 = 0;
    }
    if (m_pC != 0)
    {
        freeFn(m_pC);
        m_pC = 0;
    }
    if (m_p18 != 0)
    {
        freeFn(m_p18);
        m_p18 = 0;
    }
    *(int*)0x8c8f38 = 0;
    if (m_p18 != 0)
    {
        freeFn(m_p18);
        m_p18 = 0;
    }
    if (m_pC != 0)
    {
        freeFn(m_pC);
        m_pC = 0;
    }
    if (m_p0 != 0)
    {
        freeFn(m_p0);
        m_p0 = 0;
    }
}
