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
