// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z; };
class Matrix3 { public: float elt[3][3]; Vector3 getColumn(int iCol) const; };
class CoordinateFrame { public: Matrix3 rotation; Vector3 translation; };
}
using namespace G3D;
namespace RBX {
class Math { public: static bool fuzzyEq(const Vector3& v0, const Vector3& v1, float epsilon); };
class MotorJoint {
public:
    CoordinateFrame getJointWorldCoord(int i);
    bool isAligned();
};
bool MotorJoint::isAligned()
{
    CoordinateFrame baseWorld = getJointWorldCoord(0);
    CoordinateFrame rotorWorld = getJointWorldCoord(1);
    if (Math::fuzzyEq(baseWorld.translation, rotorWorld.translation, 1.0e-5f) &&
        Math::fuzzyEq(baseWorld.rotation.getColumn(2), rotorWorld.rotation.getColumn(2), 1.0e-5f))
        return true;
    return false;
}
}
