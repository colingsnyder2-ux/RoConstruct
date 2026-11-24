// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available. The target is the adjustor thunk
// `sub ecx,14h; jmp Selection::`vector deleting destructor'`. MSVC emits it into
// the vftable of a secondary base at offset 20 when the derived class overrides
// that base's virtual destructor. It is modeled here as a 20-byte primary base
// plus a secondary base with a virtual destructor. The real members and base
// classes of Selection are unknown.
// The out-of-line constructor makes the compiler emit the vftable and the thunk.

namespace RBX {

struct SelectionPrimaryBase {
    virtual ~SelectionPrimaryBase() {}
    char pad[16]; // INFERRED: fills the first 20 bytes (vptr + 16)
};

struct SelectionSecondaryBase {
    virtual ~SelectionSecondaryBase() {}
    int dummy;
};

class Selection : public SelectionPrimaryBase, public SelectionSecondaryBase {
public:
    Selection();
    virtual ~Selection();
    void* member; // INFERRED
};

Selection::Selection()
{
    member = 0;
}

Selection::~Selection()
{
}

} // namespace RBX
