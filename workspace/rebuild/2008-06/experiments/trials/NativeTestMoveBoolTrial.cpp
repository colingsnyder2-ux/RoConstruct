#include "tool/Dragger.h"
#include "v8world/ContactManager.h"
namespace RBX {
bool __cdecl testMove(const G3D::Array<Primitive*>& parts, ContactManager& manager) {
    Extents result = Dragger::computeExtents(parts);
    return result.min().y < -0.01f || manager.intersectingOthers(parts, 0.01f);
}
}
