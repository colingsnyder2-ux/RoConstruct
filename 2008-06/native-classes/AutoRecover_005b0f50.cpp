// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available, so the layout below is a stand-in.
// The target is a compiler-generated adjustor thunk: `sub ecx,0xc4` followed by
// `jmp` to the real vector deleting destructor.
// Plain C++ cannot write that thunk directly. This source instead recreates the
// situation in which the compiler emits it:
//   - Accoutrement has two polymorphic bases.
//   - The secondary base sits at offset 0xc4.
//   - That base's virtual-destructor slot in the Accoutrement vtable therefore
//     points at the `vector deleting destructor'`adjustor{196}' thunk.
// The real base class names and members are unknown and are guesses.

namespace RBX {

// INFERRED: primary polymorphic base, 0xc4 bytes total (vptr plus 0xc0 bytes).
class AccoutrementPrimaryBase {
public:
    virtual ~AccoutrementPrimaryBase() {}
    char pad[0xc0];
};

// INFERRED: secondary polymorphic base, placed at offset 0xc4.
class AccoutrementSecondaryBase {
public:
    virtual ~AccoutrementSecondaryBase() {}
};

class Accoutrement : public AccoutrementPrimaryBase, public AccoutrementSecondaryBase {
public:
    Accoutrement();
    virtual ~Accoutrement();
};

// Out-of-line definitions force the vtable to be emitted, and the thunk with it.
Accoutrement::Accoutrement() {}
Accoutrement::~Accoutrement() {}

} // namespace RBX
