// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/pv-parent
// >>> native-status (generated) -- do not edit >>>
// PVInstanceTopParent | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src df8e5f8e | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/PVInstance.h"

namespace RBX {
PVInstance* PVInstance::getTopLevelPVParent()
{
    PVInstance* part = this;
    while (!part->isTopLevelPVInstance())
        part = static_cast<PVInstance*>(part->getParent());
    return part;
}
}
