// >>> native-status (generated) -- do not edit >>>
// ResizeToolMethods | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 75192014 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ResizeTool.h"
namespace RBX {
void recordCameraHistory(const char*, const Instance*);
MouseCommand* ResizeTool::isSticky() const { return new ResizeTool(workspace); }
const std::string ResizeTool::getCursorName() const {
    return overHandle ? "ResizeCursor" : ArrowToolBase::getCursorName();
}
void ResizeTool::onMouseHover(const UIEvent& inputObject) {
    findTargetPV(inputObject);
    overHandle = !targetPV.expired();
    ArrowToolBase::onMouseHover(inputObject);
}
MouseCommand* ResizeTool::onMouseDown(const UIEvent& inputObject) {
    findTargetPV(inputObject);
    if (targetPV.expired()) return ArrowToolBase::onMouseDown(inputObject);
    down = inputObject.mousePosition;
    moveAxis = 0;
    movePerp = 0;
    overHandle = true;
    capture();
    return this;
}
MouseCommand* ResizeTool::onMouseUp(const UIEvent&) {
    if (captured()) {
        releaseCapture();
        if (!targetPV.expired()) {
            recordCameraHistory(getName().c_str(), workspace);
            workspace->getDataState().setDirty(true);
        }
    }
    return NULL;
}
}
