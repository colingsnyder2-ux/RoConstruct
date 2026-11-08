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
