#include "CMainFrame.h"

extern bool nativeLockA, nativeLockB, nativeLockC;

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& create)
{
    if (!CMDIFrameWnd::PreCreateWindow(create)) return FALSE;
    AfxGetModuleState();
    create.lpszClass = AfxRegisterWndClass(0, 0, 0, ::LoadIcon(AfxFindResourceHandle(MAKEINTRESOURCE(0x80), RT_GROUP_ICON), MAKEINTRESOURCE(0x80)));
    return TRUE;
}

void CMainFrame::OnSetPreviewMode(BOOL preview, CPrintPreviewState* state)
{
    GetCommandBars()->OnSetPreviewMode(preview);
    tabClient.ShowWorkspace(preview ? FALSE : !state104);
    dockingPanes.OnSetPreviewMode(preview);
    if (GetCommandBars()) GetCommandBars()->OnSetPreviewMode(preview);
    CMDIFrameWnd::OnSetPreviewMode(preview, state);
}

void CMainFrame::handle_430bd0()
{
    if (!nativeLockC) {
        state105 = true;
        hideEditorChrome();
    }
}

#include "CPatchedControlComboBox.h"
#include "CRobloxControlColorSelector.h"
#include "CWrapperView.h"
#include "COutputView.h"
#include "CRobloxReportView.h"
#include "CWebToolbox.h"
#include "CDataModelPropGrid.h"

// Report pane view (docking pane 0x8c): only its runtime class is used here.
class CRobloxReportPaneView : public CRobloxReportView { DECLARE_DYNCREATE(CRobloxReportPaneView) };

IMPLEMENT_DYNCREATE(CWrapperView, CView)

CWrapperView::CWrapperView()
{
}

void CWrapperView::OnDraw(CDC*)
{
}

BOOL CWrapperView::PreCreateWindow(CREATESTRUCT& cs)
{
    if (!CView::PreCreateWindow(cs))
        return FALSE;
    cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
    return TRUE;
}

// Commands the view does not handle go to the tree.
BOOL CWrapperView::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
    if (CView::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;
    return tree.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

// The tree fills the view: created on WM_CREATE, resized on WM_SIZE.
BOOL CWrapperView::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    BOOL handled = CView::OnWndMsg(message, wParam, lParam, pResult);
    if (handled && *pResult)
        return TRUE;
    switch (message) {
    case WM_CREATE: {
        CRect rect(0, 0, 100, 100);
        if (!tree.Create(WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, rect, this, 0)) {
            *pResult = -1;
            return TRUE;
        }
        tree.ModifyStyleEx(0, WS_EX_CLIENTEDGE, SWP_FRAMECHANGED);
        return TRUE;
    }
    case WM_SIZE:
        if (tree.m_hWnd)
            tree.MoveWindow(0, 0, LOWORD(lParam), HIWORD(lParam), TRUE);
        return TRUE;
    }
    return handled;
}

LRESULT CMainFrame::handle_4314e0(WPARAM wParam, LPARAM lParam)
{
    if (wParam == XTP_DPN_SHOWWINDOW) {
        CXTPDockingPane* pane = (CXTPDockingPane*)lParam;
        if (!pane->IsValid()) {
            switch (pane->GetID()) {
            case 0xc1:
                if (!splitter || !splitter->m_hWnd) {
                    splitter.reset(new CXTSplitterWnd);
                    if (!splitter->CreateStatic(this, 2, 1, WS_CHILD | WS_VISIBLE, AFX_IDW_PANE_FIRST))
                        return FALSE;
                    selectionCaption.reset(new CSelectionCaption);
                    if (!static_cast<CXTCaption*>(selectionCaption.get())->Create(splitter.get(), _T(""), 2, 0x10000201,
                                                  CRect(0, 0, 0, 0), splitter->IdFromRowCol(0, 0)))
                        return -1;
                    propertyGrid.reset(new CDataModelPropGrid);
                    propertyGrid->Create(CRect(0, 0, 0, 0), splitter.get(), splitter->IdFromRowCol(1, 0), 0);
                    propertyGrid->ShowToolBar(TRUE);
                    propertyGrid->SetTheme(xtpGridThemeWhidbey);
                    propertyGrid->ActiveDocView::refresh();
                    splitter->SetRowInfo(0, 28, 0);
                    splitter->SetSplitterStyle(XT_SPLIT_NOSIZE);
                }
                pane->Attach(splitter.get());
                return TRUE;
            case 0xc2: {
                CWnd* view = pane->AttachView(this, RUNTIME_CLASS(CWrapperView));
                if (view && ::IsWindow(view->m_hWnd)) view->SendMessage(WM_INITIALUPDATE);
                return TRUE;
            }
            case 0xc0: {
                CWnd* view = pane->AttachView(this, RUNTIME_CLASS(CStandardOutputView));
                if (view && ::IsWindow(view->m_hWnd)) view->SendMessage(WM_INITIALUPDATE);
                return TRUE;
            }
            case 0x8c: {
                CWnd* view = pane->AttachView(this, RUNTIME_CLASS(CRobloxReportPaneView));
                if (view && ::IsWindow(view->m_hWnd)) view->SendMessage(WM_INITIALUPDATE);
                return TRUE;
            }
            case 0xbf: {
                CWnd* view = pane->AttachView(this, RUNTIME_CLASS(CWebToolbox));
                if (view && ::IsWindow(view->m_hWnd)) view->SendMessage(WM_INITIALUPDATE);
                return TRUE;
            }
            }
        } else
            return TRUE;
    }
    return FALSE;
}

int CMainFrame::handle_42fcf0(void* p)
{
    LPCREATEBARSTRUCT lpCreatePopup = (LPCREATEBARSTRUCT)p;
    if (lpCreatePopup->bPopup && _tcscmp(lpCreatePopup->lpcstrCaption, _T("Camera Positioning")) == 0) {
        CXTPPopupBar* popup = CXTPPopupBar::CreatePopupBar(GetCommandBars());
        popup->SetTearOffPopup(lpCreatePopup->lpcstrCaption, 1001, 400);
        lpCreatePopup->pCommandBar = popup;
        return TRUE;
    }
    return FALSE;
}

int CMainFrame::handle_42fe00(void* p)
{
    LPCREATECONTROLSTRUCT lpCreateControl = (LPCREATECONTROLSTRUCT)p;
    if (lpCreateControl->bToolBar) {
        CXTPToolBar* toolBar = DYNAMIC_DOWNCAST(CXTPToolBar, lpCreateControl->pCommandBar);
        if (!toolBar)
            return FALSE;
        if (lpCreateControl->nID == 0xe12b) {
            lpCreateControl->controlType = xtpControlSplitButtonPopup;
            return TRUE;
        }
        if (lpCreateControl->nID == 0xe12c) {
            lpCreateControl->controlType = xtpControlSplitButtonPopup;
            return TRUE;
        }
        if (lpCreateControl->nID == 0x80db) {
            lpCreateControl->pControl = (CXTPControl*)CXTPControlButton::CreateObject();
            lpCreateControl->pControl->SetFlags(lpCreateControl->pControl->GetFlags() & ~xtpFlagManualUpdate);
            lpCreateControl->pControl->SetStyle(xtpButtonCaption);
            return TRUE;
        }
        if (lpCreateControl->nID == 0x80f6) {
            lpCreateControl->pControl = (CXTPControl*)CXTPControlButton::CreateObject();
            lpCreateControl->pControl->SetFlags(lpCreateControl->pControl->GetFlags() & ~xtpFlagManualUpdate);
            lpCreateControl->pControl->SetStyle(xtpButtonCaption);
            return TRUE;
        }
        if (lpCreateControl->nID == 0x80c3) {
            CXTPControlComboBox* combo = new CPatchedControlComboBox();
            combo->SetDropDownListStyle(TRUE);
            combo->SetCaption(_T("Command >"));
            combo->SetStyle(xtpButtonCaption);
            combo->SetFlags(xtpFlagControlStretched);
            lpCreateControl->pControl = combo;
            return TRUE;
        }
        if (lpCreateControl->nID == 0x8040) {
            CXTPControlPopupColor* popupColor = (CXTPControlPopupColor*)CXTPControlPopupColor::CreateObject();
            CXTPPopupBar* colorBar = CXTPPopupToolBar::CreatePopupToolBar(GetCommandBars());
            popupColor->SetCommandBar(colorBar);
            colorBar->GetControls()->Add(new CRobloxControlColorSelector(), 0x8d);
            colorBar->SetTearOffPopup(_T("Color"), 0x3ed, FALSE);
            colorBar->EnableCustomization(TRUE);
            colorBar->InternalRelease();
            lpCreateControl->pControl = popupColor;
            return TRUE;
        }
    }
    return FALSE;
}

void CMainFrame::handle_42fbf0()
{
    CXTPCommandBars* commandBars = GetCommandBars();
    if (commandBars) {
        CXTPCustomizeSheet sheet(commandBars);
        CXTPCustomizeOptionsPage options(&sheet);
        sheet.AddPage(&options);
        CXTPCustomizeCommandsPage* commands = sheet.GetCommandsPage();
        commands->AddCategories(0x81);           // IDR_MAINFRAME
        commands->InsertAllCommandsCategory();
        commands->InsertBuiltInMenus(0x81);
        commands->InsertNewMenuCategory();
        sheet.DoModal();
    }
}

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

#include "CRenderSettings.h"

void CMainFrame::OnGetMinMaxInfo(MINMAXINFO* info)
{
    Default();
    if (stateF8) { info->ptMaxPosition.x = 0; info->ptMaxPosition.y = 0; }
    if (!stateFA && !stateF8 && state104) {
        G3D::Vector2int16 size = CRenderSettings::singleton().getFullscreenSize();
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

#include "v8datamodel/BrickColor.h"
#include "v8datamodel/ToolsPart.h"
#include <G3D/Color3uint8.h>

IMPLEMENT_DYNAMIC(CMainFrame, CXTPMDIFrameWnd)

void CMainFrame::onEvent(const RBX::FillToolColor*, RBX::BrickColor color)
{
    G3D::Color3uint8 rgb(color.color3());
    unsigned long value = (((unsigned long)rgb.b << 8) | rgb.g) << 8;
    value |= rgb.r;
    CXTPControlPopupColor* popup = static_cast<CXTPControlPopupColor*>(
        GetCommandBars()->FindControl(xtpControlPopup, 0x8040, TRUE, TRUE));
    if (popup) popup->SetColor(value);
}

void CMainFrame::handle_4300d0(CCmdUI* ui)
{
    if (ui->m_pOther) {
        CXTPControls* controls = ((CXTPToolBar*)ui->m_pOther)->GetControls();
        int index = (int)ui->m_nIndex;
        CRobloxControlColorSelector* control = index >= 0 && index < controls->GetCount()
            ? (CRobloxControlColorSelector*)controls->GetAt(index) : NULL;
        G3D::Color3uint8 color(RBX::FillTool::color.get().color3());
        unsigned long value = (((unsigned long)color.b << 8) | color.g) << 8;
        value |= color.r;
        control->SetColor(value);
    }
    ui->Enable(TRUE);
}

template class CArray<CXTPControl *,CXTPControl *>;

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
