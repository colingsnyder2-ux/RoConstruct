#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "StandardVerbs.h"
namespace RBX {
char sAxisMoveTool[] = "AxisMove";
template<> const Name& Named<ArrowToolBase, sAxisMoveTool>::getName() const { return NativeToolName<AxisMoveTool>::get(); }
}
