#include "tool/Dragger.h"
#include "util/Math.h"
#include "NativeMoveGridTrial.h"
namespace RBX {
void __cdecl transformMove(const G3D::Array<Primitive*>&, const G3D::Vector3&, G3D::Vector3&);
bool __cdecl testMove(const G3D::Array<Primitive*>&, ContactManager&);
void __cdecl subdivideMove(const G3D::Array<Primitive*>& parts, const G3D::Vector3& start, const G3D::Vector3& end, G3D::Vector3& result, ContactManager& context) {
    transformMove(parts, end, result);
    if (!testMove(parts, context)) return;
    G3D::Vector3 average = (start + end) * 0.51f;
    G3D::Vector3 midpoint = Math::toGrid(average, nativeMoveGrid());
    transformMove(parts, midpoint, result);
    bool accepted = testMove(parts, context);
    if (midpoint == end) {
        if (accepted) transformMove(parts, start, result);
    } else if (accepted) subdivideMove(parts, start, midpoint, result, context);
    else subdivideMove(parts, midpoint, end, result, context);
}
}
