// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available. The target is a compiler-generated
// adjustor thunk (this -= 0x44, then jmp to the primary vector deleting
// destructor). I reproduce it by modelling Accoutrement as having a primary base
// of size 0x44 and a secondary polymorphic base at offset 0x44, whose virtual
// destructor is overridden by Accoutrement's.

namespace RBX {

    // INFERRED: primary base, 4 byte vptr + 0x40 bytes of data = 0x44
    class AccoutrementPrimaryBase {
    public:
        char data[0x40];
        virtual ~AccoutrementPrimaryBase();
    };

    // INFERRED: secondary base located at offset 0x44 (68)
    class AccoutrementSecondaryBase {
    public:
        virtual ~AccoutrementSecondaryBase();
    };

    class Accoutrement : public AccoutrementPrimaryBase, public AccoutrementSecondaryBase {
    public:
        Accoutrement();
        virtual ~Accoutrement();
    };

    AccoutrementPrimaryBase::~AccoutrementPrimaryBase() {}
    AccoutrementSecondaryBase::~AccoutrementSecondaryBase() {}

    // Defining the constructor forces the vtable, and with it the
    // `vector deleting destructor'`adjustor{68}' thunk, to be emitted.
    Accoutrement::Accoutrement() {}
    Accoutrement::~Accoutrement() {}

}
