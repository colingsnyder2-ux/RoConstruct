// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// ToolVerbCheckedSurface | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 755cb92f | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/SurfaceTools.h"
#include "StandardVerbs.h"
#include <typeinfo>

namespace RBX {
template<class Tool, class Base> bool TToolVerb<Tool, Base>::isChecked() const {
    MouseCommand* command = dataModel->getWorkspace()->getCurrentMouseCommand();
    if (command) return typeid(Tool) == typeid(*command);
    return false;
}
#define RBX_TOOL_CHECKED(T) template bool TToolVerb<T, RunStateVerb>::isChecked() const;
RBX_TOOL_CHECKED(GlueTool)
RBX_TOOL_CHECKED(WeldTool)
RBX_TOOL_CHECKED(StudsTool)
RBX_TOOL_CHECKED(InletTool)
RBX_TOOL_CHECKED(HingeTool)
RBX_TOOL_CHECKED(RightMotorTool)
RBX_TOOL_CHECKED(LeftMotorTool)
RBX_TOOL_CHECKED(OscillateMotorTool)
RBX_TOOL_CHECKED(ModelSetFrontTool)
#undef RBX_TOOL_CHECKED
}
