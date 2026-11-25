// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Sky.h / BoundProp header available; header-free analog.
// INFERRED: the target frees a heap pointer at +0x18 with operator delete, then stores the base vtable (0x80b730). That matches an inlined member dtor followed by an inlined base dtor.
// INFERRED: the owned pointer is a member object with its own inline dtor. The derived class has no explicit dtor, so the compiler inlines the whole chain into the atexit stub.
namespace RBX {
class TextureId {};
namespace Reflection {
class PropDescriptorBase {
public:
    int f04, f08, f0c, f10, f14;
    PropDescriptorBase();
    virtual ~PropDescriptorBase() {}
};
struct OwnedPtr {
    void* p;
    ~OwnedPtr() { if (p) delete (char*)p; }
};
template <class T, int N>
class BoundProp : public PropDescriptorBase {
public:
    OwnedPtr owned;
    BoundProp();
};
}
class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
