// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers were available, so these are opaque local stand-ins for the Ogre types.
struct OgreQuaternion;
struct OgreRadian;
struct OgreVector3;

// Ogre::Quaternion::Quaternion(const Radian&, const Vector3&), at 0x5426f0.
// INFERRED: the callee is thiscall (ecx = quaternion) with two stack args, so it is declared fastcall with a dummy edx.
extern "C" OgreQuaternion* __fastcall fn_005426f0(OgreQuaternion* self, int unusedEdx,
                                                  const OgreRadian* angle,
                                                  const OgreVector3* axis);

// INFERRED: the target is thiscall with ecx = a Vector3* (the axis).
// It forwards (this = arg1, angle = arg3, axis = ecx) to the Quaternion constructor and returns arg1.
// arg2 is unused.
extern "C" OgreQuaternion* __fastcall fn_00541360(OgreVector3* self, int unusedEdx,
                                                  OgreQuaternion* out, int arg2,
                                                  const OgreRadian* angle)
{
    fn_005426f0(out, 0, angle, self);
    return out;
}
