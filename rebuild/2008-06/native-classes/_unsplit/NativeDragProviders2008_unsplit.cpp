// UNSPLIT CANDIDATE (2026-11-08): drag/handle/megadragger native providers
// Provides: DragUtilities::getPrimitives, Dragger::computeExtents, hitMoveHandles, MegaDragger::safeMoveAlongLine, anyDragPartAlive
// Do not compile alongside originals (duplicate symbols). Review before promotion.

// ---- BEGIN DragPrimitiveBounds.cpp ----
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// >>> native-status (generated) -- do not edit >>>
// NativeDragProviders2008_unsplit | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 68fe51b6 | roc native-status --write
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
// ---- END DragPrimitiveBounds.cpp ----

// ---- BEGIN MoveHandleHit.cpp ----
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/Extents.h"
#include <G3D/Ray.h>
#include <G3D/Sphere.h>
#include <G3D/CollisionDetection.h>
namespace RBX {
float moveHandleRadius(const G3D::Vector3&, const G3D::Vector3&);
bool hitMoveHandlesInFrame(const Extents& box, const G3D::CoordinateFrame& frame,
    const G3D::Ray& ray, G3D::Vector3& result, NormalId& face) {
    for (int i = 0; i < 6; ++i) {
        G3D::Vector3 center = box.faceCenter(static_cast<NormalId>(i));
        center += normalIdToVector3(static_cast<NormalId>(i)) * 3.f;
        G3D::Vector3 point = frame.pointToWorldSpace(center);
        float radius = moveHandleRadius(ray.origin, point);
        G3D::Vector3 hit;
        bool found = G3D::CollisionDetection::collisionTimeForMovingPointFixedSphere(
            ray.origin, ray.direction, G3D::Sphere(point, radius), hit) != G3D::inf();
        if (found) { face = static_cast<NormalId>(i); result = point; return true; }
    }
    return false;
}
bool hitMoveHandles(const Extents& box, const G3D::Ray& ray, G3D::Vector3& point, NormalId& face) {
    G3D::CoordinateFrame frame(box.center());
    Extents local = Extents::fromCenterCorner(G3D::Vector3::zero(), box.size() * 0.5f);
    return hitMoveHandlesInFrame(local, frame, ray, point, face);
}
}
// ---- END MoveHandleHit.cpp ----

// ---- BEGIN MoveHandleRadius.cpp ----
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include <G3D/Vector3.h>
namespace RBX {
float moveHandleRadius(const G3D::Vector3& origin, const G3D::Vector3& point) {
    float distance = (origin - point).magnitude();
    float radius = 0.5f;
    if (distance > 0.5f / (3.14f / 180.0f)) radius = distance * (3.14f / 180.0f);
    return radius;
}
}
// ---- END MoveHandleRadius.cpp ----

// ---- BEGIN MegaDraggerMovement.cpp ----
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/MegaDragger.h"
#include "tool/DragUtilities.h"
#include "tool/Dragger.h"
namespace RBX {
bool MegaDragger::anyDragPartAlive() { return DragUtilities::anyPartAlive(dragParts); }
G3D::Vector3 MegaDragger::safeMoveAlongLine(const G3D::Vector3& delta) {
    G3D::Array<Primitive*> primitives;
    DragUtilities::partsToPrimitives(dragParts, primitives);
    if (primitives.size() > 0) {
        G3D::Vector3 result = Dragger::safeMoveAlongLine(primitives, delta, contactManager);
        return result;
    }
    return G3D::Vector3::zero();
}
}
// ---- END MegaDraggerMovement.cpp ----

