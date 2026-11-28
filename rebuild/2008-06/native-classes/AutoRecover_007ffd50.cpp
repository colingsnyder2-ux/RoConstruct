// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: minimal local layout; real headers not available. Member at +0x18 is
// a heap pointer freed in ~BoundProp (typed delete => null check), then the base
// dtor resets the vptr (0x80b730).
// INFERRED: dtors are throw() so no EH unwind frame is emitted (target has none).
namespace RBX {
class TextureId {};
class Sky;
namespace Reflection {
class PropDescriptor {
public:
    int pad[5];
    PropDescriptor() {}
    virtual ~PropDescriptor() throw() {}
};
template <class T, int N>
class BoundProp : public PropDescriptor {
public:
    char* storage;
    BoundProp() : storage(0) {}
    virtual ~BoundProp() throw() { delete storage; }
};
}
class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
