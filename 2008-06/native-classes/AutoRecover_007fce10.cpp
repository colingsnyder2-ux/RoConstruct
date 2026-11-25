// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the original headers were not available, so the types below are minimal
// stand-ins that only reproduce the mangled symbol name and the layout the destructor
// touches: the vptr at +0, a 0x18-byte block after it, and the owned pointer at +0x1c.
// Both destructors are __forceinline so the atexit thunk gets the body inlined
// instead of a jump to an out-of-line destructor.
namespace RBX {
class TextureId {};
namespace Reflection {
struct DescriptorBase {
    virtual __forceinline ~DescriptorBase() {}
    char pad[0x18];
};
template <class T, bool B>
class BoundProp : public DescriptorBase {
public:
    char* ptr;
    BoundProp() : ptr(0) {}
    __forceinline ~BoundProp() {
        if (ptr)
            delete ptr;
    }
};
}
class Sky {
public:
    static Reflection::BoundProp<TextureId, true> prop_SkyRt;
};
Reflection::BoundProp<TextureId, true> Sky::prop_SkyRt;
}
