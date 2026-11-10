#include "tool/Dragger.h"
#include "v8world/Primitive.h"
namespace RBX {
Extents Dragger::computeExtents(const std::vector<Primitive*>& primitives) {
    Extents result = Extents::negativeInfiniteExtents();
    for (unsigned i = 0; i < primitives.size(); ++i) {
        Primitive* p = primitives[i];
        G3D::Vector3 half = (*reinterpret_cast<Geometry**>(reinterpret_cast<char*>(p) + 0x9c))->getGridSize() * 0.5f;
        Extents world = Extents(-half, half).toWorldSpace(p->getCoordinateFrame());
        result.unionWith(world);
    }
    return result;
}
}
