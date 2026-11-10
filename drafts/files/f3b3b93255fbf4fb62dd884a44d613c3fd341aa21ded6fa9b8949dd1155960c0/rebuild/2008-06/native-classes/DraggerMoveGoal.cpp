// native-flags: /O2 /Ob1 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/Dragger.h"
#include "util/Math.h"
namespace RBX {
void Dragger::movePrimitivesGoal(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& goal, G3D::Vector3& previous) {
    G3D::Vector3 difference = goal - previous;
    G3D::Vector3 movement = Math::toGrid(difference, dragSnap());
    if (movement != G3D::Vector3::zero()) { movePrimitives(primitives, movement); previous = goal; }
}
}
