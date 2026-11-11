// >>> native-status (generated) -- do not edit >>>
// CChildFrame | 2008-06 | 3 byte-exact, inactive (not link-selected)
// 3/4 mapped addresses byte-exact | 1 unproved | no mapped strings | by atomic.potato (+1) (mixed 3)
// <<< native-status | src fa5b8315 | roc native-status --write
#include "CChildFrame.h"

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
    ON_WM_CREATE()
END_MESSAGE_MAP()

// Inlined into the deleting destructor 00412c60 (vptr store, then CFrameWnd::~CFrameWnd).
CChildFrame::~CChildFrame()
{
}

// 00412b00: open at the client origin with the largest size, keep the view from painting over children.
BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.x = cs.y = 0;
    cs.cx = cs.cy = 0x7fff;
    if (!CMDIChildWnd::PreCreateWindow(cs))
        return FALSE;
    cs.style |= WS_CLIPCHILDREN;
    return TRUE;
}

// 00412b40: the first MDI child (the top of the MDI client's z-order) always opens maximized.
void CChildFrame::ActivateFrame(int nCmdShow)
{
    CMDIChildWnd::ActivateFrame(GetParent()->GetWindow(GW_CHILD) == this ? SW_SHOWMAXIMIZED : nCmdShow);
}

// 00412b90: strip the system menu, drop the pane's border and give it a client edge instead.
int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    m_hMenuShared = NULL;
    CMenu* menu = GetSystemMenu(FALSE);
    menu->RemoveMenu(SC_RESTORE, MF_BYCOMMAND);
    menu->RemoveMenu(SC_MINIMIZE, MF_BYCOMMAND);
    menu->RemoveMenu(SC_MAXIMIZE, MF_BYCOMMAND);
    menu->RemoveMenu(SC_MOVE, MF_BYCOMMAND);
    menu->RemoveMenu(SC_SIZE, MF_BYCOMMAND);
    CWnd* pane = GetDescendantWindow(AFX_IDW_PANE_FIRST, TRUE);
    pane->ModifyStyle(WS_BORDER, 0, 0);
    pane->ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_FRAMECHANGED);
    return 0;
}

IMPLEMENT_DYNCREATE(CRbxChildFrame, CChildFrame)

BEGIN_MESSAGE_MAP(CRbxChildFrame, CChildFrame)
    ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

#ifdef NATIVE_CHILD_FRAME_PENDING
// Pending a shared-header change: the original calls CRenderSettings::getFullscreenSize out of line
// (call 00445250 with a hidden return slot), so the declaration it saw was not the in-class inline body
// that native-headers/CRenderSettings.h has now. With that one line changed to the declaration
// "G3D::Vector2int16 getFullscreenSize() const;" this body is exact (tests/record_native_child_frame.py).
#include "CMainFrame.h"
#include "CRenderSettings.h"

// 00412e60: grow the maximized size by 40 pixels in full-screen mode without toolbars; while not zoomed,
// limit the tracking size to the frame rectangle around the render settings' full-screen size.
void CRbxChildFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
    Default();
    CMainFrame* frame = static_cast<CMainFrame*>(GetParentFrame());
    if (frame && frame->stateF8 && frame->GetCommandBars()->GetCount() == 0) {
        lpMMI->ptMaxSize.x += 40;
        lpMMI->ptMaxSize.y += 40;
        lpMMI->ptMaxTrackSize.x += 40;
        lpMMI->ptMaxTrackSize.y += 40;
    }
    if (!IsZoomed()) {
        G3D::Vector2int16 size = CRenderSettings::singleton().getFullscreenSize();
        RECT rect = {0, 0, size.x, size.y};
        CalcWindowRect(&rect, 0);
        lpMMI->ptMaxTrackSize.x = rect.right - rect.left;
        lpMMI->ptMaxTrackSize.y = rect.bottom - rect.top;
    }
}
#endif
