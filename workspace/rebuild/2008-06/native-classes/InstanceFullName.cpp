// >>> native-status (generated) -- do not edit >>>
// InstanceFullName | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (deepseek:deepseek-flash)
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
