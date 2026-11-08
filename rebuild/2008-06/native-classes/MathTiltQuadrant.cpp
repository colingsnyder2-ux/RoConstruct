// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "util/Math.h"
#include <math.h>
#pragma intrinsic(atan2)
#pragma float_control(precise, off)

namespace RBX {
int Math::toYAxisQuadrant(const G3D::CoordinateFrame& coordinate)
{
    G3D::Vector3 look = coordinate.rotation.getColumn(2) * G3D::CoordinateFrame::zLookDirection;
    return static_cast<int>(floor((atan2(-look.x, -look.z) + 7.0685834884643555f)
        * 4.0f * 0.15915495087284556)) % 4;
}
}
