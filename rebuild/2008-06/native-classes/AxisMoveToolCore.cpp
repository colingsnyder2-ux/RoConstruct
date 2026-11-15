#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "StandardVerbs.h"
namespace RBX {
char sAxisMoveTool[] = "AxisMove";
AxisMoveTool::AxisMoveTool(Workspace* w) : Named<ArrowToolBase, sAxisMoveTool>(w), cursor("ArrowCursor"), dragging(false) {}
template<> MouseCommand* TToolVerb<AxisMoveTool, RunStateVerb>::newMouseCommand() {
    return new AxisMoveTool(dataModel->getWorkspace());
}
template<> const Name& Named<ArrowToolBase, sAxisMoveTool>::getName() const { return NativeToolName<AxisMoveTool>::get(); }
}
