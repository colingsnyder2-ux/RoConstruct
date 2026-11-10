#include <afxwin.h>
#include "CBrowserViewExternal.h"

// Original 00410f90 (IBrowserViewExternal::get_IsIDE): AFX module state guard, copy of the VARIANT_BOOL at +0x1c.
STDMETHODIMP CBrowserViewExternal::get_IsIDE(VARIANT_BOOL* result)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    *result = isIDE;
    return S_OK;
}

// Original 0040fbf0: the genuine ATL9 CComObject<Base>::CreateInstance construction sequence (atlcom.h) for
// CComObjectNoLock<CBrowserViewExternal>, as a free cdecl function. Codegen analog; the name and unused argument are not proven.
HRESULT __cdecl createBrowserViewExternal(ATL::CComObjectNoLock<CBrowserViewExternal>** result, int /*unused*/)
{
    typedef ATL::CComObjectNoLock<CBrowserViewExternal> Object;
    HRESULT hr = E_OUTOFMEMORY;
    Object* object = NULL;
    ATLTRY(object = new Object())
    if (object != NULL) {
        object->SetVoid(NULL);
        object->InternalFinalConstructAddRef();
        hr = object->_AtlInitialConstruct();
        if (SUCCEEDED(hr))
            hr = object->FinalConstruct();
        if (SUCCEEDED(hr))
            hr = object->_AtlFinalConstruct();
        object->InternalFinalConstructRelease();
        if (hr != S_OK) {
            delete object;
            object = NULL;
        }
    }
    *result = object;
    return hr;
}

// CoCreateInstance arguments of GetApp; neutral analog names.
static const CLSID applicationClassGuid = {0xeec6b245, 0x01be, 0x4a51, {0x92, 0xba, 0x2a, 0xfd, 0xaf, 0x97, 0x58, 0x1b}};
static const IID applicationInterfaceGuid = {0x54f58168, 0x734e, 0x4379, {0xb1, 0x98, 0x64, 0xb0, 0x82, 0x6a, 0x00, 0x2e}};

// Original 00429330 (native-classes/WorkspaceSiteError.cpp).
extern HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);

// Original 00410fe0.
STDMETHODIMP CBrowserViewExternal::GetApp(IDispatch** result)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    ATL::CComPtr<IDispatch> application;
    HRESULT hr = ::CoCreateInstance(applicationClassGuid, NULL, CLSCTX_ALL, applicationInterfaceGuid, reinterpret_cast<void**>(&application));
    if (hr != S_OK) {
        CString message;
        message.Format("IBrowserViewExternal::GetApp-0x%X", hr);
        return reportWorkspaceSiteError(CLSID_BrowserViewExternal, message, hr);
    }
    return ATL::CComPtr<IDispatch>(application).CopyTo(result);
}
