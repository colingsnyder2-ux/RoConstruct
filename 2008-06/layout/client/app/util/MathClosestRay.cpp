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
