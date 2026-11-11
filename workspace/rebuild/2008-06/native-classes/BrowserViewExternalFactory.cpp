// >>> native-status (generated) -- do not edit >>>
// BrowserViewExternalFactory | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 1772334e | roc native-status --write
#include <afxwin.h>
#include "CBrowserViewExternal.h"

HRESULT __cdecl createBrowserViewExternal(ATL::CComObjectNoLock<CBrowserViewExternal>** result, int)
{
    HRESULT status = E_OUTOFMEMORY;
    ATL::CComObjectNoLock<CBrowserViewExternal>* object = NULL;
    try {
        object = new ATL::CComObjectNoLock<CBrowserViewExternal>;
    } catch (CException* exception) {
        exception->Delete();
    }
    if (object) {
        object->InternalAddRef();
        status = S_OK;
        object->InternalRelease();
    }
    *result = object;
    return status;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class ATL::CComPtrBase<ITypeInfo2>;
template class ATL::CComPtrBase<IUnknown>;
