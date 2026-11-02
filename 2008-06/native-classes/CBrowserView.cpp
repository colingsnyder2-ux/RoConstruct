#include <afxwin.h>
#include <afxole.h>
#include <afxcmn.h>
#include <afxext.h>
#include <algorithm>
#include "CBrowserView.h"

void InitializeIcons(CXTPImageManager* manager);  // 0042f380, native icon initializer

IMPLEMENT_DYNCREATE(CBrowserView, CSecureHtmlView)

// Message map 0080d414 (entries 0080d420), base CHtmlView.
BEGIN_MESSAGE_MAP(CBrowserView, CSecureHtmlView)
    ON_WM_ERASEBKGND()
    ON_WM_SIZE()
    ON_WM_CREATE()
    ON_COMMAND(0x80bb, OnStop)
    ON_UPDATE_COMMAND_UI(0x80bb, OnUpdateStop)
    ON_COMMAND(0x80bd, OnHome)
    ON_UPDATE_COMMAND_UI(0x80bd, OnUpdateHome)
    ON_COMMAND(0x80bc, OnRefresh)
    ON_UPDATE_COMMAND_UI(0x80bc, OnUpdateAlways)
    ON_COMMAND(0x80ba, OnBack)
    ON_UPDATE_COMMAND_UI(0x80ba, OnUpdateBack)
    ON_COMMAND(0x80b9, OnForward)
    ON_UPDATE_COMMAND_UI(0x80b9, OnUpdateForward)
    ON_COMMAND(0x80ca, OnGo)
    ON_UPDATE_COMMAND_UI(0x80ca, OnUpdateGo)
    ON_XTP_EXECUTE(0x80c9, OnAddressExecute)
    ON_XTP_CREATECONTROL()
END_MESSAGE_MAP()

CBrowserView::CBrowserView() : addressBox(NULL), canGoBack(false), canGoForward(false)
{
    InitializeIcons(XTPImageManager());
}

CBrowserView::~CBrowserView()
{
}

void CBrowserView::OnNavigateComplete2(LPCTSTR url)
{
    CSecureHtmlView::OnNavigateComplete2(url);
    if (addressBox) {
        if (std::find(pages.begin(), pages.end(), std::string(url)) == pages.end()) {
            CString text(url);
            addressBox->SetEditText(text);
        }
    }
}

void CBrowserView::OnTitleChange(LPCTSTR title)
{
    CSecureHtmlView::OnTitleChange(title);
    CDocument* document = m_pDocument;
    if (document)
        document->SetTitle(title);
    else if (GetParentFrame())
        GetParentFrame()->SetWindowText(title);
}

void CBrowserView::OnDocumentComplete(LPCTSTR url)
{
    CSecureHtmlView::OnDocumentComplete(url);
}

void CBrowserView::OnCommandStateChange(long command, BOOL enable)
{
    CSecureHtmlView::OnCommandStateChange(command, enable);
    switch (command) {
    case CSC_UPDATECOMMANDS:
        ::InvalidateRect(toolBar.m_hWnd, NULL, TRUE);
        break;
    case CSC_NAVIGATEFORWARD:
        canGoForward = enable != 0;
        break;
    case CSC_NAVIGATEBACK:
        canGoBack = enable != 0;
        break;
    }
}

int CBrowserView::OnCreate(LPCREATESTRUCT create)
{
    if (CSecureHtmlView::OnCreate(create) == -1)
        return -1;
    toolBar.CreateToolBar(WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBRS_TOOLTIPS, this);
    toolBar.SetOwner(this);
    if (XTPPaintManager()) {
        XTPPaintManager()->InternalAddRef();
        toolBar.SetPaintManager(XTPPaintManager());
    }
    XTPImageManager()->InternalAddRef();
    toolBar.SetImageManager(XTPImageManager());
    toolBar.LoadToolBar(0x93, FALSE);
    return 0;
}

void CBrowserView::OnSize(UINT type, int cx, int cy)
{
    int top = 0;
    if (toolBar.GetSafeHwnd()) {
        CSize size;
        size = toolBar.CalcDockingLayout(cx, LM_STRETCH | LM_HORZ | LM_HORZDOCK | LM_COMMIT | LM_HIDEWRAP);
        top = size.cy;
        toolBar.MoveWindow(0, 0, cx, top);
        ::InvalidateRect(toolBar.m_hWnd, NULL, FALSE);
    }
    if (m_wndBrowser.GetSafeHwnd())
        m_wndBrowser.SetWindowPos(NULL, 0, top, cx, cy - top, SWP_NOZORDER | SWP_NOREDRAW | SWP_NOACTIVATE);
}

void CBrowserView::OnStop()
{
    m_pBrowserApp->Stop();
}

void CBrowserView::OnUpdateStop(CCmdUI* ui)
{
    VARIANT_BOOL busy;
    ui->Enable(m_pBrowserApp->get_Busy(&busy) == S_OK && busy == VARIANT_TRUE ? TRUE : FALSE);
}

void CBrowserView::OnHome()
{
    if (address != "")
        Navigate(address);
}

void CBrowserView::OnUpdateHome(CCmdUI* ui)
{
    ui->Enable(!address.IsEmpty());
}

void CBrowserView::OnRefresh()
{
    m_pBrowserApp->Refresh();
}

void CBrowserView::OnUpdateAlways(CCmdUI* ui)
{
    ui->Enable(TRUE);
}

void CBrowserView::OnBack()
{
    m_pBrowserApp->GoBack();
}

void CBrowserView::OnUpdateBack(CCmdUI* ui)
{
    ui->Enable(canGoBack);
}

void CBrowserView::OnForward()
{
    m_pBrowserApp->GoForward();
}

void CBrowserView::OnUpdateForward(CCmdUI* ui)
{
    ui->Enable(canGoForward);
}

void CBrowserView::OnGo()
{
    CString text = addressBox->GetEditText();
    if (addressBox->FindString(-1, text) == CB_ERR) {
        addressBox->InsertString(0, text);
        if (addressBox->GetCount() > 10)
            addressBox->DeleteItem(addressBox->GetCount() - 1);
    }
    Navigate(text);
    addressBox->GetEditCtrl()->SetSel(0, -1);
}

void CBrowserView::OnUpdateGo(CCmdUI* ui)
{
    ui->Enable(addressBox != NULL);
}

void CBrowserView::OnAddressExecute(NMHDR* header, LRESULT* result)
{
    if (((NMXTPCONTROL*)header)->pControl->GetType() == xtpControlComboBox) {
        OnGo();
        *result = 1;
    }
}

int CBrowserView::OnCreateControl(LPCREATECONTROLSTRUCT create)
{
    if (create->bToolBar) {
        CXTPToolBar* bar = DYNAMIC_DOWNCAST(CXTPToolBar, create->pCommandBar);
        if (bar && create->nID == 0x80c9) {
            if (!addressBox)
                addressBox = new CXTPControlComboBox();
            addressBox->SetDropDownListStyle(TRUE);
            addressBox->SetCaption("Address");
            addressBox->SetStyle(xtpComboLabel);
            addressBox->SetFlags(xtpFlagManualUpdate | xtpFlagControlStretched);
            addressBox->SetEnabled(TRUE);
            create->pControl = addressBox;
            return TRUE;
        }
    }
    return FALSE;
}

BOOL CBrowserView::OnEraseBkgnd(CDC*)
{
    return TRUE;
}

HRESULT CBrowserView::OnGetHostInfo(DOCHOSTUIINFO* info)
{
    HRESULT result = CSecureHtmlView::OnGetHostInfo(info);
    if (result == S_OK)
        info->dwFlags |= 0x1844016;
    return result;
}

// Original 004060d0 returns the application-owned base URL CString.
CString applicationBaseUrl();

IMPLEMENT_DYNCREATE(CIDEBrowserView, CBrowserView)

CIDEBrowserView::CIDEBrowserView()
{
    address = applicationBaseUrl() + "/IDE/Start.aspx";
}

IMPLEMENT_DYNCREATE(CPlayBrowserView, CBrowserView)

CPlayBrowserView::CPlayBrowserView()
{
    address = applicationBaseUrl() + "/Start.aspx";
}
