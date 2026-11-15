// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/pv-parent
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
