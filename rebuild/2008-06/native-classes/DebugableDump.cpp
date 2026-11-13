// >>> native-status (generated) -- do not edit >>>
// DebugableDump | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by tester
// <<< native-status | src 85de5d5a | roc native-status --write
#include "util/Debug.h"
#include <typeinfo>

namespace RBX {
void Debugable::dump(std::ostream& stream) {
    const std::type_info& type = typeid(*this);
    stream << type.name();
}
}
