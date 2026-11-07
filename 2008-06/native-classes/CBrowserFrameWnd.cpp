// >>> native-status (generated) -- do not edit >>>
// CBrowserFrameWnd | 2008-06 | linked
// 1/1 exact by name (100%) | 1/1 exact bodies | no strings | verified 2026-11-07| by king_originala (deepseek:deepseek-flash)
// <<< native-status | src f7dd6285 | roc native-status --write
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
