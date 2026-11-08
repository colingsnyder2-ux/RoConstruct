// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// MoveHandleHit | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src f8241486 | roc native-status --write
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
