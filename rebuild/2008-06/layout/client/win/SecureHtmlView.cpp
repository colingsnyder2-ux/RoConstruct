// =============================================================================
// SecureHtmlView.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/SecureHtmlView.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "CSecureHtmlView.h"
#include <mshtmdid.h>

HRESULT __cdecl checkDialogUrl(const char* url);
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
