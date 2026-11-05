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
