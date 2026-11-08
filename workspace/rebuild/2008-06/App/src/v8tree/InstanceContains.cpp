// Inactive native Instance hierarchy method; contributor provenance in manifest.
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
