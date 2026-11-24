// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../native-donor-2007
// 00449550: CRobloxApp handler for ON_THREAD_MESSAGE(WM_USER + 2): CRobloxApp AFX_MSGMAP 00816c54, entry 00816d18
// {0x402, 0, 0, 0, sig 0x1e, 00449550}; openrbx 2007 analog Roblox.cpp:134 (FUN_0044d450). thiscall ret 8, `this` unused:
// when a main window exists it flashes it (FlashWindow(hwnd, FALSE)), shows string resource 0xc4 through
// AfxMessageBox(UINT, UINT, UINT) with (0, -1), then always AfxPostQuitMessage(0). The two AfxGetMainWnd() inlines
// (AfxGetThread 006a0e4e + CWinThread::GetMainWnd vtable slot +0x7c) are the original's.
// The previous file held an unrelated `function(int,int)` stub with no matching body; it is replaced.
// Guarded: CRobloxApp.h (not owned here) does not declare the member. Header proposal: add
//   afx_msg void onFatalMessage(WPARAM, LPARAM);   // 00449550
// to CRobloxApp and define CROBLOXAPP_HEADER_DECLARES_ONFATALMESSAGE there. The name is the 2007 analog's role
// (fatal-error message), INFERRED.
namespace RBX { const char* get_thread_name(); }
#include "CRobloxApp.h"

#ifdef CROBLOXAPP_HEADER_DECLARES_ONFATALMESSAGE
void CRobloxApp::onFatalMessage(WPARAM, LPARAM)
{
	if (AfxGetMainWnd())
	{
		FlashWindow(AfxGetMainWnd()->m_hWnd, FALSE);
		AfxMessageBox(0xc4, 0, (UINT)-1);
	}
	AfxPostQuitMessage(0);
}
#endif
