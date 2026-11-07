// >>> native-status (generated) -- do not edit >>>
// CWorkspaceSiteCheck | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 2356ca3c | roc native-status --write
#include <afxwin.h>
#include "CWorkspace.h"

HRESULT validateWorkspaceSiteZone(const wchar_t*, DWORD);
HRESULT reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);
extern const CLSID workspaceSiteErrorContext;

template<class T, DWORD Supported>
HRESULT IObjectSafetyRobloxImpl<T, Supported>::checkSite()
{
    T* owner = static_cast<T*>(this);
    ATL::CComPtr<IUnknown> site;
    if (owner->GetSite(IID_IUnknown, reinterpret_cast<void**>(&site)) == S_OK && site) {
        ATL::CComBSTR url;
        DWORD zone;
        HRESULT result = owner->getSiteUrl(url, zone);
        if (result) return reportWorkspaceSiteError(workspaceSiteErrorContext, "Failed to get SiteUrl", result);
        result = validateWorkspaceSiteZone(url, zone);
        if (result) {
            CString message;
            { message.Format("Untrusted Site: %s", CString(url)); }
            const char* (CString::*convert)() const = &CString::operator const char*;
            return reportWorkspaceSiteError(workspaceSiteErrorContext, (message.*convert)(), result);
        }
    }
    return S_OK;
}

template HRESULT IObjectSafetyRobloxImpl<CWorkspace, 1>::checkSite();
