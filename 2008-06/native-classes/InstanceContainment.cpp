// >>> native-status (generated) -- do not edit >>>
// InstanceContainment | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
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
