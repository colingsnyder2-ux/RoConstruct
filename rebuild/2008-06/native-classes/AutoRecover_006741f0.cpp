// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

namespace RBX {
    class AdornRbxGfx;
}

// INFERRED: no header for AdornRbxGfx was provided, so the destructor body at 0x00673a90
// is declared as an extern "C" __fastcall helper (ecx = this, edx = dummy).
extern "C" void __fastcall fn_00673a90(RBX::AdornRbxGfx* self, int unusedEdx);

// INFERRED: this is the compiler-generated scalar deleting destructor of RBX::AdornRbxGfx,
// so it is written as a plain function with the flags dword (bit 0 = also delete).
extern "C" RBX::AdornRbxGfx* __fastcall fn_006741f0(RBX::AdornRbxGfx* self, int unusedEdx, unsigned int flags)
{
    fn_00673a90(self, 0);
    if (flags & 1) {
        ::operator delete((void*)self);
    }
    return self;
}
