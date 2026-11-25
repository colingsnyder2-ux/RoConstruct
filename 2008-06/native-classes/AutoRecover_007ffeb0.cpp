// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers given; layout reconstructed from disassembly only.
// Base (vptr 0x80b730, 0x14 bytes of members) then a derived member at +0x18
// whose destructor deletes a heap pointer. The derived vptr store is dead, so
// only the base vptr store survives, after the delete.
namespace RBX {
struct TextureId {};
namespace Reflection {
struct DescriptorBase {
    int pad[5]; // INFERRED: fills +4..+0x18
    virtual ~DescriptorBase() {}
};
struct OwnedPtr {
    char* p;
    ~OwnedPtr() { delete p; }
};
template <class T, int N>
struct BoundProp : DescriptorBase {
    OwnedPtr owned; // INFERRED: member at +0x18 deleted in dtor
    BoundProp() { owned.p = 0; }
    ~BoundProp() {}
};
} // namespace Reflection
struct Sky {
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
} // namespace RBX
