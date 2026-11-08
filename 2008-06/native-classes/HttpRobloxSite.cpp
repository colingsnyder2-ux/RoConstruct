// >>> native-status (generated) -- do not edit >>>
// HttpRobloxSite | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 4b7cee21 | roc native-status --write
#include <shlwapi.h>
#include <atlutil.h>
#include <atlstr.h>
#include "util/Http.h"

bool RBX::Http::isRobloxSite(const char* url)
{
    ATL::CUrl parsed;
    parsed.CrackUrl(url);
    ATL::ATL_URL_SCHEME scheme = parsed.GetScheme();
    if (scheme != ATL::ATL_URL_SCHEME_FTP && (scheme <= ATL::ATL_URL_SCHEME_GOPHER || scheme > ATL::ATL_URL_SCHEME_HTTPS))
        return false;
    ATL::CString host(parsed.GetHostName());
    host.MakeLower();
    if (host.Right(10) == "roblox.com")
        return true;
    return false;
}
