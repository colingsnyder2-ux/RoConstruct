#include "NativeHammerWorkerTrial.h"
#include "StandardVerbs.h"
#include <typeinfo>
namespace RBX {
template<> MouseCommand* TToolVerb<HammerTool, RunStateVerb>::newMouseCommand() { return new HammerTool(dataModel->getWorkspace()); }
template<> bool TToolVerb<HammerTool, RunStateVerb>::isChecked() const { MouseCommand* command=dataModel->getWorkspace()->getCurrentMouseCommand(); if(command) return typeid(HammerTool)==typeid(*command); return false; }
void forceDestroyHammer(HammerTool* p) { delete p; }
}
