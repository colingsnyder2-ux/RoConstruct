// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Matrix3 { public: float elt[3][3]; };
class Vector3 { public: float x, y, z; };
class CoordinateFrame {
public:
    Matrix3 rotation; Vector3 translation;
    CoordinateFrame inverse() const;
    CoordinateFrame operator*(const CoordinateFrame& other) const;
};
}
namespace RBX {
class Primitive;
class Math { public: static bool orthonormalizeIfNecessary(G3D::Matrix3& m); };
class Joint {
public:
    virtual ~Joint();
    char pad[0xc];
    Primitive* prim[2];
    char pad2[0x38 - 0x18];
    G3D::CoordinateFrame jointCoord0;
    G3D::CoordinateFrame jointCoord1;
    Primitive* getPrimitive(int i) const { return prim[i]; }
    const G3D::CoordinateFrame& getJointCoord(int i) const { return i == 0 ? jointCoord0 : jointCoord1; }
};
class RigidJoint : public Joint {
public:
    G3D::CoordinateFrame getChildInParent(Primitive* parent, Primitive* child);
};
G3D::CoordinateFrame RigidJoint::getChildInParent(Primitive* parent, Primitive* child)
{
    const G3D::CoordinateFrame& c0 = getJointCoord(parent == getPrimitive(0) ? 0 : 1);
    const G3D::CoordinateFrame& c1 = getJointCoord(child == getPrimitive(0) ? 0 : 1);
    G3D::CoordinateFrame answer = c0 * c1.inverse();
    Math::orthonormalizeIfNecessary(answer.rotation);
    return answer;
}
}
