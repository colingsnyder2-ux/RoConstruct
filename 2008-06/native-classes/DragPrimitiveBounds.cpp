// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// >>> native-status (generated) -- do not edit >>>
// DragPrimitiveBounds | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 6892ac0f | roc native-status --write
#include "tool/Dragger.h"
#include "tool/DragUtilities.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Primitive.h"
namespace RBX {
__declspec(noinline) void collectPrimitives(const Instance* object, std::vector<Primitive*>& output) {
    if (const PartInstance* part = dynamic_cast<const PartInstance*>(object))
        output.push_back(const_cast<Primitive*>(part->getPrimitive()));
    for (size_t i = 0; i < object->numChildren(); ++i)
        collectPrimitives(object->getChild(i), output);
}
void DragUtilities::getPrimitives(const Instance* object, std::vector<Primitive*>& output) {
    collectPrimitives(object, output);
}
Extents Dragger::computeExtents(const std::vector<Primitive*>& primitives) {
    Extents result = Extents::negativeInfiniteExtents();
    for (unsigned i = 0; i < primitives.size(); ++i) {
        Primitive* primitive = primitives[i];
        G3D::Vector3 half = primitive->getGeometry()->getGridSize() * 0.5f;
        Extents world = Extents(-half, half).toWorldSpace(primitive->getCoordinateFrame());
        result.unionWith(world);
    }
    return result;
}
}
