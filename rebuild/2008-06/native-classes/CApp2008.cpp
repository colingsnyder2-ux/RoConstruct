// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /D_ATL_APARTMENT_THREADED /I{headers}/std-noinline-string /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// App COM registration and recovered methods, inactive pending ABI and provider proof.
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

OBJECT_ENTRY_AUTO(CLSID_App, CApp)
