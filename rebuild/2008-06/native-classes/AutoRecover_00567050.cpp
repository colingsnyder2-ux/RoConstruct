// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: The target is a compiler-generated adjustor thunk
// (sub ecx,16 ; jmp Selection's vector deleting destructor).
// It cannot be written as a plain function, so the class layout that makes
// the compiler emit it is reproduced instead. Selection has a primary base
// of 16 bytes and a secondary polymorphic base at offset 16 with a virtual
// destructor. The thunk is generated for that secondary base's destructor slot.
// The base names and contents below are guesses; only sizes/offsets matter.

namespace RBX {

struct SelectionPrimaryBase {
    virtual ~SelectionPrimaryBase() {}
    char pad[12];   // vptr (4) + 12 = 16 bytes, so the next base sits at offset 16
};

struct SelectionSecondaryBase {
    virtual ~SelectionSecondaryBase() {}
};

class Selection : public SelectionPrimaryBase, public SelectionSecondaryBase {
public:
    Selection();
    virtual ~Selection();
};

Selection::Selection()
{
}

// INFERRED: out-of-line destructor so the vector deleting destructor and its
// adjustor{16} thunk are emitted in this translation unit.
Selection::~Selection()
{
}

} // namespace RBX
