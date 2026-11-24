// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

namespace G3D {
class GImage {
public:
    // Defined elsewhere (0x0050e230, ??1GImage@G3D@@UAE@XZ).
    virtual ~GImage();
};
}

// INFERRED: no class header was available, so the compiler-generated deleting
// destructor cannot be emitted from a class definition. This is written
// explicitly as a __thiscall-compatible __fastcall helper that follows the
// disassembly: destroy the object, then delete it if bit 0 of the flag is set.
extern "C" G3D::GImage* __fastcall fn_0045acc0(G3D::GImage* self, int unusedEdx, unsigned int flags)
{
    self->G3D::GImage::~GImage();
    if (flags & 1) {
        ::operator delete(self);
    }
    return self;
}
