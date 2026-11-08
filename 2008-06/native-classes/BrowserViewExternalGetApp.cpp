// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// >>> native-status (generated) -- do not edit >>>
// BrowserViewExternalGetApp | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src a2011b9b | roc native-status --write
#include <afxwin.h>
#include "CBrowserViewExternal.h"

extern HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);
extern const CLSID browserAppClass = {0xeec6b245, 0x01be, 0x4a51, {0x92, 0xba, 0x2a, 0xfd, 0xaf, 0x97, 0x58, 0x1b}};
extern const IID browserAppInterface = {0x54f58168, 0x734e, 0x4379, {0xb1, 0x98, 0x64, 0xb0, 0x82, 0x6a, 0x00, 0x2e}};
extern const CLSID browserExternalErrorContext = {0x70ebd57e, 0xfd0d, 0x4032, {0xb0, 0x90, 0x92, 0x44, 0xaa, 0x7d, 0xed, 0x6e}};

STDMETHODIMP CBrowserViewExternal::GetApp(IDispatch** result)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    CComPtr<IDispatch> app;
    HRESULT hr = CoCreateInstance(browserAppClass, NULL, CLSCTX_ALL, browserAppInterface, reinterpret_cast<void**>(&app));
    if (hr != S_OK) {
        CString message;
        message.Format("IBrowserViewExternal::GetApp-0x%X", hr);
        return reportWorkspaceSiteError(browserExternalErrorContext, static_cast<LPCSTR>(message), hr);
    }
    CComPtr<IDispatch> copy(app);
    return copy.CopyTo(result);
}
