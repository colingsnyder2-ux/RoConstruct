// >>> native-status (generated) -- do not edit >>>
// CMainFrameWindow | 2008-06 | inactive
// 0/1 exact by name (0%) | 0/1 exact bodies | no strings | verified 2026-11-07| by tester
// <<< native-status | src 4e60f154 | roc native-status --write
#include "CMainFrame.h"

extern bool nativeLockA, nativeLockB, nativeLockC;

// 0042e500
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& create)
{
    if (!CMDIFrameWnd::PreCreateWindow(create)) return FALSE;
    AfxGetModuleState();
    create.lpszClass = AfxRegisterWndClass(0, 0, 0, ::LoadIcon(AfxFindResourceHandle(MAKEINTRESOURCE(0x80), RT_GROUP_ICON), MAKEINTRESOURCE(0x80)));
    return TRUE;
}

// 00430ae0
void CMainFrame::OnSetPreviewMode(BOOL preview, CPrintPreviewState* state)
{
    GetCommandBars()->OnSetPreviewMode(preview);
    tabClient.ShowWorkspace(preview ? FALSE : !state104);
    dockingPanes.OnSetPreviewMode(preview);
    if (GetCommandBars()) GetCommandBars()->OnSetPreviewMode(preview);
    CMDIFrameWnd::OnSetPreviewMode(preview, state);
}

// 00430bd0
void CMainFrame::handle_430bd0()
{
    if (!nativeLockC) {
        state105 = true;
        hideEditorChrome();
    }
}
