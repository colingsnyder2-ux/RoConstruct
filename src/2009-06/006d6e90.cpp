// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define ISALIGNED
namespace G3D {
class Vector3 { public: float x, y, z; };
class Matrix3 { public: float elt[3][3]; };
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame operator*(const CoordinateFrame& other) const;
    CoordinateFrame inverse() const;
};
}
namespace RBX {
class Primitive {
public:
    const G3D::CoordinateFrame& getCoordinateFrame() const;
};
namespace Math {
bool fuzzyEq(const G3D::CoordinateFrame& a, const G3D::CoordinateFrame& b, float d1, float d2);
}
class Joint {
public:
    virtual ~Joint();
    virtual bool isAligned();
    virtual G3D::CoordinateFrame align(Primitive* pMove, Primitive* pStay);
    char pad[0xc];
    Primitive* prim[2];
    char pad2[0x20];
    G3D::CoordinateFrame jointCoord0;
    G3D::CoordinateFrame jointCoord1;
    Primitive* getPrimitive(int i) const { return prim[i]; }
    const G3D::CoordinateFrame& getJointCoord(int i) const { return i == 0 ? jointCoord0 : jointCoord1; }
};
class RigidJoint : public Joint {
public:
    virtual bool isAligned();
    virtual G3D::CoordinateFrame align(Primitive* pMove, Primitive* pStay);
};
#ifdef ISALIGNED
bool RigidJoint::isAligned()
{
    G3D::CoordinateFrame c0World = getPrimitive(0)->getCoordinateFrame() * jointCoord0;
    G3D::CoordinateFrame c1World = getPrimitive(1)->getCoordinateFrame() * jointCoord1;
    return Math::fuzzyEq(c0World, c1World, 0.00001f, 0.00001f);
}
#else
G3D::CoordinateFrame RigidJoint::align(Primitive* pMove, Primitive* pStay)
{
    const G3D::CoordinateFrame& c0 = getJointCoord(pMove == getPrimitive(0) ? 0 : 1);
    const G3D::CoordinateFrame& c1 = getJointCoord(pStay == getPrimitive(0) ? 0 : 1);

    G3D::CoordinateFrame jointWorld = pStay->getCoordinateFrame() * c1;
    return jointWorld * c0.inverse();
}
#endif
}
