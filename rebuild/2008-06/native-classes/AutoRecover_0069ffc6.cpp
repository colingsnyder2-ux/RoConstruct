// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x0069ffc6 is an import thunk (jmp [IAT]) into rgmain.dll. A same-signature
// forwarder tail-calling a dllimport function compiles to the same `jmp dword ptr [imp]`.
#include <string>

namespace Ogre {
class MovableObject;
}

// INFERRED: stands in for rgmain's MovableObject::getName import slot (thiscall: this in ecx).
extern "C" __declspec(dllimport) const std::string& __fastcall rgmain_MovableObject_getName(const Ogre::MovableObject* self);

namespace Ogre {
class MovableObject {
public:
    virtual const std::string& getName(void) const;
};

const std::string& MovableObject::getName(void) const
{
    return rgmain_MovableObject_getName(this);
}
}
