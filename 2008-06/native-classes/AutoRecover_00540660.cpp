// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no Ogre header is visible, so the types are declared opaquely here.
namespace Ogre {
    class Radian;
    class Vector3;
    class Quaternion;
}

// INFERRED: the callee is Ogre::Quaternion::Quaternion(const Radian&, const Vector3&),
// a __thiscall constructor that returns nothing the target uses. It is declared with the
// fn_<addr> C-linkage convention.
extern "C" void __fastcall fn_005426f0(Ogre::Quaternion* self, int unusedEdx,
                                       const Ogre::Radian& angle, const Ogre::Vector3& axis);

// INFERRED: the layout of the object is a guess. The Radian is taken as the object itself
// (its address is passed). A pointer to a Vector3 sits at offset 0x10, and the code pushes
// that pointer value as the reference argument.
struct AxisAngleHolder {
    char pad[0x10];
    const Ogre::Vector3* axis;
};

extern "C" Ogre::Quaternion* __fastcall fn_00540660(AxisAngleHolder* self, int unusedEdx,
                                                    Ogre::Quaternion* out)
{
    fn_005426f0(out, 0,
                *reinterpret_cast<const Ogre::Radian*>(self),
                *self->axis);
    return out;
}
