// >>> native-status (generated) -- do not edit >>>
// InstanceContainment | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 250056b9 | roc native-status --write
#include "v8tree/Instance.h"
namespace RBX {
bool Instance::contains(const Instance* child) const {
    while (child) {
        if (child == this) return true;
        child = child->getParent();
    }
    return false;
}
}
