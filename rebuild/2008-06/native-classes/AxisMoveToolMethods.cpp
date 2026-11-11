// >>> native-status (generated) -- do not edit >>>
// AxisMoveToolMethods | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 3d817b65 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "StandardVerbs.h"
namespace RBX {
void recordCameraHistory(const char*, const Instance*);
MouseCommand* AxisMoveTool::isSticky() const { return new AxisMoveTool(workspace); }
MouseCommand* AxisMoveTool::onMouseUp(const UIEvent&) {
    if (dragging) {
        megaDragger->finishDragging();
        megaDragger.release();
        dragging = false;
        recordCameraHistory(getName().c_str(), workspace);
    }
    releaseCapture();
    return NULL;
}
void AxisMoveTool::onMouseIdle(const UIEvent& event) {
    ArrowToolBase::onMouseIdle(event);
    if (captured()) cursor = "DragCursor";
    else {
        G3D::Vector3 point;
        NormalId face;
        if (hitHandle(event, point, face)) cursor = "ResizeCursor";
        else cursor = ArrowToolBase::getCursorName();
    }
}
}
