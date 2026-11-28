// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: the original unit was compiled without optimization (ebp frame,
// "this" spilled to [ebp-4]), so optimization is turned off for this code.
#pragma optimize("", off)

namespace RBX {
namespace RenderNew {
// INFERRED: minimal class declaration; the real header was not provided.
// The destructor is only declared, not defined, so the compiler emits a
// call to ??1TextureProxy@RenderNew@RBX@@UAE@XZ (0x7ae3b0) from the
// compiler-generated deleting destructor (the target function).
class TextureProxy {
public:
    TextureProxy() {}
    virtual ~TextureProxy();
};
}
}

namespace {
// INFERRED: file-local helper that odr-uses the inline constructor, forcing the
// compiler to emit TextureProxy's vtable and with it the compiler-generated
// __thiscall deleting destructor (this function). Not a definition of the target.
RBX::RenderNew::TextureProxy* emitTextureProxyVtable(void* mem)
{
    return new (mem) RBX::RenderNew::TextureProxy();
}

// Keep the helper referenced so it (and the vtable) is not discarded.
RBX::RenderNew::TextureProxy* (* volatile s_keepTextureProxyVtable)(void*) = &emitTextureProxyVtable;
}
