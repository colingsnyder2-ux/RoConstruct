// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// MainLogManager unit (LogManager.cpp) pure-call handler, emitted just before relocateLog 00428310.
// MainLogManagerRecovery.cpp installs it with _set_purecall_handler and declares it with external linkage, and no
// other native unit defines it, so it lives in this small unit. The openrbx 2007 analog (Client/win/LogManager.cpp)
// reports through LogManager::ReportEvent; the 2008 client calls reportWorkspaceStatus 00427c20 (push 1 / push msg).
#include <afxwin.h>

extern void __cdecl reportWorkspaceStatus(unsigned short, const char*);

// 004282a0
void __cdecl purecallHandler()
{
	CString eventMessage;
	eventMessage.Format("Pure Call Error");
	reportWorkspaceStatus(1, eventMessage);

	int* p = NULL;
	*p = p[1];
}
