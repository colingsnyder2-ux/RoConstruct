#include "v8datamodel/ToolsPart.h"
namespace RBX {
PartTool::PartTool(Workspace* workspace) : MouseCommand(workspace) {}
void forceDestroy(PartTool* p) { delete p; }
}
