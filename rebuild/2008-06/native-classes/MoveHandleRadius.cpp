// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include <G3D/Vector3.h>
namespace RBX {
float moveHandleRadius(const G3D::Vector3& origin, const G3D::Vector3& point) {
    float distance = (origin - point).magnitude();
    float radius = 0.5f;
    if (distance > 0.5f / (3.14f / 180.0f)) radius = distance * (3.14f / 180.0f);
    return radius;
}
}
