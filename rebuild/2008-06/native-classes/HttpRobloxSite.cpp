// >>> native-status (generated) -- do not edit >>>
// HttpRobloxSite | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (deepseek:deepseek-chat)
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
