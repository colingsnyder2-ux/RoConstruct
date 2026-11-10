#include "util/Math.h"
#include <math.h>
#pragma intrinsic(atan2)
#pragma float_control(precise, off)
namespace RBX {
extern const float nativeTiltOffset, nativeTiltScale;
extern const double nativeTiltSectorScale;
static inline double tiltAngle(const G3D::Vector3& v, float scale) {
    G3D::Vector3 scaled = v * scale;
    return atan2(-scaled.x, -scaled.z);
}
int Math::toYAxisQuadrant(const G3D::CoordinateFrame& coordinate) {
    float scale = G3D::CoordinateFrame::zLookDirection;
    return static_cast<int>(floor((tiltAngle(coordinate.rotation.getColumn(2), scale) + nativeTiltOffset) * nativeTiltScale * nativeTiltSectorScale)) % 4;
}
}
