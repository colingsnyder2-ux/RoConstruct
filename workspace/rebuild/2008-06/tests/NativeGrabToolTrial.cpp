#include "NativeGrabToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
GrabTool::GrabTool(Workspace* workspace) : Named<MouseCommand, sGrabTool>(workspace), cursor("ArrowCursor") {}
GrabTool::~GrabTool() {}
// moved to native-classes/ToolVerbFactories.cpp
void forceDestroy(GrabTool* p) { delete p; }
}
