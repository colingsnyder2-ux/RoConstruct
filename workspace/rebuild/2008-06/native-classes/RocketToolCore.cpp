// >>> native-status (generated) -- do not edit >>>
// RocketToolCore | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by king_originala (+1) (chatgpt:gpt-6.1-sol)
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
