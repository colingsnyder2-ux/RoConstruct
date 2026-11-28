// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: minimal local types; layout from disassembly (member pointer at +0x1c deleted, then base vtable restored).
namespace RBX {
class TextureId {};
namespace Reflection {
struct PropDescriptor {
    virtual ~PropDescriptor() {}
    int pad[6]; // INFERRED: fields up to +0x1c
};
template <class T, int B>
struct BoundProp : PropDescriptor {
    void* p; // INFERRED: owned pointer at +0x1c
    BoundProp() : p(0) {}
    ~BoundProp() { delete (char*)p; }
};
}
struct Sky {
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
