// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// No class header was provided, so this file uses a minimal local stand-in class.
// INFERRED: BallBlockContact is the root of its own vtable chain. The
// disassembly stores only its own vtable (0x8436e8) and calls no base
// destructor before the conditional operator delete.
// INFERRED: the original body has the scalar-deleting shape: it tests only
// bit 0 and has no vector-delete branch. The ??_E name probably comes from
// identical-COMDAT folding of ??_G and ??_E in the original link.
namespace RBX {

class BallBlockContact {
public:
    virtual ~BallBlockContact();
};

// INFERRED: an empty out-of-line virtual destructor acts as the key function.
// It forces the vtable and its deleting destructor to be emitted in this TU,
// and /Ob2 inlines it so only the vtable-pointer reset remains.
BallBlockContact::~BallBlockContact()
{
}

} // namespace RBX
