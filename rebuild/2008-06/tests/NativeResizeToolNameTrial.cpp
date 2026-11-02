#include "NativeResizeToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<ArrowToolBase, sResizeTool>::getName() const {
    return NativeToolName<ResizeTool>::get();
}
}
