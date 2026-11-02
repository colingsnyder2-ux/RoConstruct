#include "CSecureHtmlView.h"
#include <mshtmdid.h>

// Original 0041dcb0 (defined with CRobloxDHtmlDialog): S_OK when Http::trustCheck accepts the URL.
HRESULT __cdecl checkDialogUrl(const char* url);
// Original 00465b50: cracks the URL with ATL::CUrl and compares it against the application base URL.
bool __cdecl isApplicationUrl(const char* url);

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
    if (strlen(targetFrameName) == 0 && checkDialogUrl(url) != S_OK && !isApplicationUrl(url))
        *cancel = TRUE;
}
