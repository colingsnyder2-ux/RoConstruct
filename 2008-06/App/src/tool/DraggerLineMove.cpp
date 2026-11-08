// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// DraggerLineMove | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src f3bbaea5 | roc native-status --write
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
