// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// CRobloxWndThrottle | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src ceeaf939 | roc native-status --write
#include "CRobloxView.h"
#include <atlsync.h>

// Original shared lock lifetime: 007ef980 / 007faf20; original identifier unknown.
namespace {
ATL::CCriticalSection throttleCriticalSection;
}

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
