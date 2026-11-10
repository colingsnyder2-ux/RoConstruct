#include "NativeSurfaceToolTrial.h"
namespace RBX {
SurfaceTool::SurfaceTool(Workspace* workspace) : MouseCommand(workspace), surface(NULL) {}
void forceDestroy(SurfaceTool* p) { delete p; }
}
