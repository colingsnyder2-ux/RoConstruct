// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
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
