// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/MegaDragger.h"
#include "tool/DragUtilities.h"
#include "tool/Dragger.h"
namespace RBX {
bool MegaDragger::anyDragPartAlive() { return DragUtilities::anyPartAlive(dragParts); }
G3D::Vector3 MegaDragger::safeMoveAlongLine(const G3D::Vector3& delta) {
    G3D::Array<Primitive*> primitives;
    DragUtilities::partsToPrimitives(dragParts, primitives);
    if (primitives.size() > 0) {
        G3D::Vector3 result = Dragger::safeMoveAlongLine(primitives, delta, contactManager);
        return result;
    }
    return G3D::Vector3::zero();
}
}
