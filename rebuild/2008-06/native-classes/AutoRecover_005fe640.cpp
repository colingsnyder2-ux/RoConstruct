// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: The target is a compiler-generated adjustor thunk (sub ecx,14h; jmp vector-deleting-dtor).
// No class headers were available, so it is reproduced with a local mock of RBX::Tool whose
// second polymorphic base sits at offset 20. The compiler then emits
// ??_ETool@RBX@@WBE@AEPAXI@Z when it builds Tool's vtable.

namespace RBX {

// INFERRED: primary base, 4-byte vptr plus 16 bytes of data, so the next base lands at offset 20.
struct ToolPrimaryBaseMock {
    virtual ~ToolPrimaryBaseMock() {}
    int pad[4];
};

// INFERRED: secondary polymorphic base at offset 20 with a virtual destructor.
struct ToolSecondaryBaseMock {
    virtual ~ToolSecondaryBaseMock() {}
};

class Tool : public ToolPrimaryBaseMock, public ToolSecondaryBaseMock {
public:
    Tool();
    virtual ~Tool();
};

// Out-of-line so the vtables and the thunk are emitted in this translation unit.
Tool::Tool() {}
Tool::~Tool() {}

} // namespace RBX
