#include "NativeSlingshotWorkerTrial.h"
#include "StandardVerbs.h"
#include <typeinfo>
namespace RBX {
ShootTool::ShootTool(Workspace* w,bool enabled,int delay):MouseCommand(w),enabled(enabled),delay(delay),remaining(0) {}
template<> MouseCommand* TToolVerb<SlingshotTool,RunStateVerb>::newMouseCommand() { return new SlingshotTool(dataModel->getWorkspace()); }
template<> bool TToolVerb<SlingshotTool,RunStateVerb>::isChecked() const { MouseCommand* command=dataModel->getWorkspace()->getCurrentMouseCommand(); if(command) return typeid(SlingshotTool)==typeid(*command); return false; }
void forceDestroySlingshot(SlingshotTool* p) { delete p; }
}
