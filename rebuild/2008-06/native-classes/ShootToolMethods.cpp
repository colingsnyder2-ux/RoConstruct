// >>> native-status (generated) -- do not edit >>>
// ShootToolMethods | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 432d1e0f | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ShootTools.h"
#include "StandardVerbs.h"
namespace RBX {
MouseCommand* ShootTool::onMouseDown(const UIEvent& input) { capture(); if (!remaining) shoot(input); return this; }
void ShootTool::onMouseIdle(const UIEvent& input) { if (remaining>0) --remaining; if (captured()) onMouseMove(input); }
void ShootTool::onMouseMove(const UIEvent& input) { if (enabled && !remaining) shoot(input); }
MouseCommand* ShootTool::onMouseUp(const UIEvent&) { releaseCapture(); return this; }
const std::string ShootTool::getCursorName() const { if (remaining && delay>10) return "GunWaitCursor"; return "GunCursor"; }
MouseCommand* SlingshotTool::isSticky() const { return new SlingshotTool(workspace); }
}
