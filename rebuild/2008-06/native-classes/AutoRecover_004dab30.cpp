// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Ogre header was available, so a minimal stand-in class is declared here.
// INFERRED: the compiler-generated vector deleting destructor cannot be written as source,
// so it is emulated with a free function that uses the fixed fn_<addr> name.

namespace Ogre {
    class __declspec(dllimport) MemoryDataStream {
    public:
        virtual ~MemoryDataStream();
    };
}

extern "C" void* __fastcall fn_004dab30(Ogre::MemoryDataStream* self, int unusedEdx, unsigned int flags)
{
    // Non-virtual call to the imported destructor (rgmain!??1MemoryDataStream@Ogre@@UAE@XZ).
    self->Ogre::MemoryDataStream::~MemoryDataStream();
    if (flags & 1)
        ::operator delete(self);
    return self;
}
