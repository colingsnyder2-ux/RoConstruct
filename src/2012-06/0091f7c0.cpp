// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class CoordinateFrame {
public:
    float rotation[9];
    float translation[3];
    CoordinateFrame operator*(const CoordinateFrame& other) const;
};
}
namespace RBX {
class Math {
public:
    static bool fuzzyEq(const G3D::CoordinateFrame& a, const G3D::CoordinateFrame& b, float radTolerance, float posTolerance);
};
class Primitive {
public:
    const G3D::CoordinateFrame& getCoordinateFrame() const;
};
class Joint {
public:
    virtual ~Joint();
    virtual bool isAligned();
    Primitive* getPrimitive(int i) const { return prim[i]; }
protected:
    char pad4[8];
    Primitive* prim[2];
    char pad14[0x20];
    G3D::CoordinateFrame jointCoord0;
    G3D::CoordinateFrame jointCoord1;
};
class RigidJoint : public Joint {
public:
    virtual bool isAligned();
};
bool RigidJoint::isAligned()
{
    G3D::CoordinateFrame c0World = getPrimitive(0)->getCoordinateFrame() * jointCoord0;
    G3D::CoordinateFrame c1World = getPrimitive(1)->getCoordinateFrame() * jointCoord1;
    return Math::fuzzyEq(c0World, c1World, 0.00001f, 0.00001f);
}
}