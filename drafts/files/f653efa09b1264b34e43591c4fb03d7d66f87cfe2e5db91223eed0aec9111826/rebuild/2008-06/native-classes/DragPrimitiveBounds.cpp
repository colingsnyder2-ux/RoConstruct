// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
#include "tool/Dragger.h"
#include "tool/DragUtilities.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Primitive.h"
#include "util/Math.h"
namespace RBX {
// Inlined into clean(parts) 0060f0a0 (aligned 00598cb0, Math::snapToGrid 005deed0 with 0.1f, setCoordinateFrame
// 0059d8a0); openrbx DragUtilities::clean(PartInstance*).
void DragUtilities::clean(PartInstance* part)
{
    if (part->aligned()) {
        const G3D::CoordinateFrame& coord = part->getCoordinateFrame();
        G3D::CoordinateFrame snapped = Math::snapToGrid(coord, 0.1f);

        if (snapped != coord) {
            part->setCoordinateFrame(snapped);
        }
    }
}

// 0060f0a0 (registry func_0060f0a0; caller MegaDragger::alignAndCleanParts 0060e0e6): openrbx DragUtilities::clean.
void DragUtilities::clean(const std::vector<boost::weak_ptr<PartInstance> >& parts)
{
    for (unsigned int i = 0; i < parts.size(); i++) {
        boost::shared_ptr<PartInstance> part = parts[i].lock();

        if (part) {
            clean(part.get());
        }
    }
}

// 0060f1d0 (registry func_0060f1d0; caller MegaDragger::alignAndCleanParts 0060e0da): openrbx DragUtilities::move
// (toObjectSpace 0060e8f0, orthonormalizeIfNecessary 005df0a0, CoordinateFrame * 00476700, setCoordinateFrame 0059d8a0).
void DragUtilities::move(const std::vector<boost::weak_ptr<PartInstance> >& parts, G3D::CoordinateFrame from, G3D::CoordinateFrame to)
{
    for (unsigned int i = 0; i < parts.size(); i++) {
        boost::shared_ptr<PartInstance> part = parts[i].lock();

        if (part) {
            G3D::CoordinateFrame meInFrom = from.toObjectSpace(part->getCoordinateFrame());
            Math::orthonormalizeIfNecessary(meInFrom.rotation);
            part->setCoordinateFrame(to * meInFrom);
        }
    }
}

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
