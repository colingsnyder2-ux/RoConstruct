#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ToolsArrow.h"
#include "tool/NullTool.h"
#include "v8datamodel/ToolsPart.h"
#include "NativeGameToolTrial.h"
#include "NativeResizeToolTrial.h"
#include "NativeAxisMoveToolTrial.h"
#include "NativeFlatToolTrial.h"
#include "NativeSurfaceSiblingsTrial.h"
#include "NativeModelToolsTrial.h"
#include "NativeCloneToolTrial.h"
#include "NativeGrabToolTrial.h"
#include "StandardVerbs.h"
#include <typeinfo>

namespace RBX {
template<class Tool, class Base> bool TToolVerb<Tool, Base>::isChecked() const {
    MouseCommand* command = this->dataModel->getWorkspace()->getCurrentMouseCommand();
    if (command) return typeid(Tool) == typeid(*command);
    return false;
}
template bool TToolVerb<GlueTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<WeldTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<StudsTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<InletTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<HingeTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<RightMotorTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<LeftMotorTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<OscillateMotorTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<ModelSetFrontTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<AnchorTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<LockTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<CloneTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<GrabTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<FlatTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<AxisMoveTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<ResizeTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<ArrowTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<NullTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<GameTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<FillTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<DropperTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<ModelSetPrimaryPartTool, RunStateVerb>::isChecked() const;
}
