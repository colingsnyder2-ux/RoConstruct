// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: local class PlayerNativeMaterial::TextureProxyBase derives from RBX::TextureProxyBase; the compiler-generated
// vector deleting destructor calls the base dtor then operator delete when bit 0 of the flag is set.
#include <new>

namespace RBX {
struct TextureProxyBase {
    virtual ~TextureProxyBase();
    int pad;
};
}

namespace PlayerNativeMaterial {
struct TextureProxyBase : RBX::TextureProxyBase {
    virtual ~TextureProxyBase() {}
};
}

extern "C" void* fn_00551d50_anchor(PlayerNativeMaterial::TextureProxyBase* p)
{
    delete p;
    return p;
}
