#include "NativeSlingshotWorkerTrial.h"
#include "StandardVerbs.h"
#include <typeinfo>
namespace RBX {
ShootTool::ShootTool(Workspace* w,bool enabled,int delay):MouseCommand(w),enabled(enabled),delay(delay),remaining(0) {}
// moved to native-classes/ToolVerbFactories.cpp
// moved to native-classes/ToolVerbFactories.cpp
void forceDestroySlingshot(SlingshotTool* p) { delete p; }
}
