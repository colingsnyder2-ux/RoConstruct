// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a one-instruction import thunk: jmp [IAT entry for
// Ogre::MemoryDataStream::close()]. It is a thiscall virtual method, mangled
// ?close@MemoryDataStream@Ogre@@UAEXXZ. ecx passes straight through, so the
// thunk is declared __fastcall with the object pointer first. No Ogre header
// was provided, so a minimal local declaration stands in for it.
namespace Ogre {
class MemoryDataStream {
public:
    __declspec(dllimport) virtual void close();
};
}

extern "C" void __fastcall fn_0069fcb4(Ogre::MemoryDataStream* self)
{
    // Qualified call: direct (non-virtual) call to the imported symbol,
    // which the optimizer emits as a tail jump through the IAT.
    self->Ogre::MemoryDataStream::close();
}
