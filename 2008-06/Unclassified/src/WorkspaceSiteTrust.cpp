// >>> native-status (generated) -- do not edit >>>
// WorkspaceSiteTrust | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 37260412 | roc native-status --write
#include <afxwin.h>
#include "util/Http.h"
#include <urlmon.h>

HRESULT validateWorkspaceSiteUrl(const wchar_t* url)
{
    return RBX::Http::trustCheck(CString(url)) ? S_OK : E_FAIL;
}

HRESULT validateWorkspaceSiteZone(const wchar_t* url, DWORD zone)
{
    if (zone == URLZONE_UNTRUSTED) return E_FAIL;
    return validateWorkspaceSiteUrl(url);
}
