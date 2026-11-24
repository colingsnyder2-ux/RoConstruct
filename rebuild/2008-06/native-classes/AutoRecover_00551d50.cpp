// native-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the class layout is unknown. The original is a compiler-generated
// vector deleting destructor, which plain C++ cannot spell out directly. This
// version therefore writes the same logic by hand: it calls the non-virtual
// base destructor (0x551cf0), then calls operator delete if bit 0 of the flag
// argument is set.
#include <new>

namespace RBX {
class TextureProxyBase {
public:
    virtual ~TextureProxyBase();
};
}

namespace PlayerNativeMaterial {
class TextureProxyBase : public RBX::TextureProxyBase {
};
}

extern "C" void* __fastcall fn_00551d50(PlayerNativeMaterial::TextureProxyBase* self, int unusedEdx, unsigned int flags)
{
    // INFERRED: explicit non-virtual call to the destructor at 0x551cf0
    self->RBX::TextureProxyBase::~TextureProxyBase();
    if (flags & 1)
        ::operator delete(self);
    return self;
}
