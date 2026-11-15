// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// >>> native-status (generated) -- do not edit >>>
// CWebToolbox | 2008-06 | 10 byte-exact, inactive (not link-selected)
// 10/10 mapped addresses byte-exact | 0 unproved | no mapped strings | by king_originala (+3) (mixed 2)
// <<< native-status | src f110b756 | roc native-status --write
#include "CWebToolbox.h"

// Original 004060d0 returns the application-owned base URL CString.
CString applicationBaseUrl();

IMPLEMENT_DYNCREATE(CWebToolbox, CSecureHtmlView)

BEGIN_MESSAGE_MAP(CWebToolbox, CHtmlView)
    ON_WM_GETMINMAXINFO()
    ON_WM_SETFOCUS()
    ON_WM_MOUSEACTIVATE()
    ON_WM_LBUTTONUP()
    ON_WM_ACTIVATE()
END_MESSAGE_MAP()

CWebToolbox::CWebToolbox() {}

CWebToolbox::~CWebToolbox() {}

void CWebToolbox::OnInitialUpdate()
{
    CSecureHtmlView::OnInitialUpdate();
    CString url = applicationBaseUrl() + "/IDE/ClientToolbox.aspx";
    Navigate(url);
}

void CWebToolbox::OnActivateView(BOOL activate, CView* activateView, CView* deactiveView)
{
    CSecureHtmlView::OnActivateView(activate, activateView, deactiveView);
    if (owner)
        owner->SetFocus();
}

HRESULT CWebToolbox::OnGetExternal(LPDISPATCH* dispatch)
{
    if (owner)
        owner->SetFocus();
    CComPtr<IDispatch> result = external;
    return result.CopyTo(dispatch);
}

HRESULT CWebToolbox::OnGetHostInfo(DOCHOSTUIINFO* info)
{
    HRESULT hr = CSecureHtmlView::OnGetHostInfo(info);
    if (hr == S_OK)
        info->dwFlags |= 0x1844017;
    return hr;
}

HRESULT CWebToolbox::OnDocWindowActivate(BOOL)
{
    if (owner)
        owner->SetFocus();
    return CSecureHtmlView::OnDocWindowActivate(FALSE);
}

HRESULT CWebToolbox::OnFrameWindowActivate(BOOL)
{
    if (owner)
        owner->SetFocus();
    return CSecureHtmlView::OnFrameWindowActivate(FALSE);
}

void CWebToolbox::OnGetMinMaxInfo(MINMAXINFO* info)
{
    CSecureHtmlView::OnGetMinMaxInfo(info);
    info->ptMaxSize.y = 50;
}

void CWebToolbox::OnSetFocus(CWnd* oldWnd)
{
    CSecureHtmlView::OnSetFocus(oldWnd);
    if (owner)
        owner->SetFocus();
}

int CWebToolbox::OnMouseActivate(CWnd*, UINT, UINT)
{
    if (owner)
        owner->SetFocus();
    return MA_NOACTIVATE;
}

void CWebToolbox::OnLButtonUp(UINT flags, CPoint point)
{
    CSecureHtmlView::OnLButtonUp(flags, point);
    if (owner)
        owner->SetFocus();
}

void CWebToolbox::OnActivate(UINT state, CWnd* other, BOOL minimized)
{
    CSecureHtmlView::OnActivate(state, other, minimized);
    if (owner)
        owner->SetFocus();
}
