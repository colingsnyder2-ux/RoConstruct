#include "tool/Dragger.h"

namespace RBX {
G3D::Vector3 Dragger::safeMoveAlongLine(const G3D::Array<Primitive*>& primitives,
    const G3D::Vector3& delta, ContactManager& contactManager) {
    if (primitives.size() == 0) return G3D::Vector3::zero();
    G3D::Vector3 result(G3D::Vector3::zero());
    if (delta != G3D::Vector3::zero())
        safePlaceAlongLine(primitives, G3D::Vector3::zero(), delta, result, contactManager);
    return result;
}
}

#include "util/Math.h"

namespace RBX {
void Dragger::movePrimitivesGoal(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& goal, G3D::Vector3& previous) {
    G3D::Vector3 difference = goal - previous;
    G3D::Vector3 movement = Math::toGrid(difference, dragSnap());
    if (movement != G3D::Vector3::zero()) { movePrimitives(primitives, movement); previous = goal; }
}
void Dragger::safePlaceAlongLine(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& start,
    const G3D::Vector3& end, G3D::Vector3& result, ContactManager& manager) {
    movePrimitivesGoal(primitives, end, result);
    if (!intersectingWorldOrOthers(primitives, manager)) return;
    G3D::Vector3 average = (start + end) * 0.51f;
    G3D::Vector3 midpoint = Math::toGrid(average, dragSnap());
    movePrimitivesGoal(primitives, midpoint, result);
    bool intersecting = intersectingWorldOrOthers(primitives, manager);
    if (midpoint == end) {
        if (intersecting) movePrimitivesGoal(primitives, start, result);
    } else if (intersecting) safePlaceAlongLine(primitives, start, midpoint, result, manager);
    else safePlaceAlongLine(primitives, midpoint, end, result, manager);
}
}
