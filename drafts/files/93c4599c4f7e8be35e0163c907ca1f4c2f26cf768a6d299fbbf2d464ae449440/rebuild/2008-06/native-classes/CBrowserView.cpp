// >>> native-status (generated) -- do not edit >>>
// CBrowserView | 2008-06 | 47 byte-exact, inactive (not link-selected)
// 47/48 mapped addresses byte-exact | named 3 | 1 unproved | no mapped strings | by auto (+4) (mixed 5)
// <<< native-status | src d39eb600 | roc native-status --write
#include "CBrowserView.h"
#include "CBrowserDoc.h"
#include "CBrowserViewExternal.h"
#include <SensAPI.h>

// Original 004060d0 returns the application-owned base URL CString.
CString applicationBaseUrl();
// Original 0042f380: loads the browser toolbar icons (ID_BROWSER_* commands) into an image manager.
void __cdecl loadBrowserIcons(CXTPImageManager* imageManager);
// Original 0056a160: true when the cracked URL is a roblox.com address.
bool __cdecl isRobloxUrl(const char* url);

IMPLEMENT_DYNCREATE(CBrowserView, CSecureHtmlView)
IMPLEMENT_DYNCREATE(CIDEBrowserView, CBrowserView)
IMPLEMENT_DYNCREATE(CPlayBrowserView, CBrowserView)

BEGIN_MESSAGE_MAP(CBrowserView, CHtmlView)
    ON_WM_ERASEBKGND()
    ON_WM_SIZE()
    ON_WM_CREATE()
    ON_COMMAND(ID_BROWSER_STOP, OnStop)
    ON_UPDATE_COMMAND_UI(ID_BROWSER_STOP, OnUpdateStop)
    ON_COMMAND(ID_BROWSER_HOME, OnHome)
    ON_UPDATE_COMMAND_UI(ID_BROWSER_HOME, OnUpdateHome)
    ON_COMMAND(ID_BROWSER_REFRESH, OnRefresh)
    ON_UPDATE_COMMAND_UI(ID_BROWSER_REFRESH, OnUpdateRefresh)
    ON_COMMAND(ID_BROWSER_BACK, OnBack)
    ON_UPDATE_COMMAND_UI(ID_BROWSER_BACK, OnUpdateBack)
    ON_COMMAND(ID_BROWSER_FORWARD, OnForward)
    ON_UPDATE_COMMAND_UI(ID_BROWSER_FORWARD, OnUpdateForward)
    ON_COMMAND(ID_BROWSER_GO, OnGo)
    ON_UPDATE_COMMAND_UI(ID_BROWSER_GO, OnUpdateGo)
    ON_XTP_EXECUTE(ID_BROWSER_ADDRESS, OnAddressExecute)
    ON_XTP_CREATECONTROL()
END_MESSAGE_MAP()

CBrowserView::CBrowserView()
    : addressCombo(NULL), canGoBack(false), canGoForward(false)
{
    loadBrowserIcons(XTPImageManager());
}

CBrowserView::~CBrowserView() {}

CIDEBrowserView::CIDEBrowserView()
{
    homeUrl = applicationBaseUrl() + "/IDE/Start.aspx";
}

CPlayBrowserView::CPlayBrowserView()
{
    homeUrl = applicationBaseUrl() + "/Start.aspx";
}

void CBrowserView::OnInitialUpdate()
{
    CSecureHtmlView::OnInitialUpdate();
    CBrowserDoc* document = (CBrowserDoc*)m_pDocument;
    if (document)
        document->view = this;
    if (homeUrl.Compare("") != 0)
        Navigate(homeUrl);
}

HRESULT CBrowserView::OnGetHostInfo(DOCHOSTUIINFO* info)
{
    HRESULT hr = CSecureHtmlView::OnGetHostInfo(info);
    if (hr == S_OK)
        info->dwFlags |= 0x1844016;
    return hr;
}

void CBrowserView::OnCommandStateChange(long command, BOOL enable)
{
    CSecureHtmlView::OnCommandStateChange(command, enable);
    switch (command) {
    case CSC_NAVIGATEBACK:
        canGoBack = enable != FALSE;
        break;
    case CSC_NAVIGATEFORWARD:
        canGoForward = enable != FALSE;
        break;
    case CSC_UPDATECOMMANDS:
        ::InvalidateRect(toolBar.m_hWnd, NULL, TRUE);
        break;
    }
}

void CBrowserView::OnDocumentComplete(LPCTSTR url)
{
    CSecureHtmlView::OnDocumentComplete(url);
}

void CBrowserView::OnTitleChange(LPCTSTR text)
{
    CSecureHtmlView::OnTitleChange(text);
    CDocument* document = GetDocument();
    if (document)
        document->SetTitle(text);
    else if (GetParentFrame())
        GetParentFrame()->SetWindowText(text);
}

BOOL CBrowserView::OnEraseBkgnd(CDC*)
{
    return TRUE;
}

void CBrowserView::OnSize(UINT, int cx, int cy)
{
    CSize size(0, 0);
    if (toolBar.GetSafeHwnd()) {
        size = toolBar.CalcDockingLayout(cx, LM_STRETCH | LM_HORZ | LM_HORZDOCK | LM_COMMIT | LM_HIDEWRAP);
        toolBar.MoveWindow(0, 0, cx, size.cy);
        ::InvalidateRect(toolBar.m_hWnd, NULL, FALSE);
    }
    if (m_wndBrowser.GetSafeHwnd())
        m_wndBrowser.SetWindowPos(NULL, 0, size.cy, cx, cy - size.cy, SWP_NOZORDER | SWP_NOREDRAW | SWP_NOACTIVATE);
}

int CBrowserView::OnCreate(LPCREATESTRUCT cs)
{
    if (CSecureHtmlView::OnCreate(cs) == -1)
        return -1;
    toolBar.CreateToolBar(WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBRS_TOOLTIPS, this, AFX_IDW_TOOLBAR);
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

void CBrowserView::OnStop()
{
    Stop();
}

void CBrowserView::OnUpdateStop(CCmdUI* ui)
{
    VARIANT_BOOL busy;
    ui->Enable(m_pBrowserApp->get_Busy(&busy) == S_OK && busy == VARIANT_TRUE);
}

void CBrowserView::OnHome()
{
    if (homeUrl.Compare("") != 0)
        Navigate(homeUrl);
}

void CBrowserView::OnUpdateHome(CCmdUI* ui)
{
    ui->Enable(!homeUrl.IsEmpty());
}

void CBrowserView::OnRefresh()
{
    Refresh();
}

void CBrowserView::OnUpdateRefresh(CCmdUI* ui)
{
    ui->Enable(TRUE);
}

void CBrowserView::OnBack()
{
    GoBack();
}

void CBrowserView::OnUpdateBack(CCmdUI* ui)
{
    ui->Enable(canGoBack);
}

void CBrowserView::OnForward()
{
    GoForward();
}

void CBrowserView::OnUpdateForward(CCmdUI* ui)
{
    ui->Enable(canGoForward);
}

void CBrowserView::OnGo()
{
    CString url = addressCombo->GetEditText();
    if (addressCombo->FindString(-1, url) == -1) {
        addressCombo->InsertString(0, url);
        if (addressCombo->GetCount() > 10)
            addressCombo->DeleteItem(addressCombo->GetCount() - 1);
    }
    Navigate(url);
    addressCombo->GetEditCtrl()->SetSel(0, -1);
}

void CBrowserView::OnUpdateGo(CCmdUI* ui)
{
    ui->Enable(addressCombo != NULL);
}

void CBrowserView::OnAddressExecute(NMHDR* nm, LRESULT* result)
{
    if (((NMXTPCONTROL*)nm)->pControl->GetType() == xtpControlComboBox) {
        OnGo();
        *result = 1;
    }
}

int CBrowserView::OnCreateControl(LPCREATECONTROLSTRUCT create)
{
    if (create->bToolBar) {
        CXTPToolBar* commandBar = DYNAMIC_DOWNCAST(CXTPToolBar, create->pCommandBar);
        if (!commandBar)
            return FALSE;
        if (create->nID != ID_BROWSER_ADDRESS)
            return FALSE;
        if (addressCombo == NULL)
            addressCombo = new CXTPControlComboBox();
        addressCombo->SetDropDownListStyle(TRUE);
        addressCombo->SetCaption("Address");
        addressCombo->SetStyle(xtpButtonCaption);
        addressCombo->SetFlags(xtpFlagManualUpdate | xtpFlagControlStretched);
        addressCombo->SetEnabled(TRUE);
        create->pControl = addressCombo;
        return TRUE;
    }
    return FALSE;
}

HRESULT CBrowserView::OnGetExternal(LPDISPATCH* dispatch)
{
    if (!external) {
        ATL::CComObjectNoLock<CBrowserViewExternal>* object;
        HRESULT hr = createBrowserViewExternal(&object, 0);
        if (hr != S_OK)
            return hr;
        VARIANT_BOOL isIDE = dynamic_cast<CIDEBrowserView*>(this) ? VARIANT_TRUE : VARIANT_FALSE;
        CBrowserViewExternal* created = object;
        created->isIDE = isIDE;
        external = created;
    }
    return external.CopyTo(dispatch);
}

void CBrowserView::OnNavigateComplete2(LPCTSTR url)
{
    CSecureHtmlView::OnNavigateComplete2(url);
    if (addressCombo) {
        bool unvisited = std::find(history.begin(), history.end(), std::string(url)) == history.end();
        if (unvisited) {
            CString text(url);
            addressCombo->SetEditText(text);
        }
    }
}

void CBrowserView::OnBeforeNavigate2(LPCTSTR url, DWORD flags, LPCTSTR targetFrameName,
                                     CByteArray& postedData, LPCTSTR headers, BOOL* cancel)
{
    DWORD network = 0;
    if (!IsNetworkAlive(&network) || network == 0) {
        char path[MAX_PATH];
        if (GetModuleFileName(AfxGetResourceHandle(), path, MAX_PATH)) {
            CString offline;
            offline.Format("res://%s/%d", path, 0xd7);
            if (offline.Compare(url) != 0) {
                Navigate(offline);
                *cancel = TRUE;
                return;
            }
        }
    }
    CSecureHtmlView::OnBeforeNavigate2(url, flags, targetFrameName, postedData, headers, cancel);
    if (*cancel) {
        Navigate(url, 0, "_blank");
        return;
    }
    CString unused(url);
    if (!isRobloxUrl(url)) {
        {
            std::string entry(url);
            history.push_back(entry);
        }
        if (history.size() > 50)
            history.erase(history.begin());
    }
}
