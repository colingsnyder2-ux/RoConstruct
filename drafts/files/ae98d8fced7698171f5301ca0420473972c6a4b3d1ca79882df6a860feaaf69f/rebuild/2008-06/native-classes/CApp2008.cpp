// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /D_ATL_APARTMENT_THREADED /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// App COM registration and recovered methods, inactive pending ABI and provider proof.
#include <afx.h>
#include "CApp2008.h"
#include "CRobloxApp.h"

STDMETHODIMP CApp::LaunchIDE()
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    return static_cast<CRobloxApp*>(AfxGetApp())->initializeFramework(false) ? S_OK : E_FAIL;
}

OBJECT_ENTRY_AUTO(CLSID_App, CApp)
