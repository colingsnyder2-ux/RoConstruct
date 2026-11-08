#include "NativeGameToolTrial.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
bool GameTool::canDrag(PartInstance* part, const G3D::Vector3& point) {
    return !part->getPartLocked() && !part->lockedInPlace() && characterCanReach(point);
}
}
