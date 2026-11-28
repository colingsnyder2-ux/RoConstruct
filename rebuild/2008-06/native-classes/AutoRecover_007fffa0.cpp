// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the layout is guessed. The object at 0x97b7fc has a vtable at +0, and a heap pointer at +0x18 (0x97b814) that the base destructor frees. 0x80b730 is the base-class vtable that the derived destructor stores during teardown.
#include <new>

namespace RBX {
class TextureId {};

namespace Reflection {
class PropDescriptorBase {
public:
    PropDescriptorBase() : owned(0) {}
    virtual ~PropDescriptorBase() { if (owned) operator delete(owned); }
    int pad[5]; // INFERRED: fills the gap between the vtable and the pointer at +0x18
    void* owned;
};

template<class T, int N>
class BoundProp : public PropDescriptorBase {
public:
    BoundProp() {}
    virtual ~BoundProp() {}
};
}

class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
