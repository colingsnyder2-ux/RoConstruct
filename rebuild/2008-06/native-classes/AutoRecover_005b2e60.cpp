// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: No Hat header was provided, so this is a minimal local reconstruction.
// The target is the compiler-generated adjustor{36} thunk for Hat's vector
// deleting destructor. In the disassembly it is "sub ecx,0x24" followed by
// "jmp Hat::`vector deleting destructor'".
// The thunk sits in the vftable of the secondary base at offset 0x24. The
// compiler emits it only in the translation unit that emits Hat's vftable.
// The base layout below is a guess. Only the 0x24 offset comes from the
// disassembly. The bases' members are only declared here, not defined, so
// this file emits as little extra code as possible.

namespace RBX {

// INFERRED: primary base occupying 0x24 bytes (vptr + 32 bytes of data)
struct HatPrimaryBase {
    int data[8];
    HatPrimaryBase();
    virtual ~HatPrimaryBase();
};

// INFERRED: secondary polymorphic base placed at offset 0x24
struct HatSecondaryBase {
    int extra;
    HatSecondaryBase();
    virtual ~HatSecondaryBase();
};

class Hat : public HatPrimaryBase, public HatSecondaryBase {
public:
    Hat();
    virtual ~Hat();
};

// INFERRED: defining the constructor and destructor here makes the compiler
// emit Hat's vftables, the vector deleting destructor and its adjustor{36} thunk.
Hat::Hat() {}
Hat::~Hat() {}

} // namespace RBX
