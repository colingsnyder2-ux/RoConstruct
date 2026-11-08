// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/DataModel.h"
#include "tool/ToolsArrow.h"
#include "StandardVerbs.h"

namespace RBX {
char sArrowTool[] = "Arrow";
template<> MouseCommand* TToolVerb<ArrowTool, RunStateVerb>::newMouseCommand()
{
    return new ArrowTool(dataModel->getWorkspace());
}
template<> const Name& Named<ArrowToolBase, sArrowTool>::getName() const
{
    return NativeToolName<ArrowTool>::get();
}
}
