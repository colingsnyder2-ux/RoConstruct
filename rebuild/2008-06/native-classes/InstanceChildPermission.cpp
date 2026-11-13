// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// InstanceChildPermission | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
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
