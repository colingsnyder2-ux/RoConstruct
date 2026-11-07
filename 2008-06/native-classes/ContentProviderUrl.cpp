// >>> native-status (generated) -- do not edit >>>
// ContentProviderUrl | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src fdc10061 | roc native-status --write
#include "util/ContentProvider.h"

bool RBX::ContentProvider::isUrl(const std::string& value)
{
    if (value.find("http://") == 0) return true;
    if (value.find("https://") == 0) return true;
    return false;
}
