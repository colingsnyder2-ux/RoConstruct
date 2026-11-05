#include "NativeSurfaceToolTrial.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
void SurfaceTool::onMouseHover(const UIEvent& input) {
    PartInstance* part;
    surface = getSurface(input, part, surfaceId);
    partInstance = shared_from(surface ? part : NULL);
}
}
