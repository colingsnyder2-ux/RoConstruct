// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#undef _RELEASEASSERT
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ToolsArrow.h"
#include "tool/NullTool.h"
#include "v8datamodel/ToolsPart.h"
#include "StandardVerbs.h"
#include <typeinfo>

namespace RBX {
template<class Tool, class Base> bool TToolVerb<Tool, Base>::isChecked() const {
    MouseCommand* command = dataModel->getWorkspace()->getCurrentMouseCommand();
    if (command) return typeid(Tool) == typeid(*command);
    return false;
}
template bool TToolVerb<ArrowTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<NullTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<FillTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<DropperTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<ModelSetPrimaryPartTool, RunStateVerb>::isChecked() const;
}
