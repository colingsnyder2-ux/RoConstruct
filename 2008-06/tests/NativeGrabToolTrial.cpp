#include "NativeGrabToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
GrabTool::GrabTool(Workspace* workspace) : Named<MouseCommand, &sGrabTool>(workspace), cursor("ArrowCursor") {}
GrabTool::~GrabTool() {}
template<> MouseCommand* TToolVerb<GrabTool, RunStateVerb>::newMouseCommand() { return new GrabTool(dataModel->getWorkspace()); }
void forceDestroy(GrabTool* p) { delete p; }
}
