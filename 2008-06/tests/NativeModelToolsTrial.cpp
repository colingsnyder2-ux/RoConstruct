#include "NativeModelToolsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> MouseCommand* TToolVerb<AnchorTool, RunStateVerb>::newMouseCommand() { return new AnchorTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<LockTool, RunStateVerb>::newMouseCommand() { return new LockTool(dataModel->getWorkspace()); }
void forceDestroy(AnchorTool* p) { delete p; }
void forceDestroy(LockTool* p) { delete p; }
}
