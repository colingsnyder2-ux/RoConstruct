// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// >>> native-status (generated) -- do not edit >>>
// DragPrimitiveBounds | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/2 mapped addresses byte-exact | 1 unproved | no mapped strings | by Espeon (mixed 2)
// <<< native-status | src 640ff6ea | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Vector_const_iterator<RBX::Primitive *,std::allocator<RBX::Primitive *> >;
template class std::_Vector_iterator<RBX::Primitive *,std::allocator<RBX::Primitive *> >;
