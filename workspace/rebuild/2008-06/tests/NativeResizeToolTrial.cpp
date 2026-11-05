#include "NativeResizeToolTrial.h"
namespace RBX {
ResizeTool::ResizeTool(Workspace* w) : Named<ArrowToolBase, sResizeTool>(w), overHandle(false), moveAxis(0), movePerp(0) {}
void forceDestroy(ResizeTool* p) { delete p; }
}
