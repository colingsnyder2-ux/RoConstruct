// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

namespace Ogre {
// INFERRED: no class header was provided, so this is a minimal stand-in.
// The destructor is imported from rgmain, matching the call through [0x804c20].
class FileStreamDataStream {
public:
    __declspec(dllimport) virtual ~FileStreamDataStream();
};
}

// INFERRED: the compiler-generated deleting destructor can't be written as a
// class member, so it is defined here as an extern "C" __fastcall helper using
// the fn_<address> convention. Only the delete flag (bit 0) is handled, as in
// the disassembly.
extern "C" void* __fastcall fn_006700c0(Ogre::FileStreamDataStream* self, int unusedEdx, unsigned int flags)
{
    self->Ogre::FileStreamDataStream::~FileStreamDataStream();
    if (flags & 1)
        ::operator delete(self);
    return self;
}
