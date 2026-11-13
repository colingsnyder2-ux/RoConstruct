// >>> native-status (generated) -- do not edit >>>
// CMainFrameCreate | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by EspClaude (+1) (deepseek:deepseek-chat)
// <<< native-status | src f5ae3801 | roc native-status --write
#include "CMainFrame.h"
#include "LoginRenewer.h"
#include "MyXTPCommandBars.h"

void InitializeAllIcons(CXTPImageManager*);
UINT nativeStatusIndicators[] = {0, 0xbb, 0xbe, 0xd1, 0xbc, 0xbd};

int CMainFrame::OnCreate(LPCREATESTRUCT create)
{
    if (CMDIFrameWnd::OnCreate(create) == -1) return -1;
    if (!status.Create(this, 0x50008200, 0xe801)) return 0;
    if (!status.SetIndicators(nativeStatusIndicators, 6)) return 0;
    if (!InitCommandBars(const_cast<CRuntimeClass*>(&MyXTPCommandBars::classMyXTPCommandBars))) return -1;
    theme.SetTheme((XTThemeStyle)2);
    CXTPPaintManager::SetTheme((XTPPaintTheme)4);
    dockingPanes.InstallDockingPanes(this, true);
    dockingPanes.SetTheme((XTPDockingPanePaintTheme)9);
    tabClient.Attach(this, FALSE);
    tabClient.GetPaintManager()->m_bShowIcons = FALSE;
    tabClient.EnableToolTips((XTPTabToolTipBehaviour)1);
    CXTPCommandBars* bars = GetCommandBars();
    if (!bars) return 0;
    bars->GetImageManager()->SetIcons(0x91, xtpImageNormal);
    dockingPanes.SetAlphaDockingContext(TRUE);
    dockingPanes.SetShowDockingContextStickers(TRUE);
    bars->GetCommandBarsOptions()->ShowKeyboardCues((XTPKeyboardCuesShow)2);
    bars->GetToolTipContext()->SetStyle((XTPToolTipStyle)2);
    XTPImageManager()->InternalAddRef();
    bars->SetImageManager(XTPImageManager());
    XTPImageManager()->SetIcons(0x91, xtpImageNormal);
    state104 = true;
    showEditorChrome(true);
    InitializeAllIcons(XTPImageManager());
    updateMonitor();
    if (AfxGetApp()->GetProfileInt("Settings", "fullscreen", 0) == 1) setFullscreen(true);
    ::PostMessageA(m_hWnd, WM_COMMAND, 0x8101, 0);
    keepAlive.reset(new LoginRenewer());
    return 0;
}


