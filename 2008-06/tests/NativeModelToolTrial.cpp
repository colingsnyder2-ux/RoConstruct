#include "NativeModelToolTrial.h"
namespace RBX {
ModelTool::ModelTool(Workspace* workspace) : MouseCommand(workspace) {}
void forceDestroy(ModelTool* p) { delete p; }
}
