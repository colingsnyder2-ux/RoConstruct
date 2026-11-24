// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// This function is a compiler-generated adjustor thunk: `sub ecx,16; jmp <vector deleting dtor>`.
// MSVC emits the vftable (and the thunks it references) in the constructor,
// so the class needs an out-of-line constructor as well as an out-of-line destructor.
// No real headers were available, so the layout below uses stand-in base classes.
// INFERRED: Accoutrement has a primary polymorphic base of 16 bytes and a
// secondary polymorphic base at offset 16 with a virtual destructor.

namespace RBX {

    struct AccoutrementPrimaryBase {
        int pad[3];
        AccoutrementPrimaryBase();
        virtual ~AccoutrementPrimaryBase();
    };

    struct AccoutrementSecondaryBase {
        AccoutrementSecondaryBase();
        virtual ~AccoutrementSecondaryBase();
    };

    class Accoutrement : public AccoutrementPrimaryBase, public AccoutrementSecondaryBase {
    public:
        int data;
        Accoutrement();
        virtual ~Accoutrement();
    };

    Accoutrement::Accoutrement()
        : data(0)
    {
    }

    Accoutrement::~Accoutrement()
    {
    }

}
