#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/AxisMoveTool.h"
#include "StandardVerbs.h"
namespace RBX {
// Original 005c6510: allocation 0x74; constructor 00640560; MouseCommand is the primary base.
template<> MouseCommand* TToolVerb<AxisMoveTool, RunStateVerb>::newMouseCommand() {
    return new AxisMoveTool(dataModel->getWorkspace());
}
}
