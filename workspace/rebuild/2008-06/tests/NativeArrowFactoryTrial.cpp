#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ToolsArrow.h"
#include "StandardVerbs.h"
namespace RBX {
#ifndef DONOR_LAYOUT_TRIAL
typedef char ArrowToolSize[sizeof(ArrowTool) == 0x20 ? 1 : -1];
#endif
template<> MouseCommand* TToolVerb<ArrowTool,RunStateVerb>::newMouseCommand() {
    return new ArrowTool(this->dataModel->getWorkspace());
}
}
