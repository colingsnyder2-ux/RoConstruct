// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original at 0x0069ffea is only an import thunk (jmp [IAT]) to
// rgmain!Ogre::MovableObject::isInScene. Defining that symbol with a body that
// tail-calls a dllimport function produces the same "jmp dword ptr [__imp_...]".
// The imported function is declared in a helper class and aliased to the real
// import symbol, since the real symbol cannot be both defined and dllimport here.

namespace Imp {
struct MO {
    __declspec(dllimport) virtual bool isInScene(void) const;
};
}

#pragma comment(linker, "/alternatename:__imp_?isInScene@MO@Imp@@UBE_NXZ=__imp_?isInScene@MovableObject@Ogre@@UBE_NXZ")

namespace Ogre {

class MovableObject {
public:
    virtual bool isInScene(void) const;
};

bool MovableObject::isInScene(void) const
{
    return reinterpret_cast<const Imp::MO*>(this)->Imp::MO::isInScene();
}

} // namespace Ogre
