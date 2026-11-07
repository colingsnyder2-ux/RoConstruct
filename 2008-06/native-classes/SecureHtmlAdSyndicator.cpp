// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-import-length /I{headers}/std-noinline-string
// Body matches the original across its main and exception-handler fragments.
// >>> native-status (generated) -- do not edit >>>
// SecureHtmlAdSyndicator | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src ab564ca1 | roc native-status --write
#include <afxwin.h>
#include <atlutil.h>
#include "util/Http.h"
#include <G3D/format.h>

CString applicationBaseUrl();

bool isAdSyndicator(const char* address)
{
    ATL::CUrl parsed;
    parsed.CrackUrl(address);
    ATL::ATL_URL_SCHEME scheme = parsed.GetScheme();
    if (scheme != ATL::ATL_URL_SCHEME_FTP && (scheme <= ATL::ATL_URL_SCHEME_GOPHER || scheme > ATL::ATL_URL_SCHEME_HTTPS))
        return false;
    CString host(parsed.GetHostName());
    host.MakeLower();
    static std::string query = static_cast<LPCSTR>(applicationBaseUrl() + "/IDE/IsAdSyndicator.ashx?site=%s");
    RBX::Http request(G3D::format(query.c_str(), static_cast<LPCSTR>(host)).c_str());
    try {
        std::string result;
        request.get(result);
        return result == "true";
    } catch (...) {
        return false;
    }
}
