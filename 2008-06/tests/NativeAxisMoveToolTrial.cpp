#include "NativeAxisMoveToolTrial.h"
namespace RBX {
AxisMoveTool::AxisMoveTool(Workspace* w) : Named<ArrowToolBase, sAxisMoveTool>(w), cursor("ArrowCursor"), dragging(false) {}
void forceDestroy(AxisMoveTool* p) { delete p; }
}
