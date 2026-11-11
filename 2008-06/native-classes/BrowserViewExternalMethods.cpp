// >>> native-status (generated) -- do not edit >>>
// BrowserViewExternalMethods | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 23cd52ca | roc native-status --write
#include <afxwin.h>
#include "CBrowserViewExternal.h"

STDMETHODIMP CBrowserViewExternal::get_IsIDE(VARIANT_BOOL* result)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    *result = isIDE;
    return S_OK;
}
