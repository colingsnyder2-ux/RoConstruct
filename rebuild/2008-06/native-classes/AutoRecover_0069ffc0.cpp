// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is a linker import thunk (jmp [0x8044d8]) into rgmain.dll's Ogre.
// No native Ogre header was supplied, so this declares a minimal local class.
namespace Ogre {
class SceneManager;
class MovableObject {
public:
    virtual SceneManager* _getManager() const;
};
}

// INFERRED: one-arg __fastcall puts this in ecx only (edx untouched), so the tail call is a bare jmp.
extern "C" __declspec(dllimport) Ogre::SceneManager* __fastcall
    fn_0069ffc0(const Ogre::MovableObject* self);

Ogre::SceneManager* Ogre::MovableObject::_getManager() const
{
    return fn_0069ffc0(this);
}
