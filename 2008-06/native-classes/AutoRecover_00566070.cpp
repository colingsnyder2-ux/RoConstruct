// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available. The target is the compiler-generated
// adjustor{20} thunk for Team's vector deleting destructor. Its code is just
// "sub ecx,0x14 ; jmp <real deleting dtor>". A thunk cannot be written directly
// in C++, so this file declares a minimal layout with a polymorphic secondary
// base at offset 20 (0x14) and defines Team's virtual destructor. The compiler
// then emits the thunk when it builds the vftable for that secondary base.

namespace RBX {

// INFERRED: primary base occupying 20 bytes (vptr + 16 bytes of data)
struct TeamPrimaryBase {
    virtual ~TeamPrimaryBase() {}
    int pad[4];
};

// INFERRED: secondary base with a virtual destructor, located at offset 20
struct TeamSecondaryBase {
    virtual ~TeamSecondaryBase() {}
};

class Team : public TeamPrimaryBase, public TeamSecondaryBase {
public:
    virtual ~Team();
};

Team::~Team() {}

} // namespace RBX
