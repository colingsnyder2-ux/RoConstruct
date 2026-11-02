#include "NativeCloneToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
CloneTool::CloneTool(Workspace* workspace) : Named<MouseCommand, &sCloneTool>(workspace) {}
template<> MouseCommand* TToolVerb<CloneTool, RunStateVerb>::newMouseCommand() { return new CloneTool(dataModel->getWorkspace()); }
void forceDestroy(CloneTool* p) { delete p; }
}
