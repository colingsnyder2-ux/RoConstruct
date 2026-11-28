// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {
class TextureId {};
namespace Reflection {
// INFERRED: minimal Descriptor base; vptr at +0, 0x14 bytes of fields, so derived member lands at +0x18
class Descriptor {
public:
    int pad[5];
    virtual ~Descriptor() {}
};
template <class T, int N>
class BoundProp : public Descriptor {
public:
    // INFERRED: heap-owned pointer at +0x18, freed by operator delete in the dtor
    int* owned;
    BoundProp() : owned(0) {}
    // INFERRED: dtor inlined into the atexit stub (delete owned, then base vptr store)
    __forceinline virtual ~BoundProp() { if (owned) delete owned; }
};
}
class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
