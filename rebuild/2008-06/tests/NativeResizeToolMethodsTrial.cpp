#include "NativeResizeToolTrial.h"
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
