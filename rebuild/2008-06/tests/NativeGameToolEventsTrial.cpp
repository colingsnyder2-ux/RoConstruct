#include "NativeGameToolTrial.h"
namespace RBX {
void GameTool::onMouseIdle(const UIEvent& event) { onMouseHover(event); }
void GameTool::onMouseHover(const UIEvent& event) {
    if (event.windowSize.x && event.windowSize.y) {
        G3D::Vector3 point;
        PartInstance* part = getUnlockedPartByLocalCharacter(event, point);
        if (!part) cursor = "ArrowFarCursor";
        else if (!canDrag(part, point)) cursor = "ArrowCursor";
        else cursor = "DragCursor";
    }
}
}
