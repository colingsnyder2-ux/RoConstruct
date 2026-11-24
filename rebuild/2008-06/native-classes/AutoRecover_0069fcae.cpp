// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no Ogre header is available, so a minimal local declaration of the
// imported class is used. It exists only to produce the import symbol
// ?eof@MemoryDataStream@Ogre@@UBE_NXZ (a virtual const member, __thiscall).
namespace Ogre {
    class MemoryDataStream {
    public:
        __declspec(dllimport) virtual bool eof() const;
    };
}

// The target is a one-instruction import thunk: jmp dword ptr [__imp_...].
// The qualified call below is non-virtual, so it binds directly to the import.
// With /O2 the call is emitted as a tail jump, and ecx (this) passes through.
extern "C" bool __fastcall fn_0069fcae(Ogre::MemoryDataStream* self, int unusedEdx)
{
    return self->Ogre::MemoryDataStream::eof();
}
