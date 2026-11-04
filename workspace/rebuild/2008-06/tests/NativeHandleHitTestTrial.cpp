#include "util/Extents.h"
#include "util/NormalId.h"
#include <AppDraw/HitTest.h>
#include <G3D/Ray.h>
#include <G3D/Sphere.h>
#include <G3D/CollisionDetection.h>
namespace RBX {
class HandleHitTest {
public:
    static bool hitTestHandleLocal(const Extents&, const G3D::CoordinateFrame&, const G3D::Ray&, G3D::Vector3&, NormalId&);
};
bool HandleHitTest::hitTestHandleLocal(const Extents& box, const G3D::CoordinateFrame& frame, const G3D::Ray& ray, G3D::Vector3& result, NormalId& face) {
    for (int i = 0; i < 6; ++i) {
        G3D::Vector3 center = box.faceCenter((NormalId)i);
        center += normalIdToVector3((NormalId)i) * 3.f;
        G3D::Vector3 point = frame.pointToWorldSpace(center);
        float radius = HitTest::distanceToHandleRadius(ray.origin, point);
        G3D::Vector3 hit;
        bool found = G3D::CollisionDetection::collisionTimeForMovingPointFixedSphere(ray.origin, ray.direction, G3D::Sphere(point, radius), hit) != G3D::inf();
        if (found) { face = (NormalId)i; result = point; return true; }
    }
    return false;
}
}
