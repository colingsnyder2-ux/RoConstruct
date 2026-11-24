// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header is available for TextureProxy, so this is written as an
// explicit scalar-deleting-destructor body. It is not the compiler-generated one,
// so the exact codegen is unchecked.
#include <new>

namespace RBX { namespace Render { class TextureProxy; } }

extern "C" void __fastcall fn_00551db0(RBX::Render::TextureProxy* self, int unusedEdx);

extern "C" void* __fastcall fn_00551d80(RBX::Render::TextureProxy* self, int unusedEdx, unsigned int flags)
{
    fn_00551db0(self, 0);
    if (flags & 1)
        ::operator delete((void*)self);
    return self;
}
