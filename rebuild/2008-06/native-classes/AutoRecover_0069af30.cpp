// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

namespace Ogre {
// INFERRED: no class header was provided, so this is a minimal local declaration.
// The destructor is imported from rgmain, matching the `call dword ptr [0x80499c]` in the disassembly.
class __declspec(dllimport) InstancedGeometry {
public:
    virtual ~InstancedGeometry();
};
}

// INFERRED: the compiler-generated deleting destructor cannot be written directly,
// so it is emulated as a C-linkage function following the fn_<addr> convention.
// Only bit 0 of the flags is tested, so this is the scalar-delete path.
extern "C" void* __fastcall fn_0069af30(Ogre::InstancedGeometry* self, int unusedEdx, unsigned int flags)
{
    // Qualified call so the destructor is invoked non-virtually, as the disassembly does.
    self->Ogre::InstancedGeometry::~InstancedGeometry();
    if (flags & 1) {
        ::operator delete(static_cast<void*>(self));
    }
    return self;
}
