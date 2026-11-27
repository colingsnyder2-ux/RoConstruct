// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

namespace G3D {
struct Matrix3 { float m[3][3]; };
struct Vector3 { float x, y, z; };
class CoordinateFrame {
public:
    Matrix3 rotation; Vector3 translation;
    CoordinateFrame inverse() const;
    CoordinateFrame operator*(const CoordinateFrame& o) const;
};
}
namespace RBX {
class Primitive;
namespace Math { void orthonormalizeIfNecessary(G3D::Matrix3& m); }
class RigidJoint {
public:
    char pad0[0xc];
    Primitive* prim0;
    char pad1[0x24];
    G3D::CoordinateFrame jointCoord0;
    G3D::CoordinateFrame jointCoord1;
    G3D::CoordinateFrame getChildInParent(Primitive* parent, Primitive* child);
};
G3D::CoordinateFrame RigidJoint::getChildInParent(Primitive* parent, Primitive* child)
{
    const G3D::CoordinateFrame& p = (parent == prim0) ? jointCoord0 : jointCoord1;
    const G3D::CoordinateFrame& c = (child == prim0) ? jointCoord0 : jointCoord1;
    G3D::CoordinateFrame answer = p * c.inverse();
    Math::orthonormalizeIfNecessary(answer.rotation);
    return answer;
}
}
