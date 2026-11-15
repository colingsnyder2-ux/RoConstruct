// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8tree/Instance.h"

namespace RBX {
bool Instance::canAddChild(const Instance* child) const
{
    if (child->contains(this)) return false;
    if (child->parent == this) return false;
    if (askAddChild(child)) return true;
    if (child->askSetParent(this)) return true;
    return false;
}

// 0041f390: canAddChild 0041f340 stays an out-of-line call in the original.
bool Instance::canSetParent(const Instance* newParent) const
{
    return !newParent || newParent->canAddChild(this);
}
}
