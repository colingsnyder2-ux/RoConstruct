// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x0069ff6c is only a linker import thunk (jmp dword ptr [IAT]) that
// forwards to rgmain's export of Ogre::MovableObject::getCastShadows. No class
// header was supplied, so the import is modeled as a __thiscall dllimport member of a
// helper class; the forwarding body should compile to a tail-call jmp through the IAT.

namespace Ogre {

// INFERRED: stand-in for the imported export; same this-call signature (ecx only).
struct MovableObjectImport {
    __declspec(dllimport) bool getCastShadowsImp(void) const;
};

class MovableObject {
public:
    virtual bool getCastShadows(void) const;
};

bool MovableObject::getCastShadows(void) const
{
    return reinterpret_cast<const MovableObjectImport*>(this)->getCastShadowsImp();
}

} // namespace Ogre
