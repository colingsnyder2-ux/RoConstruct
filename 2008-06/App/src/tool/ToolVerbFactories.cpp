// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// The 2008 client was built without RBXASSERT: getCurrentMouseCommand inlines to a plain load.
// >>> native-status (generated) -- do not edit >>>
// ToolVerbFactories | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 596ff440 | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ToolsArrow.h"
#include "StandardVerbs.h"
#include "tool/AxisMoveTool.h"
#include "tool/BasicMouseTools.h"
#include "tool/FlatTool.h"
#include "tool/SurfaceTools.h"
#include "tool/ModelTools.h"
#include <typeinfo>
#include "tool/NullTool.h"
#include "v8datamodel/ToolsPart.h"
#include "tool/ResizeTool.h"
#include "tool/ShootTools.h"
#include "tool/GroupDragTool.h"
#include "v8datamodel/PartInstance.h"
#include "tool/PartDragTool.h"
namespace RBX {
// from tests/NativeArrowFactoryTrial.cpp
template<> MouseCommand* TToolVerb<ArrowTool,RunStateVerb>::newMouseCommand() {
    return new ArrowTool(this->dataModel->getWorkspace());
}
// from tests/NativeAxisMoveToolMethodsTrial.cpp
template<> MouseCommand* TToolVerb<AxisMoveTool, RunStateVerb>::newMouseCommand() {
    return new AxisMoveTool(dataModel->getWorkspace());
}
// from tests/NativeCloneToolTrial.cpp
template<> MouseCommand* TToolVerb<CloneTool, RunStateVerb>::newMouseCommand() { return new CloneTool(dataModel->getWorkspace()); }
// from tests/NativeFlatToolTrial.cpp
template<> MouseCommand* TToolVerb<FlatTool, RunStateVerb>::newMouseCommand() { return new FlatTool(dataModel->getWorkspace()); }
// from tests/NativeGameToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<GameTool,RunStateVerb>::newMouseCommand() {
    return new GameTool(this->dataModel->getWorkspace());
}
// from tests/NativeGlueToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<GlueTool, RunStateVerb>::newMouseCommand() { return new GlueTool(dataModel->getWorkspace()); }
// from tests/NativeGrabToolTrial.cpp
template<> MouseCommand* TToolVerb<GrabTool, RunStateVerb>::newMouseCommand() { return new GrabTool(dataModel->getWorkspace()); }
// from tests/NativeHammerWorkerTrial.cpp
template<> MouseCommand* TToolVerb<HammerTool, RunStateVerb>::newMouseCommand() { return new HammerTool(dataModel->getWorkspace()); }
// from tests/NativeHingeToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<HingeTool, RunStateVerb>::newMouseCommand() { return new HingeTool(dataModel->getWorkspace()); }
// from tests/NativeInletToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<InletTool, RunStateVerb>::newMouseCommand() { return new InletTool(dataModel->getWorkspace()); }
// from tests/NativeLaserTrial.cpp
template<> MouseCommand* TToolVerb<LaserTool, RunStateVerb>::newMouseCommand() { return new LaserTool(dataModel->getWorkspace()); }
// from tests/NativeLeftMotorToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<LeftMotorTool, RunStateVerb>::newMouseCommand() { return new LeftMotorTool(dataModel->getWorkspace()); }
// from tests/NativeModelSetFrontToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<ModelSetFrontTool, RunStateVerb>::newMouseCommand() { return new ModelSetFrontTool(dataModel->getWorkspace()); }
// from tests/NativeModelToolsTrial.cpp
template<> MouseCommand* TToolVerb<AnchorTool, RunStateVerb>::newMouseCommand() { return new AnchorTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<LockTool, RunStateVerb>::newMouseCommand() { return new LockTool(dataModel->getWorkspace()); }
// from tests/NativeNullToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<NullTool,RunStateVerb>::newMouseCommand() {
    return new NullTool(this->dataModel->getWorkspace());
}
// from tests/NativeOscillateMotorToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<OscillateMotorTool, RunStateVerb>::newMouseCommand() { return new OscillateMotorTool(dataModel->getWorkspace()); }
// from tests/NativePartToolsFactoriesTrial.cpp
template<> MouseCommand* TToolVerb<FillTool, RunStateVerb>::newMouseCommand() { return new FillTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<DropperTool, RunStateVerb>::newMouseCommand() { return new DropperTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<ModelSetPrimaryPartTool, RunStateVerb>::newMouseCommand() { return new ModelSetPrimaryPartTool(dataModel->getWorkspace()); }
// from tests/NativeResizeToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<ResizeTool, RunStateVerb>::newMouseCommand() {
    return new ResizeTool(dataModel->getWorkspace());
}
// from tests/NativeRightMotorToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<RightMotorTool, RunStateVerb>::newMouseCommand() { return new RightMotorTool(dataModel->getWorkspace()); }
// from tests/NativeRocketWorkerTrial.cpp
template<> MouseCommand* TToolVerb<RocketTool,RunStateVerb>::newMouseCommand() { return new RocketTool(dataModel->getWorkspace()); }
// from tests/NativeSlingshotWorkerTrial.cpp
template<> MouseCommand* TToolVerb<SlingshotTool,RunStateVerb>::newMouseCommand() { return new SlingshotTool(dataModel->getWorkspace()); }
// from tests/NativeStudsToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<StudsTool, RunStateVerb>::newMouseCommand() { return new StudsTool(dataModel->getWorkspace()); }
// from tests/NativeToolCheckedTrial.cpp
// from tests/NativeWeldToolFactoryTrial.cpp
template<> MouseCommand* TToolVerb<WeldTool, RunStateVerb>::newMouseCommand() { return new WeldTool(dataModel->getWorkspace()); }
// Named<...>::getName for the tool classes (from the same trials).
template<> const Name& Named<ArrowToolBase, sAxisMoveTool>::getName() const {
    return NativeToolName<AxisMoveTool>::get();
}
template<> const Name& Named<MouseCommand, sCloneTool>::getName() const { return NativeToolName<CloneTool>::get(); }
template<> const Name& Named<SurfaceTool, sFlatTool>::getName() const { return NativeToolName<FlatTool>::get(); }
template<> const Name& Named<MouseCommand, sGameTool>::getName() const {
    return NativeToolName<GameTool>::get();
}
template<> const Name& Named<SurfaceTool, sGlueTool>::getName() const { return NativeToolName<GlueTool>::get(); }
template<> const Name& Named<MouseCommand, sGrabTool>::getName() const { return NativeToolName<GrabTool>::get(); }

template<> const Name& Named<MouseCommand, sHammerTool>::getName() const { return NativeToolName<HammerTool>::get(); }
template<> const Name& Named<SurfaceTool, sHingeTool>::getName() const { return NativeToolName<HingeTool>::get(); }
template<> const Name& Named<SurfaceTool, sInletTool>::getName() const { return NativeToolName<InletTool>::get(); }
template<> const Name& Named<MouseCommand, sLaserTool>::getName() const { return NativeToolName<LaserTool>::get(); }
template<> const Name& Named<SurfaceTool, sLeftMotorTool>::getName() const { return NativeToolName<LeftMotorTool>::get(); }
template<> const Name& Named<SurfaceTool, sModelSetFrontTool>::getName() const { return NativeToolName<ModelSetFrontTool>::get(); }
template<> const Name& Named<ModelTool, sAnchorTool>::getName() const { return NativeToolName<AnchorTool>::get(); }
template<> const Name& Named<ModelTool, sLockTool>::getName() const { return NativeToolName<LockTool>::get(); }
template<> const Name& Named<SurfaceTool, sOscillateMotorTool>::getName() const { return NativeToolName<OscillateMotorTool>::get(); }

template<> const Name& Named<PartTool, sFillTool>::getName() const { return NativeToolName<FillTool>::get(); }
template<> const Name& Named<PartTool, sDropperTool>::getName() const { return NativeToolName<DropperTool>::get(); }
template<> const Name& Named<PartTool, sModelSetPrimaryPartTool>::getName() const { return NativeToolName<ModelSetPrimaryPartTool>::get(); }
template<> const Name& Named<ArrowToolBase, sArrowTool>::getName() const { return NativeToolName<ArrowTool>::get(); }  // 005a1830
template<> const Name& Named<ArrowToolBase, sResizeTool>::getName() const {
    return NativeToolName<ResizeTool>::get();
}
template<> const Name& Named<SurfaceTool, sRightMotorTool>::getName() const { return NativeToolName<RightMotorTool>::get(); }
template<> const Name& Named<ShootTool,sRocketTool>::getName() const { return NativeToolName<RocketTool>::get(); }
template<> const Name& Named<ShootTool,sSlingshotTool>::getName() const { return NativeToolName<SlingshotTool>::get(); }
template<> const Name& Named<SurfaceTool, sStudsTool>::getName() const { return NativeToolName<StudsTool>::get(); }
template<> const Name& Named<SurfaceTool, sWeldTool>::getName() const { return NativeToolName<WeldTool>::get(); }
// isChecked: one template body, instantiated per tool (tests/NativeToolCheckedMultiTrial.cpp).
template<class Tool, class Base> bool TToolVerb<Tool, Base>::isChecked() const {
    MouseCommand* command = this->dataModel->getWorkspace()->getCurrentMouseCommand();
    if (command) return typeid(Tool) == typeid(*command);
    return false;
}
template bool TToolVerb<ArrowTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<ResizeTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<AxisMoveTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<FlatTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<GlueTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<WeldTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<StudsTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<InletTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<HingeTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<RightMotorTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<LeftMotorTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<OscillateMotorTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<ModelSetFrontTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<ModelSetPrimaryPartTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<AnchorTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<LockTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<FillTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<DropperTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<NullTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<GameTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<GrabTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<CloneTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<HammerTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<SlingshotTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<RocketTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<LaserTool, RunStateVerb>::isChecked() const;
}
