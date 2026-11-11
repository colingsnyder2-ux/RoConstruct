// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// ToolVerbCore | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src ca68984b | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "StandardVerbs.h"

namespace RBX {
template<class Tool, class Base> void TToolVerb<Tool, Base>::doIt(IDataState*)
{
    if (isChecked()) this->dataModel->getWorkspace()->setDefaultMouseCommand();
    else this->dataModel->getWorkspace()->setMouseCommand(newMouseCommand());
}

#define TOOL_VERBS(M) \
    M(ArrowTool) M(ResizeTool) M(AxisMoveTool) M(FlatTool) M(GlueTool) M(WeldTool) \
    M(StudsTool) M(InletTool) M(HingeTool) M(RightMotorTool) M(LeftMotorTool) \
    M(OscillateMotorTool) M(ModelSetFrontTool) M(ModelSetPrimaryPartTool) M(AnchorTool) \
    M(LockTool) M(FillTool) M(DropperTool) M(NullTool) M(GameTool) M(GrabTool) \
    M(CloneTool) M(HammerTool) M(SlingshotTool) M(RocketTool) M(LaserTool)

#define INSTANTIATE(T) \
    template void TToolVerb<T, RunStateVerb>::doIt(IDataState*);
TOOL_VERBS(INSTANTIATE)
#undef INSTANTIATE
#undef TOOL_VERBS
}
