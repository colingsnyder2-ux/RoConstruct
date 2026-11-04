#include "NativeGameToolTrial.h"
#include "NativePartDragToolTrial.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
MouseCommand* GameTool::onMouseDown(const UIEvent& event) {
    G3D::Vector3 point;
    PartInstance* part = getUnlockedPartByLocalCharacter(event, point);
    if (part && !part->getPartLocked() && !part->lockedInPlace() && characterCanReach(point))
        return (new PartDragTool(part, point, workspace, boost::shared_ptr<Instance>()))->onMouseDown(event);
    return NULL;
}
}
