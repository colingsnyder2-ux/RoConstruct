// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
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

