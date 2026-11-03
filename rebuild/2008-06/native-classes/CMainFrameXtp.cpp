// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#include "CMainFrame.h"
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

// XTPWM_DOCKINGPANE_NOTIFY (0x2aad, 004314e0): create pane contents the first time they are shown.
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

// WM_XTP_CREATECOMMANDBAR (0x2861, 0042fcf0): the "Camera Positioning" popup becomes a tear-off bar.
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

// WM_XTP_CREATECONTROL (0x285e, 0042fe00): Roblox's custom toolbar controls.
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

// XTP customization command (ON_COMMAND 0x88b9, 0042fbf0): the toolkit's stock customize sheet.
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
