#include "NativeRocketWorkerTrial.h"
#include "StandardVerbs.h"
#include <typeinfo>
namespace RBX {
char sRocketTool[]="Rocket";
template<> bool TToolVerb<RocketTool,RunStateVerb>::isChecked() const { MouseCommand* command=dataModel->getWorkspace()->getCurrentMouseCommand(); if(command) return typeid(RocketTool)==typeid(*command); return false; }
template<> MouseCommand* TToolVerb<RocketTool,RunStateVerb>::newMouseCommand() { return new RocketTool(dataModel->getWorkspace()); }
MouseCommand* RocketTool::isSticky() const { return new RocketTool(workspace); }
int RocketTool::getShootSound() { return 8; }
template<> const Name& Named<ShootTool,sRocketTool>::getName() const { return NativeToolName<RocketTool>::get(); }
}
