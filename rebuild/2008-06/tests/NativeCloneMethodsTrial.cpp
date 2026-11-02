#include "NativeCloneToolTrial.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
void CloneTool::onMouseIdle(const UIEvent& input) {
    partInstance = shared_from(getUnlockedPartByLocalCharacter(input));
}
const std::string CloneTool::getCursorName() const {
    if (partInstance) return "CloneOverCursor";
    return "CloneCursor";
}
}
