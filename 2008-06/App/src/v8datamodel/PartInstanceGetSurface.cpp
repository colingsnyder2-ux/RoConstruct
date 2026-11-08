// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// >>> native-status (generated) -- do not edit >>>
// PartInstanceGetSurface | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 268fa35b | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include <G3D/AABox.h>
#include <G3D/CollisionDetection.h>

namespace RBX {
Surface* PartInstance::getSurface(const G3D::Ray& source, int& faceIndex)
{
    const G3D::CoordinateFrame& frame = primitive.getCoordinateFrame();
    G3D::Ray ray = frame.toObjectSpace(source);
    const G3D::Vector3& size = primitive.getGridSize();
    float x = size.x * 0.5f;
    float y = size.y * 0.5f;
    float z = size.z * 0.5f;
    Extents bounds(G3D::Vector3(-x, -y, -z), G3D::Vector3(x, y, z));
    const G3D::Vector3& low = bounds.min();
    const G3D::Vector3& high = bounds.max();
    G3D::Vector3 point(0.0f, 0.0f, 0.0f);
    G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox(
        ray.origin, ray.direction, G3D::AABox(low, high), point);
    for (int i = 0; i < 3; ++i) {
        if (point[i] == high[i]) {
            faceIndex = i;
            return &surfaces[static_cast<NormalId>(i)];
        }
        if (point[i] == low[i]) {
            faceIndex = i + 3;
            return &surfaces[static_cast<NormalId>(i + 3)];
        }
    }
    return NULL;
}
}
