// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers available; local stand-ins reproduce the layout.
// INFERRED: the heap pointer at +0x18 is a member object whose dtor frees it with a null check,
// so the base (Descriptor) vtable store comes after the delete.
#include <new>
namespace RBX {
class TextureId;
namespace Reflection {
class Descriptor {
public:
    virtual ~Descriptor() {}
    int pad[5];
};
struct Owned {
    char* p;
    Owned() : p(0) {}
    ~Owned() { if (p) operator delete(p); }
};
template <class T, bool B>
class BoundProp : public Descriptor {
public:
    BoundProp() {}
    ~BoundProp() {}
    Owned owned; // INFERRED: member at +0x18
};
}
class Sky {
public:
    static Reflection::BoundProp<TextureId, true> prop_SkyRt;
};
Reflection::BoundProp<TextureId, true> Sky::prop_SkyRt;
}
