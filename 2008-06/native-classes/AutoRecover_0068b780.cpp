// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: no Ogre header excerpt was provided, so this is a minimal RenderQueue.
// Its real destructor is imported from rgmain, which matches the
// `call dword ptr [0x8047a0]` (??1RenderQueue@Ogre@@UAE@XZ) in the disassembly.
namespace Ogre {

class RenderQueue {
public:
    __declspec(dllimport) virtual ~RenderQueue();
};

} // namespace Ogre

// The vector deleting destructor is compiler-generated and cannot be written in
// source. Instead I write its body by hand under the fn_<addr> convention, as the
// task instructions require for this function. It runs the non-virtual destructor,
// calls operator delete if (flags & 1), and returns this.
extern "C" void* __fastcall fn_0068b780(Ogre::RenderQueue* self, int unusedEdx, unsigned int flags)
{
    self->Ogre::RenderQueue::~RenderQueue();
    if (flags & 1)
        ::operator delete(self);
    return self;
}
