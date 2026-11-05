#include "NativeRocketWorkerTrial.h"
#include "StandardVerbs.h"
#include <typeinfo>
namespace RBX {
char sRocketTool[]="Rocket";
// moved to native-classes/ToolVerbFactories.cpp
// moved to native-classes/ToolVerbFactories.cpp
MouseCommand* RocketTool::isSticky() const { return new RocketTool(workspace); }
int RocketTool::getShootSound() { return 8; }
// moved to native-classes/ToolVerbFactories.cpp
}
