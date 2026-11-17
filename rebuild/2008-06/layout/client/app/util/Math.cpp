#include "util/Math.h"
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

#include "../../../../../../tools/rbxgs/Client/App/include/util/Math.h"

namespace RBX {
const G3D::Matrix3& Math::getAxisRotationMatrix(int face)
{
	static G3D::Matrix3 y = G3D::Matrix3::fromEulerAnglesXYZ(0, 0, G3D::halfPi());
	static G3D::Matrix3 z = G3D::Matrix3::fromEulerAnglesXYZ(0, G3D::halfPi(), 0);
	static G3D::Matrix3 y_neg = G3D::Matrix3(y);
	static G3D::Matrix3 z_neg = G3D::Matrix3(z);

	switch (face)
	{
	case 0:
		return G3D::Matrix3::identity();
	case 1:
		return y;
	case 2:
		return z;
	case 4:
		return y_neg;
	case 5:
		return z_neg;
	default:
		return G3D::Matrix3::identity();
	}
}
}
