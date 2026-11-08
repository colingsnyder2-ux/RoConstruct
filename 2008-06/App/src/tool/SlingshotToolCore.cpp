// >>> native-status (generated) -- do not edit >>>
// SlingshotToolCore | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 6eb1ff2d | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ShootTools.h"
#include "StandardVerbs.h"
namespace RBX {
char sSlingshotTool[] = "Slingshot";
ShootTool::ShootTool(Workspace* w, bool enabled, int delay) : MouseCommand(w), enabled(enabled), delay(delay), remaining(0) {}
template<> MouseCommand* TToolVerb<SlingshotTool, RunStateVerb>::newMouseCommand() { return new SlingshotTool(dataModel->getWorkspace()); }
template<> const Name& Named<ShootTool, sSlingshotTool>::getName() const { return NativeToolName<SlingshotTool>::get(); }
}
