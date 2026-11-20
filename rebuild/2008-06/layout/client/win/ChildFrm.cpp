#include "CChildFrame.h"

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
    ON_WM_CREATE()
END_MESSAGE_MAP()

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.x = cs.y = 0;
    cs.cx = cs.cy = 0x7fff;
    if (!CMDIChildWnd::PreCreateWindow(cs))
        return FALSE;
    cs.style |= WS_CLIPCHILDREN;
    return TRUE;
}

void CChildFrame::ActivateFrame(int nCmdShow)
{
    CMDIChildWnd::ActivateFrame(GetParent()->GetWindow(GW_CHILD) == this ? SW_SHOWMAXIMIZED : nCmdShow);
}

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

#include "CMainFrame.h"
#include "CRenderSettings.h"

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
