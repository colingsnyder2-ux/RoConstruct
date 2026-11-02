#include "NativeResizeToolTrial.h"
namespace RBX {
ResizeTool::ResizeTool(Workspace* w) : Named<ArrowToolBase, &sResizeTool>(w), overHandle(false), accumulatedResize(0), resetState(0) {}
void forceDestroy(ResizeTool* p) { delete p; }
}
