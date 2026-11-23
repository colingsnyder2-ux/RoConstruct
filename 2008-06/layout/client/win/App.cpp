// =============================================================================
// App.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/App.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include <afx.h>
#include "CApp2008.h"
#include "CRobloxApp.h"
#include "ErrorUploaderState.h"
#include "v8datamodel/DebugSettings.h"

extern CRobloxApp theApp;

STDMETHODIMP CApp::LaunchIDE()
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    return static_cast<CRobloxApp*>(AfxGetApp())->initializeFramework(false) ? S_OK : E_FAIL;
}

STDMETHODIMP CApp::get_ErrorReporting(ERROR_REPORTING* value)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    *value = static_cast<ERROR_REPORTING>(RBX::DebugSettings::singleton().errorReporting);
    return S_OK;
}

STDMETHODIMP CApp::get_HasErrorFiles(VARIANT_BOOL* value)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    *value = theApp.logManager.hasCrashLogs() ? VARIANT_TRUE : VARIANT_FALSE;
    return S_OK;
}

STDMETHODIMP CApp::DeleteErrorFiles()
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    theApp.logManager.archiveCrashLogs();
    return S_OK;
}

STDMETHODIMP CApp::get_IsUploadingErrorFiles(VARIANT_BOOL* value)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    *value = theApp.errorUploader->IsUploading() ? VARIANT_TRUE : VARIANT_FALSE;
    return S_OK;
}

STDMETHODIMP CApp::get_Version(BSTR* value)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    CComBSTR version(static_cast<CRobloxApp*>(AfxGetApp())->version.c_str());
    return version.CopyTo(value);
}

void CApp::uploadErrorFiles(const char* url)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    theApp.errorUploader->Upload(url, false);
}

STDMETHODIMP CApp::SendErrorFiles(BSTR url)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    uploadErrorFiles(CString(url));
    return S_OK;
}

OBJECT_ENTRY_AUTO(CLSID_App, CApp)
