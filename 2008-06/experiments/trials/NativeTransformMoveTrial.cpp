#include "tool/Dragger.h"
#include "util/Math.h"
#include "NativeMoveGridTrial.h"
namespace RBX {
void __cdecl applyMove(const G3D::Array<Primitive*>&, const G3D::Vector3&);
void __cdecl transformMove(const G3D::Array<Primitive*>& parts, const G3D::Vector3& source, G3D::Vector3& previous) {
    G3D::Vector3 difference = source - previous;
    G3D::Vector3 result = Math::toGrid(difference, nativeMoveGrid());
    if (result != G3D::Vector3::zero()) { applyMove(parts, result); previous = source; }
}
}
