// >>> native-status (generated) -- do not edit >>>
// HttpTrustInitialize | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 0310874d | roc native-status --write
#include <windows.h>
#include <atlbase.h>

namespace RBX {
extern bool skipTrustCheck;

void initializeTrustCheck()
{
    DWORD value = 0;
    ATL::CRegKey key;
    if (key.Open(HKEY_CURRENT_USER, "Software\\ROBLOX Corporation\\Roblox", KEY_READ) == ERROR_SUCCESS)
        key.QueryDWORDValue("SkipTrustCheck", value);
    else if (key.Open(HKEY_LOCAL_MACHINE, "Software\\Roblox", KEY_READ) == ERROR_SUCCESS)
        key.QueryDWORDValue("SkipTrustCheck", value);
    skipTrustCheck = value != 0;
}
}
