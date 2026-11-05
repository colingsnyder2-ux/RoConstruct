#include "tool/Dragger.h"
namespace RBX {
void __cdecl subdivideMove(const G3D::Array<Primitive*>&, const G3D::Vector3&, const G3D::Vector3&, G3D::Vector3&, ContactManager&);
G3D::Vector3 Dragger::safeMoveAlongLine(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& target, ContactManager& manager) {
    if (primitives.size() == 0) return G3D::Vector3::zero();
    G3D::Vector3 result(G3D::Vector3::zero());
    if (target != G3D::Vector3::zero()) subdivideMove(primitives, G3D::Vector3::zero(), target, result, manager);
    return result;
}
}
