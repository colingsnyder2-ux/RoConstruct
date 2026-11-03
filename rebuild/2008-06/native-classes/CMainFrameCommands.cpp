// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// (OnClose 00431f10 needs CString::operator PCXSTR out of line; hideEditorChrome 004309f0, showEditorChrome 00430f50)
#include "CMainFrame.h"
#include "util/standardout.h"
#include "util/boost.hpp"
#include <G3D/Vector2int16.h>

void CMainFrame::showDockPane(int id, CRect bounds, XTPDockingPaneDirection direction)
{
    CXTPDockingPane* pane = dockingPanes.FindPane(id);
    if (!pane) pane = dockingPanes.CreatePane(id, bounds, direction, NULL);
    dockingPanes.ShowPane(pane, TRUE);
    pane->SetFocus();
}

void CMainFrame::handle_42e550(CCmdUI* ui) { ui->Enable(TRUE); }
void CMainFrame::handle_42eec0(CCmdUI* ui) { ui->SetCheck(state104); }
void CMainFrame::handle_42eef0(CCmdUI* ui) { ui->SetCheck(stateF8); }
void CMainFrame::handle_42e5e0() { showDockPane(0xc2, CRect(0, 0, 250, 300), (XTPDockingPaneDirection)1); }
void CMainFrame::handle_42fb80() { showDockPane(0xbf, CRect(0, 0, 280, 400), (XTPDockingPaneDirection)0); }
void CMainFrame::handle_42fbb0() { showDockPane(0xc0, CRect(0, 0, 640, 200), (XTPDockingPaneDirection)3); }

void CMainFrame::handle_42ee90() { showDockPane(0x8c, CRect(0, 0, 150, 400), (XTPDockingPaneDirection)0); }
void CMainFrame::handle_42ed00(CCmdUI* ui) { ui->SetText(""); }
void CMainFrame::handle_4314c0() { if (state104) showEditorChrome(0); else hideEditorChrome(); }
void CMainFrame::handle_431ce0() { setFullscreen(!stateF8); }
void CMainFrame::handle_42e610()
{
    bool missing = dockingPanes.FindPane(0xc1) == NULL;
    showDockPane(0xc1, CRect(0, 0, 250, 300), (XTPDockingPaneDirection)1);
    if (missing) {
        CXTPDockingPane* relative = dockingPanes.FindPane(0xc2);
        if (relative) {
            CXTPDockingPaneBase* base = relative;
            CXTPDockingPane* pane = dockingPanes.FindPane(0xc1);
            dockingPanes.DockPane(pane, (XTPDockingPaneDirection)3, base);
        }
    }
}

void CMainFrame::setFullscreen(bool value)
{
    RECT rect;
    if (stateF8 != value) {
        stateF8 = value;
        if (value) {
            ::GetWindowRect(m_hWnd, &windowPosition.rcNormalPosition);
            ::CopyRect(&rect, &windowPosition.rcNormalPosition);
            configureFullscreen();
        } else {
            restoreFullscreen();
            ::CopyRect(&rect, &windowPosition.rcNormalPosition);
            if (!::IsRectEmpty(&rect))
                SetWindowPos(NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0x260);
        }
        RecalcLayout(TRUE);
    }
}

namespace {
struct ResolutionGuard {
    bool* value; bool old;
    ResolutionGuard(bool& target) : value(&target), old(target) { target = true; }
    ~ResolutionGuard() { *value = old; }
};
}
void CMainFrame::restoreFullscreen()
{
    ResolutionGuard guard(stateFA);
    if (!monitor) {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "CMainFrame::RestoreResolution hm is NULL");
        return;
    }
    MONITORINFOEXA info;
    info.cbSize = sizeof(info);
    if (::GetMonitorInfoA(monitor, &info)) {
        ShowWindow(0);
        LONG result = ::ChangeDisplaySettingsExA(info.szDevice, NULL, NULL, 0, NULL);
        if (result) RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "CMainFrame::RestoreResolution ChangeDisplaySettings == %d", result);
    }
    ModifyStyle(0, WS_CAPTION | WS_THICKFRAME, 0);
}

void CMainFrame::OnActivate(UINT state, CWnd* other, BOOL minimized)
{
    CFrameWnd::OnActivate(state, other, minimized);
    if (stateF8 && !stateFA && state) { configureFullscreen(); ShowWindow(SW_RESTORE); }
}
void CMainFrame::OnActivateApp(BOOL active, DWORD)
{
    Default();
    if (stateF8 && !stateFA && !active) { restoreFullscreen(); ShowWindow(SW_SHOWMINNOACTIVE); }
}
void CMainFrame::OnWindowPosChanging(WINDOWPOS* position)
{
    Default();
    if (stateF8 && !stateFA) position->flags |= SWP_NOSIZE | SWP_NOMOVE;
}

// Original 00412d50 and 00445250; class identity remains unverified.
class FrameSizeSettings { public: G3D::Vector2int16 getFrameSize() const; };
FrameSizeSettings* frameSizeSettings();
void CMainFrame::OnGetMinMaxInfo(MINMAXINFO* info)
{
    Default();
    if (stateF8) { info->ptMaxPosition.x = 0; info->ptMaxPosition.y = 0; }
    if (!stateFA && !stateF8 && state104) {
        G3D::Vector2int16 size = frameSizeSettings()->getFrameSize();
        RECT rect = {0, 0, size.x, size.y};
        CalcWindowRect(&rect, 0);
        info->ptMaxSize.x = info->ptMaxTrackSize.x = rect.right - rect.left;
        info->ptMaxSize.y = info->ptMaxTrackSize.y = rect.bottom - rect.top;
    }
}

void CMainFrame::OnDestroy()
{
    int fullscreen = stateF8 || stateF9 ? 1 : 0;
    AfxGetApp()->WriteProfileInt("Settings", "fullscreen", fullscreen);
    if (stateF8) restoreFullscreen();
    else windowPosition.SaveWindowPos(this, "CMainFrameV2", NULL);
    if (state104) initializeToolbars(false);
    CMDIFrameWnd::OnDestroy();
    tabClient.Detach();
}

void CMainFrame::hideEditorChrome()
{
    if (!state104) {
        CXTPPropExchangeXMLNode exchange(FALSE, NULL, "IDE");
        if (exchange.OnBeforeExchange()) {
            exchangeLayout(&exchange, TRUE);
            exchange.SaveToFile(static_cast<LPCTSTR>(text), TRUE);
        }
        status.ShowWindow(SW_HIDE);
        tabClient.ShowWorkspace(FALSE);
        GetCommandBars()->RemoveAll();
        dockingPanes.DestroyAll();
        RecalcLayout(TRUE);
        state104 = true;
    }
}



void CMainFrame::exchangeLayout(CXTPPropExchange* px, int mode)
{
    CXTPCommandBars* bars = GetCommandBars();
    XTP_COMMANDBARS_PROPEXCHANGE_PARAM options;
    options.bSerializeControls = mode;
    options.bLoadSilent = TRUE;
    CXTPPropExchangeSection commandBars(px->GetSection("CommandBars"));
    bars->DoPropExchange(&commandBars, &options);
    CXTPPropExchangeSection shortcuts(px->GetSection("Shortcuts"));
    bars->GetShortcutManager()->DoPropExchange(&shortcuts);
    CXTPPropExchangeSection settings(px->GetSection("Options"));
    bars->GetCommandBarsOptions()->DoPropExchange(&settings, TRUE);
    CXTPPropExchangeSection docking(px->GetSection("DockingPane"));
    dockingPanes.DoPropExchange(&docking);
}

void CMainFrame::showEditorChrome(bool loadIcons)
{
    if (state104 && !state105) {
        status.ShowWindow(SW_SHOW);
        initializeToolbars(loadIcons);
        tabClient.ShowWorkspace(TRUE);
        CXTPPropExchangeXMLNode exchange(TRUE, NULL, "IDE");
        if (exchange.LoadFromFile(static_cast<LPCTSTR>(text))) exchangeLayout(&exchange, TRUE);
        else { handle_42e5e0(); handle_42e610(); }
        state104 = false;
    }
}

void CMainFrame::OnClose()
{
    keepAlive.reset();
    if (stateF8) { setFullscreen(false); stateF9 = true; }
    else stateF9 = false;
    if (!state104) {
        CXTPPropExchangeXMLNode exchange(FALSE, NULL, "IDE");
        if (exchange.OnBeforeExchange()) {
            exchangeLayout(&exchange, TRUE);
            exchange.SaveToFile(static_cast<LPCTSTR>(text), TRUE);
        }
    }
    CFrameWnd::OnClose();
}

void CMainFrame::updateMonitor()
{
    monitor = ::MonitorFromWindow(m_hWnd, MONITOR_DEFAULTTONEAREST);
    if (!monitor) RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING, "CMainFrameFrameWnd::getMonitorInfo MonitorFromWindow returned NULL");
}
