// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CWnd57 { char pad[0xfc]; bool fullscreen; };
struct CWinApp57 { char pad[0x20]; CWnd57* m_pMainWnd; };
struct AFX_MODULE_STATE57 { void* a; CWinApp57* m_pCurrentWinApp; };
AFX_MODULE_STATE57* __stdcall AfxGetModuleState57();
inline CWinApp57* AfxGetApp57() { return AfxGetModuleState57()->m_pCurrentWinApp; }
struct ToggleFullscreenVerb { bool isChecked(); };
bool ToggleFullscreenVerb::isChecked() { return AfxGetApp57()->m_pMainWnd->fullscreen; }
