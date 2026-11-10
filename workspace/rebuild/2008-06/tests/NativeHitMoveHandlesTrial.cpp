#include "util/Extents.h"
#include "G3D/Ray.h"
namespace RBX {
class HandleHitTest {
public:
    static bool hitTestHandleLocal(const Extents&, const G3D::CoordinateFrame&, const G3D::Ray&, G3D::Vector3&, NormalId&);
};
bool hitMoveHandles(const Extents& box, const G3D::Ray& ray, G3D::Vector3& point, NormalId& face) {
    G3D::CoordinateFrame frame(box.center());
    Extents local = Extents::fromCenterCorner(G3D::Vector3::zero(), box.size() * 0.5f);
    return HandleHitTest::hitTestHandleLocal(local, frame, ray, point, face);
}
}
