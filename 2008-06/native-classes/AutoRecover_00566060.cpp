// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no header for RBX::Team was provided. The target is a compiler-generated
// adjustor thunk: "sub ecx,16; jmp Team::`vector deleting destructor'".
// The compiler emits it when Team overrides a virtual destructor of a secondary
// base at offset 16. The bases below are stand-ins for that layout; the real
// members are unknown.
// The bases and ~Team are only declared here. That way the only code emitted is
// the vtable-bound compiler-generated code (ctor, vector deleting dtor, thunk).
namespace RBX {

// INFERRED: primary base, 16 bytes (vptr + 12 bytes of data).
struct TeamPrimaryBase {
    int pad[3];
    TeamPrimaryBase();
    virtual ~TeamPrimaryBase();
};

// INFERRED: secondary base at offset 16 with a virtual destructor.
struct TeamSecondaryBase {
    TeamSecondaryBase();
    virtual ~TeamSecondaryBase();
};

class Team : public TeamPrimaryBase, public TeamSecondaryBase {
public:
    Team();
    virtual ~Team();   // defined elsewhere (scalar destructor)
};

// Defining the constructor makes the compiler emit the vtable, the
// vector deleting destructor and its adjustor{16} thunk.
Team::Team() {}

} // namespace RBX
