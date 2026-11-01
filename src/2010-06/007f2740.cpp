// from server: 100% by tester
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void* __stdcall SetWindowsHookExA(int, void*, void*, unsigned long);

struct CXTPCustomizeSheet {
    void* m_pHook1;
    int m_pad1;
    int m_pad2;
    void* m_pHook2;
    int m_pad3;
    int m_pad4;
    void* m_pHook3;
    void Init();
};

void CXTPCustomizeSheet::Init()
{
    unsigned long (__stdcall *pGetCurrentThreadId)() = GetCurrentThreadId;
    void* (__stdcall *pSetWindowsHookExA)(int, void*, void*, unsigned long) = SetWindowsHookExA;

    unsigned long tid = pGetCurrentThreadId();
    m_pHook1 = pSetWindowsHookExA(7, (void*)0x6734f0, 0, tid);

    tid = pGetCurrentThreadId();
    m_pHook2 = pSetWindowsHookExA(2, (void*)0x673550, 0, tid);

    tid = pGetCurrentThreadId();
    m_pHook3 = pSetWindowsHookExA(4, (void*)0x6735b0, 0, tid);
}
