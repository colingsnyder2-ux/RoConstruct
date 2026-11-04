#include "NativeFlatToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> MouseCommand* TToolVerb<FlatTool, RunStateVerb>::newMouseCommand() { return new FlatTool(dataModel->getWorkspace()); }
void forceDestroy(FlatTool* p) { delete p; }
}
