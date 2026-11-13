// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// GameToolDrag | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (deepseek:deepseek-flash)
// <<< native-status | src b888a75f | roc native-status --write
#include "tool/BasicMouseTools.h"

namespace RBX {
bool GameTool::canDrag(PartInstance* part, const G3D::Vector3& point)
{
    return !part->getPartLocked() && !part->lockedInPlace() && characterCanReach(point);
}
}
