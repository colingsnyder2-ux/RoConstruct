// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout stand-ins for RBX::Reflection::BoundProp<TextureId,1>.
// The object has a vptr at +0 (reset to the base vtable 0x80b730 by the base
// destructor) and a heap pointer owned by a member at +0x18 that is deleted first.

namespace RBX {

class TextureId;

namespace Reflection {

// INFERRED: polymorphic base whose (empty) destructor resets the vptr last.
class PropertyDescriptorBase {
public:
    virtual void describe() {}
    ~PropertyDescriptorBase() {}
protected:
    char pad_[0x14];          // +0x04 .. +0x17
};

// INFERRED: owning holder for the pointer at +0x18.
struct OwnedPtr {
    void* p;
    ~OwnedPtr() { if (p) operator delete(p); }
};

template<class T, int N>
class BoundProp : public PropertyDescriptorBase {
public:
    OwnedPtr owned;           // +0x18
};

} // namespace Reflection

class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;

} // namespace RBX
