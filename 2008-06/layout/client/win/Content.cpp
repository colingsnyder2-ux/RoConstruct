// =============================================================================
// Content.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/Content.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include <afxwin.h>
#include "CContent.h"
#include "LogManager.h"
#include "util/Http.h"

typedef char HttpSizeCheck[sizeof(RBX::Http) == 0x38 ? 1 : -1];

extern HRESULT validateWorkspaceSiteUrl(const wchar_t*);

HRESULT __stdcall CContent::Upload(BSTR url) {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    if (HRESULT hr = validateWorkspaceSiteUrl(url)) {
        CStringA msg;
        msg.Format("Untrusted Url: %s", CStringA(url));
        return LogManager::ReportCOMError(CLSID_Content, msg, hr);
    }
    try {
        std::string error;
        RBX::Http(CStringA(url)).post(stream, true, error);
    } catch (std::exception& e) {
        return LogManager::ReportExceptionAsCOMError(CLSID_Content, e);
    }
    return S_OK;
}
