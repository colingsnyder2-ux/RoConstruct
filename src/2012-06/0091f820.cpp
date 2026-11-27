// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace G3D {
class CoordinateFrame {
public:
    float m[12];
    CoordinateFrame operator*(const CoordinateFrame& other) const;
    CoordinateFrame inverse() const;
};
}
namespace RBX {
class Primitive {
public:
    const G3D::CoordinateFrame& getCoordinateFrame() const;
};
class RigidJoint {
public:
    int pad[2];
    Primitive* prim[2];
    char pad2[0x20];
    G3D::CoordinateFrame jointCoord0;
    G3D::CoordinateFrame jointCoord1;
    Primitive* getPrimitive(int i) const { return prim[i]; }
    const G3D::CoordinateFrame& getJointCoord(int i) const { return i == 0 ? jointCoord0 : jointCoord1; }
    virtual G3D::CoordinateFrame align(Primitive* pMove, Primitive* pStay);
};
G3D::CoordinateFrame RigidJoint::align(Primitive* pMove, Primitive* pStay)
{
    const G3D::CoordinateFrame& c0 = getJointCoord(pMove == getPrimitive(0) ? 0 : 1);
    const G3D::CoordinateFrame& c1 = getJointCoord(pStay == getPrimitive(0) ? 0 : 1);
    G3D::CoordinateFrame jointWorld = pStay->getCoordinateFrame() * c1;
    return jointWorld * c0.inverse();
}
}