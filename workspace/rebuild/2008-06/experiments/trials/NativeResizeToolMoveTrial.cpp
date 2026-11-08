#include "NativeResizeToolTrial.h"
#include "util/Math.h"
#include <cmath>
namespace RBX {
static inline G3D::Vector3 directNormal(NormalId id, const G3D::CoordinateFrame& f) {
    const G3D::Matrix3& m = f.rotation;
    int c = id % 3;
    int sign = 1 - (id / 3) * 2;
    return sign * G3D::Vector3(m[0][c], m[1][c], m[2][c]);
}
void ResizeTool::onMouseMove(const UIEvent& event) {
    if (targetPV.expired()) return;
    G3D::Vector3 direction = directNormal(localNormalId, targetPV.lock()->getLocation());
    G3D::Ray axis = G3D::Ray::fromOriginAndDirection(hitPointGrid, direction);
    G3D::Ray mouse = getUnitMouseRay(event);
    G3D::Vector3 hit = Math::closestPointOnRay(axis, mouse);
    float dot = (hit - hitPointGrid).dot(axis.direction);
    float delta = dot - moveAxis;
    if (delta > 1.0f) {
        int steps = G3D::iRound((float)std::floor(delta));
        moveAxis += steps;
        capturedDrag(steps);
    }
    if (delta < -1.0f) {
        int steps = -G3D::iRound((float)std::floor(-delta));
        moveAxis += steps;
        capturedDrag(steps);
    }
}
}
