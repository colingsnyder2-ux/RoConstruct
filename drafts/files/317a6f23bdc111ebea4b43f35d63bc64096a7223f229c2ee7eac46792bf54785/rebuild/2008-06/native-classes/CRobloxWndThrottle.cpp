// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// CRobloxWndThrottle | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src ceeaf939 | roc native-status --write
#include "CRobloxView.h"
#include <atlsync.h>

// Original shared lock lifetime: 007ef980 / 007faf20; original identifier unknown.
namespace {
ATL::CCriticalSection throttleCriticalSection;
}

// 0045ba60 (IRunView vtable 008199e8 slot 1; this = IRunView subobject at CRobloxWnd+0x54).
// Blocked on CRobloxView.h: the target stores the double at [this+0x3c] = CRobloxWnd+0x90,
// which the header currently covers with unaccessed_8c[3]. Header proposal: split it into
// 'unsigned unaccessed_8c; double pendingThrottle; // 0x90, written by 0045ba60'.
// Lock is the global CRITICAL_SECTION at 0096df6c (EnterCriticalSection/LeaveCriticalSection imports).
void CRobloxWnd::AdjustThrottle(double value)
{
    throttleCriticalSection.Enter();
    pendingThrottle = value;
    throttleCriticalSection.Leave();
}

void CRobloxWnd::InvalidateRunView()
{
    ::InvalidateRgn(m_hWnd, NULL, FALSE);
}
