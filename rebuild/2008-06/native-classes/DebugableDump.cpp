// >>> native-status (generated) -- do not edit >>>
// DebugableDump | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 85de5d5a | roc native-status --write
#include "util/Debug.h"
#include <typeinfo>

namespace RBX {
void Debugable::dump(std::ostream& stream) {
    const std::type_info& type = typeid(*this);
    stream << type.name();
}
}
