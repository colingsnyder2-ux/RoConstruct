// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were provided, so the real RBX::ForceField hierarchy is unknown.
// The target is a compiler-generated adjustor thunk (sub ecx,16; jmp to the real vector
// deleting destructor at 0x62d8d0). It cannot be written directly, so a class with a
// secondary polymorphic base at offset 16 and an out-of-line virtual destructor is
// modelled; the compiler then emits ??_EForceField@RBX@@WBA@AEPAXI@Z.

namespace RBX {

// INFERRED: primary base, 16 bytes (vptr + 12 bytes of data)
struct ForceFieldPrimaryBase {
    ForceFieldPrimaryBase() {}
    virtual ~ForceFieldPrimaryBase() {}
    int pad[3];
};

// INFERRED: secondary base located at offset 16
struct ForceFieldSecondaryBase {
    ForceFieldSecondaryBase() {}
    virtual ~ForceFieldSecondaryBase() {}
};

class ForceField : public ForceFieldPrimaryBase, public ForceFieldSecondaryBase {
public:
    ForceField();
    virtual ~ForceField();
};

// INFERRED: out-of-line constructor so the vtable (and its adjustor thunks) is emitted here
ForceField::ForceField()
{
}

ForceField::~ForceField()
{
}

} // namespace RBX
