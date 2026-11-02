#include "NativeGrabToolTrial.h"
#include "v8datamodel/PartInstance.h"
#include "tool/DragTool.h"
namespace RBX {
void GrabTool::onMouseIdle(const UIEvent& input) { onMouseHover(input); }
void GrabTool::onMouseHover(const UIEvent& input) {
    PartInstance* part = getUnlockedPartByLocalCharacter(input);
    if (!part) cursor = "ArrowFarCursor";
    else if (part->getPartLocked()) cursor = "ArrowCursor";
    else cursor = "DragCursor";
}
MouseCommand* GrabTool::onMouseDown(const UIEvent& input) {
    G3D::Vector3 point;
    PartInstance* part = getUnlockedPartByLocalCharacter(input, point);
    if (part) {
        std::vector<Instance*> dragInstances;
        dragInstances.push_back(getTopSelectable3d(part));
        return DragTool::onMouseDown(part, point, dragInstances, input, workspace, boost::shared_ptr<Instance>());
    }
    return NULL;
}
MouseCommand* GrabTool::isSticky() const { return new GrabTool(workspace); }
}
