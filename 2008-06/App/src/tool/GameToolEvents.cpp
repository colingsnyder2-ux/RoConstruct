// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// GameToolEvents | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src a0939e6a | roc native-status --write
#include "tool/BasicMouseTools.h"
#include "tool/PartDragTool.h"
#include "v8datamodel/Workspace.h"

namespace RBX {
MouseCommand* GameTool::isSticky() const { return new GameTool(workspace); }
void GameTool::onMouseIdle(const UIEvent& event) { onMouseHover(event); }

void GameTool::onMouseHover(const UIEvent& event)
{
    if (event.windowSize.x && event.windowSize.y) {
        G3D::Vector3 point;
        PartInstance* part = getUnlockedPartByLocalCharacter(event, point);
        if (!part) cursor = "ArrowFarCursor";
        else if (!canDrag(part, point)) cursor = "ArrowCursor";
        else cursor = "DragCursor";
    }
}

MouseCommand* GameTool::onMouseDown(const UIEvent& event)
{
    G3D::Vector3 point;
    PartInstance* part = getUnlockedPartByLocalCharacter(event, point);
    if (part && !part->getPartLocked() && !part->lockedInPlace() && characterCanReach(point))
        return (new PartDragTool(part, point, workspace, boost::shared_ptr<Instance>()))->onMouseDown(event);
    return NULL;
}
}
