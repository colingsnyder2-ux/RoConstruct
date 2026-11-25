// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layouts below are minimal stand-ins; member at +0x18 is a heap pointer deleted in ~BoundProp
namespace RBX {
struct TextureId { int a; };
namespace Reflection {
struct Descriptor {
    Descriptor();            // INFERRED: out-of-line ctor so the static needs dynamic init
    virtual ~Descriptor() {}
    int base[5];             // INFERRED: fills +4..+0x18
};
struct Slot { int x; };
template<class T, int N>
struct BoundProp : Descriptor {
    Slot* slot;              // INFERRED: owned pointer at +0x18
    BoundProp() { slot = new Slot; }  // INFERRED: forces the dynamic atexit destructor
    ~BoundProp() { delete slot; }
};
}
struct Sky {
    static Reflection::BoundProp<TextureId, 1> prop_SkyDn;
};
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyDn;
}
