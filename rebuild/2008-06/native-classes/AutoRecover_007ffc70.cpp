// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: local stand-in types; real headers unavailable. Layout from disasm:
// vtable at +0, owned pointer member at +0x1c freed by its own dtor, base dtor resets vtable.
namespace RBX {
class TextureId {};

namespace Reflection {
class PropDescriptorBase {
    char pad[24]; // INFERRED: base members up to +0x1c
public:
    PropDescriptorBase() {}
    virtual ~PropDescriptorBase() {}
};

// INFERRED: owning pointer member (string-like) whose dtor does `if (p) delete p`
struct OwnedPtr {
    char* p;
    OwnedPtr() : p(0) {}
    ~OwnedPtr() { if (p) delete p; }
};

template <class T, int B>
class BoundProp : public PropDescriptorBase {
    OwnedPtr owned; // INFERRED: heap pointer at +0x1c
public:
    BoundProp() {}
};
} // namespace Reflection

class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
} // namespace RBX
