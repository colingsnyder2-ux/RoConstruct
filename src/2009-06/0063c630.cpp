// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator*(float f) const { return Vector3(x * f, y * f, z * f); }
};
class Matrix3 {
public:
    float elt[3][3];
    Vector3 getColumn(int iCol) const;
};
class CoordinateFrame {
public:
    static const float zLookDirection;
    Matrix3 rotation;
    Vector3 translation;
    inline Vector3 lookVector() const { return rotation.getColumn(2) * zLookDirection; }
};
}
namespace RBX {
class Accoutrement {
public:
    char pad[0xc4];
    G3D::CoordinateFrame attachmentPoint;
    const G3D::Vector3 getAttachmentForward() const;
};
const G3D::Vector3 Accoutrement::getAttachmentForward() const
{
    return attachmentPoint.lookVector();
}
}
