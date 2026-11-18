// native-flags: unit=CPatchedControlComboBox size=47 cc=thiscall ret=8 retbuf=hidden
#include <afxwin.h>

// NEEDS-DECL: class CXTPMultiMonitor { public: CRect GetScreenArea(HWND); CRect GetScreenArea(const CWnd*); CRect GetWorkArea(HWND); CRect GetWorkArea(const CWnd*); };

class CXTPMultiMonitor
{
public:
    CRect GetScreenArea(HWND hWnd);
    CRect GetScreenArea(const CWnd* pWnd);
    CRect GetWorkArea(HWND hWnd);
    CRect GetWorkArea(const CWnd* pWnd);
};

#pragma optimize("gty", on)

CRect CXTPMultiMonitor::GetScreenArea(const CWnd* pWnd)
{
    HWND h;
    if (pWnd == 0)
        h = 0;
    else
        h = pWnd->m_hWnd;
    return GetScreenArea(h);
}

CRect CXTPMultiMonitor::GetWorkArea(const CWnd* pWnd)
{
    HWND h;
    if (pWnd == 0)
        h = 0;
    else
        h = pWnd->m_hWnd;
    return GetWorkArea(h);
}
