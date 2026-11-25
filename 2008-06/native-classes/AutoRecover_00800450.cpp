// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: static-destructor for BoundProp<TextureId,1> Sky::prop_SkyRt; the
// dtor frees an owned pointer (operator delete) and resets the vtable.
// Real class header not available, so a minimal local analog is used.
namespace RBX {
namespace Reflection {
struct PropVTable {};
extern PropVTable g_vtbl_80b730; // INFERRED: base-class vtable at 0x80b730
template <class T, int N>
struct BoundProp {
    void* vtbl;   // 0x97c094
    char pad[0x14]; // INFERRED: padding up to the owned pointer
    void* owned;  // 0x97c0ac
    ~BoundProp() {
        if (owned)
            ::operator delete(owned);
        vtbl = &g_vtbl_80b730;
    }
};
}
struct TextureId {};
struct Sky {
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
