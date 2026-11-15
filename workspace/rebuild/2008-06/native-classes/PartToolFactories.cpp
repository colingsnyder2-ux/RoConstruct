// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/DataModel.h"
#include "v8datamodel/ToolsPart.h"
#include "StandardVerbs.h"

namespace RBX {
template<> MouseCommand* TToolVerb<FillTool, RunStateVerb>::newMouseCommand() { return new FillTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<DropperTool, RunStateVerb>::newMouseCommand() { return new DropperTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<ModelSetPrimaryPartTool, RunStateVerb>::newMouseCommand() { return new ModelSetPrimaryPartTool(dataModel->getWorkspace()); }
}
