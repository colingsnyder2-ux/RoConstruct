#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ToolsArrow.h"
#include "tool/NullTool.h"
#include "v8datamodel/ToolsPart.h"
#include "NativeGameToolTrial.h"
#include "StandardVerbs.h"
#include <typeinfo>

namespace RBX {
template<class Tool, class Base> bool TToolVerb<Tool, Base>::isChecked() const {
    MouseCommand* command = this->dataModel->getWorkspace()->getCurrentMouseCommand();
    if (command) return typeid(Tool) == typeid(*command);
    return false;
}
template bool TToolVerb<ArrowTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<NullTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<GameTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<FillTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<DropperTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<ModelSetPrimaryPartTool, RunStateVerb>::isChecked() const;
}
