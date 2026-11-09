#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ToolsArrow.h"
#include "StandardVerbs.h"
#include <typeinfo>
namespace RBX {
template<> bool TToolVerb<ArrowTool,RunStateVerb>::isChecked() const {
    MouseCommand* command = this->dataModel->getWorkspace()->getCurrentMouseCommand();
    if (command) return typeid(ArrowTool) == typeid(*command);
    return false;
}
}
