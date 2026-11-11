// native-flags: /O2 /Ob1 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// DraggerPlacement | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src dbf34372 | roc native-status --write
#include "tool/Dragger.h"
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
