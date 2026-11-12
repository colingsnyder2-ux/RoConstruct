// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Http::isScript (004a6040) - native 2008-06.
// >>> native-status (generated) -- do not edit >>>
// HttpScriptCheck | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | 2 referenced strings (not rechecked) | by colin
// <<< native-status | src 68721f11 | roc native-status --write
#include <shlwapi.h>
#include <atlutil.h>
#include <atlstr.h>
#include "util/Http.h"

bool RBX::Http::isScript(const char* url)
{
    ATL::CUrl parsed;
    parsed.CrackUrl(url);
    ATL::ATL_URL_SCHEME scheme = parsed.GetScheme();
    if (scheme == ATL::ATL_URL_SCHEME_FTP || (scheme > ATL::ATL_URL_SCHEME_GOPHER && scheme <= ATL::ATL_URL_SCHEME_HTTPS))
        return false;
    ATL::CString text(url);
    if (text.Find("javascript:") == 0)
        return true;
    if (text.Find("jscript:") == 0)
        return true;
    return false;
}
