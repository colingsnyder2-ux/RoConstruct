// >>> native-status (generated) -- do not edit >>>
// InstanceFullName | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 86db1dc4 | roc native-status --write
#include "v8tree/Instance.h"
namespace RBX {
std::string Instance::getFullName() const {
    if (parent) {
        if (parent->parent)
            return parent->getFullName() + "." + name;
        return name;
    }
    return "";
}
}
