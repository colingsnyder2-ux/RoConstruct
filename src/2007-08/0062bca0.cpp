// from server: 86% by EspClaude
// roc 2007-08 0062bca0  unit: RBX::GroupDragTool  size: 181 bytes
// RunDragger::tooCloseToCamera (rbxgs tool/RunDragger.cpp). drag @+0x14, dragPointLocal @+0x18,
// mouseRay.origin @+0x48; Primitive body @+0x64, body pv cframe @+0x84 after out-of-line update (0x530100).
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
#include <math.h>
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    const float& operator[](int i) const { return ((const float*)this)[i]; }
    float magnitude() const { return sqrtf(x*x + y*y + z*z); }
};
class Matrix3 {
public:
    float elt[3][3];
    const float* operator[](int i) const { return elt[i]; }
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    Vector3 pointToWorldSpace(const Vector3& v) const
    {
        return Vector3(
            rotation[0][0] * v[0] + rotation[0][1] * v[1] + rotation[0][2] * v[2] + translation[0],
            rotation[1][0] * v[0] + rotation[1][1] * v[1] + rotation[1][2] * v[2] + translation[1],
            rotation[2][0] * v[0] + rotation[2][1] * v[1] + rotation[2][2] * v[2] + translation[2]);
    }
};
class Ray { public: Vector3 origin; Vector3 direction; };
}
namespace RBX {
class Body {
public:
    char pad[0x84];
    G3D::CoordinateFrame cframe;
    void updatePV();
    const G3D::CoordinateFrame& getCoordinateFrame() { updatePV(); return cframe; }
};
class Primitive {
public:
    char pad[0x64];
    Body* body;
    const G3D::CoordinateFrame& getCoordinateFrame() const { return body->getCoordinateFrame(); }
};
class RunDragger {
    char pad[0x14];
    Primitive* drag;
    G3D::Vector3 dragPointLocal;
    char pad2[0x48 - 0x24];
    G3D::Ray mouseRay;
public:
    bool tooCloseToCamera();
};

bool RunDragger::tooCloseToCamera()
{
    return (drag->getCoordinateFrame().pointToWorldSpace(dragPointLocal) - mouseRay.origin).magnitude() < 6.0f;
}
}
