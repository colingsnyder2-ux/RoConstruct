// >>> native-status (generated) -- do not edit >>>
// ContentProviderUrl | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src fdc10061 | roc native-status --write
#include "util/ContentProvider.h"

bool RBX::ContentProvider::isUrl(const std::string& value)
{
    if (value.find("http://") == 0) return true;
    if (value.find("https://") == 0) return true;
    return false;
}
