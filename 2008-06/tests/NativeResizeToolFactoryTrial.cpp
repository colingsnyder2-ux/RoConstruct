#include "NativeResizeToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> MouseCommand* TToolVerb<ResizeTool, RunStateVerb>::newMouseCommand() {
    return new ResizeTool(dataModel->getWorkspace());
}
}
