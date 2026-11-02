#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "StandardVerbs.h"
namespace RBX {
template<class Tool,class Base> void TToolVerb<Tool,Base>::doIt(IDataState*) {
    if (isChecked()) this->dataModel->getWorkspace()->setDefaultMouseCommand();
    else this->dataModel->getWorkspace()->setMouseCommand(newMouseCommand());
}
template void TToolVerb<ArrowTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<ResizeTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<AxisMoveTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<FlatTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<GlueTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<WeldTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<StudsTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<InletTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<HingeTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<RightMotorTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<LeftMotorTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<OscillateMotorTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<ModelSetFrontTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<ModelSetPrimaryPartTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<AnchorTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<LockTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<FillTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<DropperTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<NullTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<GameTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<GrabTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<CloneTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<HammerTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<SlingshotTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<RocketTool,RunStateVerb>::doIt(IDataState*);
template void TToolVerb<LaserTool,RunStateVerb>::doIt(IDataState*);
}
