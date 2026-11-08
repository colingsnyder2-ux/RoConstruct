#include "CWorkspace.h"
#include <servprov.h>
#include <exdisp.h>
#include <shlguid.h>
#include <urlmon.h>

template<class T, DWORD Supported>
HRESULT IObjectSafetyRobloxImpl<T, Supported>::getSiteUrl(ATL::CComBSTR& url, DWORD& zone)
{
    ATL::CComPtr<IServiceProvider> provider;
    T* owner = static_cast<T*>(this);
    HRESULT result = owner->GetSite(IID_IServiceProvider, reinterpret_cast<void**>(&provider));
    if (FAILED(result)) return result;
    ATL::CComPtr<IWebBrowser2> browser;
    result = provider->QueryService(SID_SWebBrowserApp, IID_IWebBrowser2, reinterpret_cast<void**>(&browser));
    if (FAILED(result)) return result;
    if (FAILED(browser->get_LocationURL(&url))) return result;
    ATL::CComPtr<IInternetSecurityManager> security;
    result = provider->QueryService(SID_SInternetSecurityManager, IID_IInternetSecurityManager, reinterpret_cast<void**>(&security));
    if (FAILED(result)) return result;
    result = security->MapUrlToZone(url, &zone, 0);
    if (FAILED(result)) return result;
    return S_OK;
}

template HRESULT IObjectSafetyRobloxImpl<CWorkspace, 1>::getSiteUrl(ATL::CComBSTR&, DWORD&);
