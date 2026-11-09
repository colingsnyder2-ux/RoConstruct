// from server: 100% by tajop
extern "C" {
    typedef unsigned int UINT;
    typedef unsigned int UINT_PTR;
    typedef void* HWND;
    typedef UINT_PTR (*TIMERPROC)(HWND, UINT, UINT_PTR, unsigned int);
    __declspec(dllimport) UINT_PTR __stdcall SetTimer(HWND, UINT_PTR, UINT, TIMERPROC);
    __declspec(dllimport) int __stdcall KillTimer(HWND, UINT_PTR);
}

struct CXTPDockingPaneMiniWnd {
    char pad[0x20];
    HWND m_hWnd;
    char pad2[0x128 - 0x24];
    int m_nTimerInterval;
    int m_nTimerCount;
    int m_nTimerSteps;
    int m_nTimerActive;
    int m_nTimerState;
    int m_nTimerFlag;
    int sub_6df790(int);
    void sub_6dec90(int);
    void OnTimer();
};

void CXTPDockingPaneMiniWnd::OnTimer()
{
    if (m_nTimerActive == 0)
        return;
    if (m_nTimerCount > 0)
        return;
    if (m_nTimerFlag != 0)
    {
        m_nTimerFlag = 0;
        m_nTimerState = 0;
        KillTimer(m_hWnd, 3);
        sub_6df790(0xb);
    }
    if (sub_6df790(0xc) == 0)
    {
        m_nTimerCount = m_nTimerInterval;
        m_nTimerState = 1;
        sub_6dec90(1);
        m_nTimerSteps = 8;
        SetTimer(m_hWnd, 1, 0x64, 0);
        sub_6df790(0xd);
    }
}
