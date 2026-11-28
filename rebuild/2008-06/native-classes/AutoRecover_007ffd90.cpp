// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layouts below are minimal stand-ins; the real headers are not available.
// INFERRED: original dtor frees the member with an explicit null check before operator delete
// (the binary tests eax and calls ??3 directly), then base dtor resets the vptr.
#include <new>
namespace RBX {
class TextureId {};
namespace Reflection {
class Descriptor {
    int pad[6]; // INFERRED: fills offsets 0x04..0x1b
public:
    virtual ~Descriptor() throw() {}
    virtual void f1();
};
template <class T, int B>
class BoundProp : public Descriptor {
public:
    void* owned; // INFERRED: freed in dtor, at +0x1c
    ~BoundProp() throw() {
        if (owned)
            ::operator delete(owned);
    }
    BoundProp();
};
} // namespace Reflection

class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
} // namespace RBX
