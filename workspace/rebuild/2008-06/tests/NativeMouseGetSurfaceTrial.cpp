#include "NativeSurfaceToolTrial.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
Surface* MouseCommand::getSurface(const UIEvent& input, PartInstance*& part, int& id) {
    part = getPart(input, NULL);
    if (part) {
        G3D::Ray ray = getUnitMouseRay(input);
        if (Surface* surface = part->getSurface(ray, id)) return surface;
    }
    return NULL;
}
}
