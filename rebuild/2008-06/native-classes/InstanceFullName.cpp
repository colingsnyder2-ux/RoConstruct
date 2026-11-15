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
