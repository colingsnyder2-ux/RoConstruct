// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided. The target is the compiler-generated
// `vector deleting destructor'`adjustor{304}' thunk (sub ecx,0x130; jmp
// Accoutrement's vector deleting destructor). It is emitted in the vftable of a
// secondary base subobject at offset 0x130 of RBX::Accoutrement. I model that
// layout here with stand-in bases so the compiler regenerates the thunk.

namespace RBX {

// INFERRED: primary base occupying the first 0x130 bytes (vptr + data).
struct AccoutrementPrimaryBase {
    char data[0x12c];
    AccoutrementPrimaryBase() {}
    virtual ~AccoutrementPrimaryBase() {}
};

// INFERRED: secondary polymorphic base placed at offset 0x130 (304).
struct AccoutrementSecondaryBase {
    int value;
    AccoutrementSecondaryBase() : value(0) {}
    virtual ~AccoutrementSecondaryBase() {}
};

class Accoutrement : public AccoutrementPrimaryBase, public AccoutrementSecondaryBase {
public:
    Accoutrement();
    // INFERRED: destructor body lives elsewhere; only the vftable (and thus the
    // adjustor thunk) is needed in this translation unit.
    virtual ~Accoutrement();
};

Accoutrement::Accoutrement() {}

} // namespace RBX
