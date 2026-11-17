#include "util/Debug.h"
#include <typeinfo>

namespace RBX {
void Debugable::dump(std::ostream& stream) {
    const std::type_info& type = typeid(*this);
    stream << type.name();
}
}
