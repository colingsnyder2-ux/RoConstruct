// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// CContentUpload | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 895b3355 | roc native-status --write
#include <afxwin.h>
#include "CContent.h"
#include "util/Http.h"

typedef char HttpSizeCheck[sizeof(RBX::Http) == 0x38 ? 1 : -1];

extern HRESULT validateWorkspaceSiteUrl(const wchar_t*);
extern HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);
extern HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const std::exception&);

HRESULT __stdcall CContent::Upload(BSTR url) {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    if (HRESULT hr = validateWorkspaceSiteUrl(url)) {
        CStringA msg;
        msg.Format("Untrusted Url: %s", CStringA(url));
        return reportWorkspaceSiteError(CLSID_Content, msg, hr);
    }
    try {
        std::string error;
        RBX::Http(CStringA(url)).post(stream, true, error);
    } catch (std::exception& e) {
        return reportWorkspaceSiteError(CLSID_Content, e);
    }
    return S_OK;
}
