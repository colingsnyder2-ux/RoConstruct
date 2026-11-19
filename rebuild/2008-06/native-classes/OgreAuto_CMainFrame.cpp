// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/CMainFrame.h"

void CMainFrame::OnSetPreviewMode(BOOL bPreview, CPrintPreviewState* pState)
{
    GetCommandBars()->OnSetPreviewMode(bPreview);
    int flag = 0;
    if (bPreview == 0)
        flag = (state104 == 0);
    tabClient.ShowWorkspace(flag);
    dockingPanes.OnSetPreviewMode(bPreview);
    if (GetCommandBars() != 0)
        GetCommandBars()->OnSetPreviewMode(bPreview);
    CFrameWnd::OnSetPreviewMode(bPreview, pState);
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    if (!CXTPMDIFrameWnd::PreCreateWindow(cs))
        return FALSE;

    AfxGetModuleState();
    cs.lpszClass = AfxRegisterWndClass(0, 0, 0,
        LoadIcon(AfxFindResourceHandle(MAKEINTRESOURCE(128), RT_GROUP_ICON),
                 MAKEINTRESOURCE(128)));
    return TRUE;
}

