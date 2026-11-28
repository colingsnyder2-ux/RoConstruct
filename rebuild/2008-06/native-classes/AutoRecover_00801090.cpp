// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were supplied. These are minimal local stand-ins whose layout comes from the disassembly.
// The vtable pointer is at +0 and the owned pointer at +0x18, which is 0x97d5a4 minus 0x97d58c.
// The store of 0x80b730 is the base-class vtable written by the base destructor.
// INFERRED: operator delete is declared throw() so no EH frame is built (the target has none).
void __cdecl operator delete(void*) throw();

namespace RBX {
class TextureId {};

namespace Reflection {
class Descriptor {
public:
    Descriptor() : pad0(0), pad1(0), pad2(0), pad3(0), pad4(0) {}
    virtual ~Descriptor() {}
    virtual void anchor() {}
    int pad0, pad1, pad2, pad3, pad4; // INFERRED: fills offsets 4..0x17
};

template <class T, int B>
class BoundProp : public Descriptor {
public:
    BoundProp() : owned(new char[4]) {}
    ~BoundProp() { delete owned; } // INFERRED: member at +0x18 freed with operator delete
    char* owned;
};
} // namespace Reflection

class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};

Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
} // namespace RBX
