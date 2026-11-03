// from server: 100% by EspClaude
// roc 2007-08 005b42f0  RBX::MotorJoint::isAligned (rbxgs v8world/MotorJoint.cpp body).
// 2007 Joint layout from the target: primitives @+8/+0xc, jointCoord0 @+0x28, jointCoord1 @+0x58;
// Primitive body @+0x64, Body cframe @+0x84 after out-of-line update (0x530100).
// roc-flags: /O2 /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z; };
class Matrix3 {
public:
    float elt[3][3];
    Vector3 getColumn(int iCol) const;
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame operator*(const CoordinateFrame& other) const;
};
}
namespace RBX {
class Math { public: static bool fuzzyEq(const G3D::Vector3& v0, const G3D::Vector3& v1, float epsilon); };
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
class Joint {
protected:
    char pad[8];
    Primitive* primitives[2];
    char pad2[0x28 - 0x10];
    G3D::CoordinateFrame jointCoord0;
    G3D::CoordinateFrame jointCoord1;
    Primitive* getPrimitive(int i) const { return primitives[i]; }
};
class MotorJoint : public Joint {
public:
    bool isAligned();
};

bool MotorJoint::isAligned()
{
    G3D::CoordinateFrame baseWorld = getPrimitive(0)->getCoordinateFrame() * jointCoord0;
    G3D::CoordinateFrame otherBaseWorld = getPrimitive(1)->getCoordinateFrame() * jointCoord1;

    if (Math::fuzzyEq(baseWorld.translation, otherBaseWorld.translation, 0.00001f))
    {
        if (Math::fuzzyEq(baseWorld.rotation.getColumn(2), otherBaseWorld.rotation.getColumn(2), 0.00001f))
            return true;
    }

    return false;
}
}
