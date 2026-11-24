// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target is a bare import thunk (jmp through the IAT) to
// Ogre::MemoryDataStream::tell() const. It is declared here as a dllimport
// virtual member, and the qualified call below is non-virtual, so it binds to
// the mangled import ?tell@MemoryDataStream@Ogre@@UBEIXZ.
namespace Ogre {
class MemoryDataStream {
public:
    virtual __declspec(dllimport) unsigned int tell() const;
};
}

// ecx = this passes straight through; edx is the dummy second argument.
extern "C" unsigned int __fastcall fn_0069fca8(Ogre::MemoryDataStream* self, int unusedEdx)
{
    return self->Ogre::MemoryDataStream::tell();
}
