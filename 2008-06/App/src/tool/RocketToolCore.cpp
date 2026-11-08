// >>> native-status (generated) -- do not edit >>>
// RocketToolCore | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src f7ca5e54 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ShootTools.h"
#include "StandardVerbs.h"
namespace RBX {
char sRocketTool[] = "Rocket";
template<> MouseCommand* TToolVerb<RocketTool, RunStateVerb>::newMouseCommand() { return new RocketTool(dataModel->getWorkspace()); }
template<> const Name& Named<ShootTool, sRocketTool>::getName() const { return NativeToolName<RocketTool>::get(); }
MouseCommand* RocketTool::isSticky() const { return new RocketTool(workspace); }
int RocketTool::getShootSound() { return 8; }
}
