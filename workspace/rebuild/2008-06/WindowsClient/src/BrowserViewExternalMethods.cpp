#include <afxwin.h>
#include "CBrowserViewExternal.h"

STDMETHODIMP CBrowserViewExternal::get_IsIDE(VARIANT_BOOL* result)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    *result = isIDE;
    return S_OK;
}
