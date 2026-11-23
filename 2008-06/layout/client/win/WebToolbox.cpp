// =============================================================================
// WebToolbox.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/WebToolbox.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "CWebToolbox.h"

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
