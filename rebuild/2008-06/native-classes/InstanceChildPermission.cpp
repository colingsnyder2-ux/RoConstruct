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
}
