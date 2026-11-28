// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: BoundProp<TextureId,1> derives from a polymorphic base; dtor frees owned ptr at +0x18,
// then the base vptr (0x80b730) is stored last.
namespace RBX {
class TextureId;
namespace Reflection {
class PropBase {
public:
    virtual ~PropBase() {}
    int pad[5]; // INFERRED: +4..+0x14, untouched by dtor
};
template <class T, int N>
class BoundProp : public PropBase {
public:
    virtual ~BoundProp() { if (owned) ::operator delete(owned); }
    void* owned; // +0x18
};
}
class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
