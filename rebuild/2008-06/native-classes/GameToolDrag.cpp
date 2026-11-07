// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// GameToolDrag | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src b888a75f | roc native-status --write
#include "tool/BasicMouseTools.h"

namespace RBX {
bool GameTool::canDrag(PartInstance* part, const G3D::Vector3& point)
{
    return !part->getPartLocked() && !part->lockedInPlace() && characterCanReach(point);
}
}
