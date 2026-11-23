// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// 00449550 is a CRobloxApp member, not a free function: the CRobloxApp message map (AFX_MSGMAP 00816c54, base map
// CWinApp::GetThisMessageMap, entries 00816c58) holds {0x402 = WM_USER + 2, 0, 0, 0, sig 0x1e, 00449550}, i.e.
// ON_THREAD_MESSAGE(WM_USER + 2, ...) as in the openrbx 2007 map (Client/win/Roblox.cpp:134, FUN_0044d450). The body
// ignores this and both arguments and returns with ret 8 (thiscall, two dwords). Statement shape from openrbx:
// AfxGetMainWnd() twice (AfxGetThread + vtable slot 0x7c each), CWnd::FlashWindow (m_hWnd at +0x20),
// AfxMessageBox(196), AfxPostQuitMessage(0).
// BLOCKED: CRobloxApp.h (maintainer exclusion, proposal only) does not declare this member, and the CRobloxApp.cpp
// message map does not route WM_USER + 2 yet. The member name is not known (placeholder func_00449550).
#include "CRobloxApp.h"

#ifdef CROBLOXAPP_HEADER_DECLARES_ONFATALMESSAGE
// 00449550
void CRobloxApp::onFatalMessage(WPARAM, LPARAM)
{
	if (AfxGetMainWnd())
	{
		AfxGetMainWnd()->FlashWindow(FALSE);
		AfxMessageBox(196);
	}

	AfxPostQuitMessage(0);
}
#endif
