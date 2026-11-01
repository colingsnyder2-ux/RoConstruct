// from server: 100% by colin
// from server: 74% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast

namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    float dot(const Vector3& v) const { return x * v.x + y * v.y + z * v.z; }
};
}

namespace G3D { inline Vector3 operator*(float s,const Vector3&v){return v*s;} }
namespace RBX {
class RbxRay {
public:
    int reserved;
    G3D::Vector3 origin;
    G3D::Vector3 direction;
};

G3D::Vector3 closestPoint(const RbxRay& pointOnRay, const RbxRay& otherRay)
{
    G3D::Vector3 pa = pointOnRay.origin;
    G3D::Vector3 pPlane = otherRay.origin;
    G3D::Vector3 ua = pointOnRay.direction;
    G3D::Vector3 ub = otherRay.direction;
    G3D::Vector3 p = pPlane - pa;
    float uaub = ua.dot(ub);
    float q1 = ua.dot(p);
    float q2 = -ub.dot(p);
    float d = 1 - uaub*uaub;
    if (d > 1e-5) {
        float alpha = (q1 + uaub*q2) / d;
        return pa + alpha * ua;
    }
    else {
        return pa;
    }
}
}
