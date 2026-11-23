// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: no header excerpt was provided, so StandardOut is declared minimally here.
// The destructor is defined elsewhere (0x00569590, ??1StandardOut@RBX@@UAE@XZ).
namespace RBX {
    class StandardOut {
    public:
        virtual ~StandardOut();
    };
}

// INFERRED: this is the scalar deleting destructor (vector deleting dtor with flag bit 0 = delete).
extern "C" RBX::StandardOut* __fastcall fn_005696d0(RBX::StandardOut* self, int unusedEdx, unsigned int flags)
{
    // Non-virtual call to the real destructor body.
    self->RBX::StandardOut::~StandardOut();
    if (flags & 1) {
        ::operator delete(static_cast<void*>(self));
    }
    return self;
}
