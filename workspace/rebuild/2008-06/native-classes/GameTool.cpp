// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// GameTool | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 0ac15f11 | roc native-status --write
#include "tool/BasicMouseTools.h"
#include "tool/PartDragTool.h"
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
char sGameTool[] = "GameTool";
GameTool::GameTool(Workspace* workspace) : Named<MouseCommand, sGameTool>(workspace) {}
GameTool::~GameTool() {}

template<> const Name& Named<MouseCommand, sGameTool>::getName() const
{
    return NativeToolName<GameTool>::get();
}
template<> MouseCommand* TToolVerb<GameTool, RunStateVerb>::newMouseCommand()
{
    return new GameTool(dataModel->getWorkspace());
}

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
