#undef _RELEASEASSERT
#include "util/Math.h"
#include <cmath>

namespace RBX
{
	float Math::radWrap(float rad)
	{
		if (rad >= -pi() && rad < pi())
			return rad;

		float rot = 1 / twoPi();
		float f = floor((rad + pi()) * rot);
		return rad - Math::iRound(f) * twoPi();
	}
}

namespace RBX {
G3D::Vector3 Math::closestPointOnRay(const G3D::Ray& pointOnRay, const G3D::Ray& otherRay) {
    G3D::Vector3 pa = pointOnRay.origin;
    G3D::Vector3 pPlane = otherRay.origin;
    G3D::Vector3 ua = pointOnRay.direction;
    G3D::Vector3 ub = otherRay.direction;
    G3D::Vector3 p = pPlane - pa;
    float uaub = ua.dot(ub);
    float q1 = ua.dot(p);
    float q2 = -ub.dot(p);
    float d = 1 - uaub * uaub;
    if (d > 1e-5) {
        float alpha = (q1 + uaub * q2) / d;
        return pa + alpha * ua;
    }
    return pa;
}
}

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
