// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// MegaDraggerMovement | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 4ada8302 | roc native-status --write
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
