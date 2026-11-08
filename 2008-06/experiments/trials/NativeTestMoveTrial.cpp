#include "tool/Dragger.h"
#include "v8world/ContactManager.h"
namespace RBX {
int __cdecl testMove(const G3D::Array<Primitive*>& parts, ContactManager& manager) {
    Extents result = Dragger::computeExtents(parts);
    if (result.min().y < -0.01f || manager.intersectingOthers(parts, 0.01f)) return 1;
    return 0;
}
}
