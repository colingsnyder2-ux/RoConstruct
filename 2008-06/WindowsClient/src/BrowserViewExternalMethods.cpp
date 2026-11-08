// >>> native-status (generated) -- do not edit >>>
// BrowserViewExternalMethods | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 23cd52ca | roc native-status --write
#include <afxwin.h>
#include "CBrowserViewExternal.h"

STDMETHODIMP CBrowserViewExternal::get_IsIDE(VARIANT_BOOL* result)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    *result = isIDE;
    return S_OK;
}
