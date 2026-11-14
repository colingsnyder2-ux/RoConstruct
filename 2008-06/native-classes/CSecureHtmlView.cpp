// >>> native-status (generated) -- do not edit >>>
// CSecureHtmlView | 2008-06 | 4 byte-exact, inactive (not link-selected)
// 4/6 mapped addresses byte-exact | 2 unproved | no mapped strings | by king_originala (+2) (mixed 2)
// <<< native-status | src d99ee39f | roc native-status --write
#include "CSecureHtmlView.h"
#include <mshtmdid.h>

// Original 0041dcb0 (defined with CRobloxDHtmlDialog): S_OK when Http::trustCheck accepts the URL.
HRESULT __cdecl checkDialogUrl(const char* url);
// Original 00465b50: queries whether the URL host is an ad syndicator.
bool __cdecl isAdSyndicator(const char* url);

IMPLEMENT_DYNAMIC(CSecureHtmlView, CHtmlView)

CSecureHtmlView::CSecureHtmlView()
{
    flag_f4 = false;
}

CSecureHtmlView::~CSecureHtmlView() {}

BOOL CSecureHtmlView::OnAmbientProperty(COleControlSite* site, DISPID dispid, VARIANT* var)
{
    if (dispid != DISPID_AMBIENT_DLCONTROL)
        return CHtmlView::OnAmbientProperty(site, dispid, var);
    if (flag_f4) {
        var->vt = VT_I4;
        var->lVal = DLCTL_DLIMAGES | DLCTL_VIDEOS | DLCTL_NO_JAVA | DLCTL_NO_RUNACTIVEXCTLS
                  | DLCTL_NO_DLACTIVEXCTLS | DLCTL_NO_FRAMEDOWNLOAD;
        return TRUE;
    }
    return CHtmlView::OnAmbientProperty(site, dispid, var);
}

BOOL CSecureHtmlView::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS, ::LoadCursor(NULL, IDC_ARROW), NULL, NULL);
    cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
    return CHtmlView::PreCreateWindow(cs);
}

void CSecureHtmlView::OnBeforeNavigate2(LPCTSTR url, DWORD flags, LPCTSTR targetFrameName,
                                        CByteArray& postedData, LPCTSTR headers, BOOL* cancel)
{
    CHtmlView::OnBeforeNavigate2(url, flags, targetFrameName, postedData, headers, cancel);
    if (strlen(targetFrameName) == 0 && checkDialogUrl(url) != S_OK && !isAdSyndicator(url))
        *cancel = TRUE;
}
