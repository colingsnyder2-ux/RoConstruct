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

// 00422ae0: true if target is an ancestor of this instance.
bool Instance::isDescendantOf(const Instance* target) const
{
    for (const Instance* p = parent; p != NULL; p = p->parent) {
        if (p == target)
            return true;
    }
    return false;
}
}
