// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/MegaDragger.h"
#include "tool/DragUtilities.h"
#include "tool/Dragger.h"
namespace RBX {
G3D::Vector3 MegaDragger::safeMoveYDrop(const G3D::Vector3& delta) {
    G3D::Array<Primitive*> primitives;
    DragUtilities::partsToPrimitives(dragParts, primitives);
    return Dragger::safeMoveYDrop(primitives, delta, contactManager);
}
G3D::Vector3 MegaDragger::safeMoveNoDrop(const G3D::Vector3& delta) {
    G3D::Array<Primitive*> primitives;
    DragUtilities::partsToPrimitives(dragParts, primitives);
    return Dragger::safeMoveNoDrop(primitives, delta, contactManager);
}
void MegaDragger::safeRotate(const G3D::Matrix3& rotation) {
    G3D::Array<Primitive*> primitives;
    DragUtilities::partsToPrimitives(dragParts, primitives);
    Dragger::safeRotate(primitives, rotation, contactManager);
}
}
