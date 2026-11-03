#include "NativeCloneToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
CloneTool::CloneTool(Workspace* workspace) : Named<MouseCommand, sCloneTool>(workspace) {}
// moved to native-classes/ToolVerbFactories.cpp
void forceDestroy(CloneTool* p) { delete p; }
}
