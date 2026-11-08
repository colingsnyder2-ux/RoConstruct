// Inactive native Instance hierarchy method; contributor provenance in manifest.
// >>> native-status (generated) -- do not edit >>>
// InstanceContains | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 0cd1d179 | roc native-status --write
#include "v8tree/Instance.h"

namespace RBX {
bool Instance::contains(const Instance* child) const
{
    for (; child != NULL; child = child->parent) {
        if (child == this)
            return true;
    }
    return false;
}
}
