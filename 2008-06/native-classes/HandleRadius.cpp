// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include <AppDraw/HitTest.h>
namespace RBX {
float HitTest::distanceToHandleRadius(const G3D::Vector3& a, const G3D::Vector3& b) {
    float distance = (a - b).magnitude();
    float result = 0.5f;
    if (distance > 28.66242027282715f) result = distance * 0.017444444820284843f;
    return result;
}
}
