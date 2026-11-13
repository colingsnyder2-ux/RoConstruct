// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// HandleRadius | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 731688a5 | roc native-status --write
#include <AppDraw/HitTest.h>
namespace RBX {
float HitTest::distanceToHandleRadius(const G3D::Vector3& a, const G3D::Vector3& b) {
    float distance = (a - b).magnitude();
    float result = 0.5f;
    if (distance > 28.66242027282715f) result = distance * 0.017444444820284843f;
    return result;
}
}
