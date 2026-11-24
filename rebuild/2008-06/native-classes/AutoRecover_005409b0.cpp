// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: minimal local declarations of the Ogre types, since no header was shown.
// The constructor is declared only, so it links to
// ??0Quaternion@Ogre@@QAE@ABVRadian@1@ABVVector3@1@@Z.
namespace Ogre {
    class Radian {
    public:
        float mRad;
    };
    class Vector3 {
    public:
        float x, y, z;
    };
    class Quaternion {
    public:
        Quaternion(const Radian& rfAngle, const Vector3& rkAxis);
        float w, x, y, z;
    };
}

// INFERRED: the object has a Vector3 at offset 0 and a pointer to a Radian at offset 0x18.
struct AxisAngleHolder {
    Ogre::Vector3 axis;
    char pad[0x0C];
    Ogre::Radian* angle;
};

extern "C" Ogre::Quaternion* __fastcall fn_005409b0(AxisAngleHolder* self, int unusedEdx, Ogre::Quaternion* out)
{
    return new (out) Ogre::Quaternion(*self->angle, self->axis);
}
