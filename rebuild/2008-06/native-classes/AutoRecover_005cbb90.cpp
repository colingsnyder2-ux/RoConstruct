// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header for RBX::ControllerService was available, so the
// layout is reconstructed locally. The target is the compiler-generated
// `vector deleting destructor'`adjustor{16}' thunk:
//     sub ecx, 0x10
//     jmp ??_EControllerService@RBX@@UAEPAXI@Z
// It exists because ControllerService has a secondary base at offset 16 with
// a virtual destructor. The compiler emits the thunk along with the vtable,
// and the vtable is emitted once the constructor is defined in this file.
// The previous build of this file produced the thunk byte-identical to the
// original (relocations masked), so the source is unchanged.

namespace RBX {

// INFERRED: the primary base is 16 bytes (vptr plus 12 bytes of data), which
// puts the secondary base at offset 16 as the adjustor{16} name implies.
struct PrimaryBase {
    PrimaryBase();
    virtual ~PrimaryBase();
    int pad[3];
};

// INFERRED: secondary base with a virtual destructor, at offset 16.
struct SecondaryBase {
    SecondaryBase();
    virtual ~SecondaryBase();
};

class ControllerService : public PrimaryBase, public SecondaryBase {
public:
    ControllerService();
    virtual ~ControllerService() {}
    int member;
};

// Defining the constructor makes the compiler emit the vtables, the vector
// deleting destructor, and the adjustor{16} thunk for the secondary vtable.
ControllerService::ControllerService()
    : member(0)
{
}

} // namespace RBX
