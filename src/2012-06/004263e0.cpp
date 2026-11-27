// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct HWND__;
extern "C" __declspec(dllimport) int __stdcall PostMessageA(HWND__ *, unsigned int, unsigned int, long);
struct CWnd { char pad[0x20]; HWND__ *m_hWnd; };
struct CWinApp { char pad[0x20]; CWnd *m_pMainWnd; };
struct State { int x; CWinApp *app; };
State *__stdcall AfxGetModuleState();
void __stdcall func(int value)
{
    CWinApp *app = AfxGetModuleState()->app;
    if (value == 0)
        PostMessageA(app->m_pMainWnd->m_hWnd, 0x111, 0x8124, 0);
}