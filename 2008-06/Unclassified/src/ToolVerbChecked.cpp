// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// ToolVerbChecked | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src f0b82bfe | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ToolsArrow.h"
#include "StandardVerbs.h"
#include "../../tests/NativeAxisMoveToolTrial.h"
#include "../../tests/NativeCloneToolTrial.h"
#include "../../tests/NativeFlatToolTrial.h"
#include "../../tests/NativeGameToolTrial.h"
#include "../../tests/NativeSurfaceSiblingsTrial.h"
#include "../../tests/NativeGrabToolTrial.h"
#include "../../tests/NativeHammerWorkerTrial.h"
#include "../../tests/NativeLaserTrial.h"
#include "../../tests/NativeModelToolsTrial.h"
#include "tool/NullTool.h"
#include "v8datamodel/ToolsPart.h"
#include "../../tests/NativeResizeToolTrial.h"
#include "../../tests/NativeRocketWorkerTrial.h"
#include "../../tests/NativeSlingshotWorkerTrial.h"
#include "tool/GroupDragTool.h"
#include "v8datamodel/PartInstance.h"
#include "tool/PartDragTool.h"
#include <typeinfo>

namespace RBX {
template<class Tool, class Base> bool TToolVerb<Tool, Base>::isChecked() const
{
    MouseCommand* command = this->dataModel->getWorkspace()->getCurrentMouseCommand();
    if (command) return typeid(Tool) == typeid(*command);
    return false;
}

#define TOOL_VERBS(M) \
    M(ArrowTool) M(ResizeTool) M(AxisMoveTool) M(FlatTool) M(GlueTool) M(WeldTool) \
    M(StudsTool) M(InletTool) M(HingeTool) M(RightMotorTool) M(LeftMotorTool) \
    M(OscillateMotorTool) M(ModelSetFrontTool) M(ModelSetPrimaryPartTool) M(AnchorTool) \
    M(LockTool) M(FillTool) M(DropperTool) M(NullTool) M(GameTool) M(GrabTool) \
    M(CloneTool) M(HammerTool) M(SlingshotTool) M(RocketTool) M(LaserTool)
#define INSTANTIATE(T) template bool TToolVerb<T, RunStateVerb>::isChecked() const;
TOOL_VERBS(INSTANTIATE)
#undef INSTANTIATE
#undef TOOL_VERBS
}
