// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
namespace Ogre {
class Matrix3;
class Quaternion {
public:
    inline Quaternion(float fW = 1.0f, float fX = 0.0f, float fY = 0.0f, float fZ = 0.0f)
        : w(fW), x(fX), y(fY), z(fZ) {}
    __declspec(dllimport) void FromRotationMatrix(const Matrix3& kRot);
    float w, x, y, z;
};
}
Ogre::Quaternion toQuaternion(const Ogre::Matrix3& m)
{
    Ogre::Quaternion q;
    q.FromRotationMatrix(m);
    return q;
}
