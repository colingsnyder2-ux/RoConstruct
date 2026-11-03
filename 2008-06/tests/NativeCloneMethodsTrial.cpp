#include "NativeCloneToolTrial.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
static G3D::Vector3 idlePoint;
void CloneTool::onMouseIdle(const UIEvent& input) {
    partInstance = shared_from(getUnlockedPartByLocalCharacter(input, idlePoint));
}
const std::string CloneTool::getCursorName() const {
    if (partInstance) return "CloneOverCursor";
    return "CloneCursor";
}
}
