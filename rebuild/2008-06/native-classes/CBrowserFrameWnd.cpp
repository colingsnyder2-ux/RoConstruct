// >>> native-status (generated) -- do not edit >>>
// CBrowserFrameWnd | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by king_originala (deepseek:deepseek-flash)
// <<< native-status | src c7883fa0 | roc native-status --write
#include "CBrowserFrameWnd.h"

IMPLEMENT_DYNCREATE(CBrowserFrameWnd, CXTPFrameWnd)

BEGIN_MESSAGE_MAP(CBrowserFrameWnd, CFrameWnd)
    ON_WM_DESTROY()
    ON_WM_CREATE()
    ON_WM_NCDESTROY()
END_MESSAGE_MAP()

// 00433130: drop the frame's menu and give the pane a clean (borderless, no client edge) look.
int CBrowserFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    CMenu* menu = GetMenu();
    if (menu && ::IsMenu(menu->m_hMenu)) {
        menu->DestroyMenu();
        SetMenu(NULL);
    }
    CWnd* pane = GetDescendantWindow(m_hWnd, AFX_IDW_PANE_FIRST, TRUE);
    pane->ModifyStyle(WS_BORDER, 0, SWP_FRAMECHANGED);
    pane->ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_FRAMECHANGED);
    return 0;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class CXTPFrameWndBase<CFrameWnd>;
