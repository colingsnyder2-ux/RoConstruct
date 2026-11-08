// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/BasicMouseTools.h"

namespace RBX {
bool GameTool::canDrag(PartInstance* part, const G3D::Vector3& point)
{
    return !part->getPartLocked() && !part->lockedInPlace() && characterCanReach(point);
}
}
