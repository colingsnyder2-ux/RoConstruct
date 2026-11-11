// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ArrowToolFactory | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 98cbc11c | roc native-status --write
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
