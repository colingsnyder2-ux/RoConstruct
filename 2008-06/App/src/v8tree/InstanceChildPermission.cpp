// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// InstanceChildPermission | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 1ce6bbf1 | roc native-status --write
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
