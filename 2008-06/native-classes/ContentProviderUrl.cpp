// >>> native-status (generated) -- do not edit >>>
// ContentProviderUrl | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | 2 referenced strings (not rechecked) | by colin (chatgpt:gpt-6.1-sol)
// <<< native-status | src fdc10061 | roc native-status --write
#include "util/ContentProvider.h"

bool RBX::ContentProvider::isUrl(const std::string& value)
{
    if (value.find("http://") == 0) return true;
    if (value.find("https://") == 0) return true;
    return false;
}
