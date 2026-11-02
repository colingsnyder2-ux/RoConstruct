#include "NativeResizeToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<class Tool, class Base> MouseCommand* TToolVerb<Tool, Base>::newMouseCommand() {
    return new Tool(this->dataModel->getWorkspace());
}
template MouseCommand* TToolVerb<ResizeTool, RunStateVerb>::newMouseCommand();
}
