// Inactive native 2008-06 recovery: the CBrowserViewExternal COM unit at the start of the application range
// 00410000..00414000 (tests/record_native_app_unit410.py, receipt app-unit410-working.json).
//
// The class comes from the committed native-headers/CBrowserViewExternal.h (read-only). Its two interface methods are
// declared there without bodies; they are defined here:
//   * get_IsIDE 00410f90 (IDispatchImpl vtable 0080d714 slot 7): AFX_MANAGE_STATE(AfxGetAppModuleState()) and a copy
//     of the VARIANT_BOOL at +0x1c;
//   * GetApp 00410fe0 (slot 8): CoCreateInstance(CLSID_App, NULL, CLSCTX_ALL, IID_IApp) and, on failure,
//     reportWorkspaceSiteError(CLSID_BrowserViewExternal, "IBrowserViewExternal::GetApp-0x%X", hr). The CLSID
//     pushed there (00816548) is {70EBD57E-...}, the BrowserViewExternal class of REGISTRY resource 119.
// The rest are ATL templates whose arguments name CBrowserViewExternal, so no other unit emits them:
// IConnectionPointContainerImpl::EnumConnectionPoints 004100a0, the IDispatchImpl members 00410260 / 004102c0 /
// 004102f0, IConnectionPointImpl::EnumConnections 004104b0 (+ its EH pieces), CComCreator<CComAggObject<...>>::
// CreateInstance 004103e0 (+ catch funclet 0041047b) and the CComCreator2 dispatcher 00410890 of the class's
// DECLARE_AGGREGATABLE creator; the CComEnum<IEnumConnectionPoints / IEnumConnections> Clone bodies 00410670 /
// 00410740 are the enumerators these create.
//
// Threading model: the original CComEnum RTTI (vtable 0080d790, 0x1c-byte object allocated in 004100a0) names
// CComSingleThreadModel as the default ThreadModel argument, i.e. CComObjectThreadModel is CComSingleThreadModel; the
// ATL default (CComMultiThreadModel) makes the enumerator 0x38 bytes. _ATL_APARTMENT_THREADED selects it (the ATL
// wizard default; a probe with _ATL_SINGLE_THREADED gave the same EnumConnectionPoints and enumerator rows, so the
// two are not distinguished by these bytes).
// Profile: document-swap flags, VS2008 RTM 21022, native-headers/mfc-noinline-pcxstr first (GetApp calls the imported
// CSimpleStringT::operator PCXSTR, as CBrowserView.cpp does).
#define _ATL_APARTMENT_THREADED
#include <afxwin.h>
#include "CBrowserViewExternal.h"
#include "AppUnit410/BrowserViewExternalApp.h"

STDMETHODIMP CBrowserViewExternal::get_IsIDE(VARIANT_BOOL* result)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    *result = isIDE;
    return S_OK;
}

STDMETHODIMP CBrowserViewExternal::GetApp(IDispatch** result)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    ATL::CComPtr<IDispatch> app;
    HRESULT hr = ::CoCreateInstance(CLSID_App, NULL, CLSCTX_ALL, IID_IApp, (void**)&app);
    if (hr != S_OK)
    {
        CString message;
        message.Format("IBrowserViewExternal::GetApp-0x%X", hr);
        return reportWorkspaceSiteError(CLSID_BrowserViewExternal, message, hr);
    }
    // 004110a2: a second reference (AddRef) is taken before CopyTo and released after it.
    ATL::CComPtr<IDispatch> dispatch(app);
    return dispatch.CopyTo(result);
}

template class ATL::IConnectionPointContainerImpl<CBrowserViewExternal>;
template class ATL::IConnectionPointImpl<CBrowserViewExternal, &__uuidof(_IBrowserViewExternalEvents),
                                         ATL::CComDynamicUnkArray>;
template class ATL::IDispatchImpl<IBrowserViewExternal, &IID_IBrowserViewExternal, &LIBID_RobloxLib, 1, 0>;
template class ATL::CComObjectNoLock<CBrowserViewExternal>;
template class ATL::CComObject<CBrowserViewExternal>;
template class ATL::CComAggObject<CBrowserViewExternal>;
template class ATL::CComContainedObject<CBrowserViewExternal>;
template HRESULT WINAPI ATL::CComCreator<ATL::CComObject<CBrowserViewExternal> >::CreateInstance(void*, REFIID, LPVOID*);
template HRESULT WINAPI ATL::CComCreator<ATL::CComAggObject<CBrowserViewExternal> >::CreateInstance(void*, REFIID,
                                                                                                  LPVOID*);
template HRESULT WINAPI ATL::CComCreator2<ATL::CComCreator<ATL::CComObject<CBrowserViewExternal> >,
                                          ATL::CComCreator<ATL::CComAggObject<CBrowserViewExternal> > >::CreateInstance(
    void*, REFIID, LPVOID*);

#ifdef NATIVE_APPUNIT410_PENDING
// Pending (needs DECLARE_PROTECT_FINAL_CONSTRUCT() in CBrowserViewExternal.h; header-owner proposal): the creator
// 0040fbf0 declared by the header. It allocates the 0x20-byte CComObjectNoLock, brackets FinalConstruct with
// m_dwRef++ / m_dwRef-- (0040fc64 / 0040fc69) and stores the object through the first argument; the second argument
// is unused. With the generated header copy the body is exact (174 B), and so is
// CComCreator<CComObject<CBrowserViewExternal>>::CreateInstance 0040f9a0 + catch funclet 0040fa39.
HRESULT __cdecl createBrowserViewExternal(ATL::CComObjectNoLock<CBrowserViewExternal>** result, int)
{
    HRESULT hr = E_OUTOFMEMORY;
    ATL::CComObjectNoLock<CBrowserViewExternal>* object = NULL;
    ATLTRY(object = new ATL::CComObjectNoLock<CBrowserViewExternal>())
    if (object != NULL)
    {
        object->SetVoid(NULL);
        object->InternalFinalConstructAddRef();
        hr = object->_AtlInitialConstruct();
        if (SUCCEEDED(hr))
            hr = object->FinalConstruct();
        if (SUCCEEDED(hr))
            hr = object->_AtlFinalConstruct();
        object->InternalFinalConstructRelease();
        if (hr != S_OK)
        {
            delete object;
            object = NULL;
        }
    }
    *result = object;
    return hr;
}
#endif
