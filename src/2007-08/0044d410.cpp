// from server: 100% by tajop
struct HWND__;
extern "C" __declspec(dllimport) int __stdcall PostMessageA(HWND__*, unsigned int, unsigned int, long);

struct CWnd { char pad[0x20]; HWND__* m_hWnd; };
struct CWinThread { char pad[0x20]; CWnd* m_pMainWnd; };
struct AFX_MODULE_STATE { void* pad; CWinThread* m_pCurrentWinApp; };
extern "C" AFX_MODULE_STATE* __stdcall sub_0062FF02();
struct ReportAbuseVerb {
    void doIt(void*);
};

void ReportAbuseVerb::doIt(void*)
{
    CWnd* pWnd = sub_0062FF02()->m_pCurrentWinApp->m_pMainWnd;
    PostMessageA(pWnd->m_hWnd, 0x111, 0x8100, 0);
}
