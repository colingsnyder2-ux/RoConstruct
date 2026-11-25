// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: local stand-in types; the real headers were not available.
// The atexit destructor for Sky::prop_SkyRt comes from the inlined ~BoundProp,
// which deletes the pointer member at +0x18, followed by the base-class
// vtable store.
#include <new>

namespace RBX {
struct TextureId {};

namespace Reflection {

class Descriptor {
public:
    char pad[20]; // INFERRED: fields that place the owned pointer at +0x18
    virtual ~Descriptor() {}
};

template <class T, int B>
class BoundProp : public Descriptor {
public:
    void* owned; // INFERRED: heap member at 0x974584 (object at 0x97456c)
    BoundProp() : owned(0) {}
    ~BoundProp() {
        if (owned)
            operator delete(owned);
    }
};

} // namespace Reflection

class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;

} // namespace RBX
