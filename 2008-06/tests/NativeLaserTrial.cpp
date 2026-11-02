#include "NativeLaserTrial.h"
#include "StandardVerbs.h"
#include <typeinfo>
namespace RBX {
template<> MouseCommand* TToolVerb<LaserTool, RunStateVerb>::newMouseCommand() { return new LaserTool(dataModel->getWorkspace()); }
template<> bool TToolVerb<LaserTool, RunStateVerb>::isChecked() const { MouseCommand* command=dataModel->getWorkspace()->getCurrentMouseCommand(); if(command) return typeid(LaserTool)==typeid(*command); return false; }
void forceDestroyLaser(LaserTool* p) { delete p; }
}
