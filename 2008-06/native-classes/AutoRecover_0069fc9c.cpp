// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target is a one-instruction import thunk. It jumps to the
// imported Ogre::MemoryDataStream::skip(long), a __thiscall virtual in rgmain.
// No Ogre headers were provided, so I declare a minimal dllimport class
// locally to get the same import symbol.
namespace Ogre {
    class __declspec(dllimport) MemoryDataStream {
    public:
        virtual void skip(long count);
    };
}

// INFERRED: __thiscall helper is declared __fastcall with a dummy edx argument,
// per the naming convention in the task rules.
extern "C" void __fastcall fn_0069fc9c(Ogre::MemoryDataStream* self, int unusedEdx, long count)
{
    // Qualified call is non-virtual, so it goes straight to the import.
    self->Ogre::MemoryDataStream::skip(count);
}
