// from server: 100% by colin
struct CXTPReportControl {
    char pad[0x20];
    void* m_hwnd;
    char pad2[0x200];
    unsigned int m_timer;
    void KillTimerMethod();
};

extern "C" int (__stdcall *KillTimer)(void* hWnd, unsigned int uIDEvent);

void CXTPReportControl::KillTimerMethod()
{
    unsigned int t = m_timer;
    if (t != 0)
    {
        KillTimer(m_hwnd, t);
        m_timer = 0;
    }
}
