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
