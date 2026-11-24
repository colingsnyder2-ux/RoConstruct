// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available, so this file uses a minimal stand-in
// hierarchy. The target is the compiler-generated `adjustor{16}' thunk: it does
// "sub ecx,16; jmp Tool::`vector deleting destructor'". MSVC emits that thunk
// into the vtable of Tool when Tool has a secondary polymorphic base at offset 16
// whose virtual destructor Tool overrides. The vtable and its thunks are only
// emitted in the translation unit where a constructor of Tool is generated, so
// the constructor is defined here explicitly.
namespace RBX {

// Primary base: vptr + 12 bytes of data, so the next base lands at offset 16.
struct ToolPrimaryBase {
    ToolPrimaryBase() {}
    virtual ~ToolPrimaryBase() {}
    int pad[3];
};

// Secondary base at offset 16 with a virtual destructor.
struct ToolSecondaryBase {
    ToolSecondaryBase() {}
    virtual ~ToolSecondaryBase() {}
    int data;
};

class Tool : public ToolPrimaryBase, public ToolSecondaryBase {
public:
    Tool();
    virtual ~Tool();
    int toolData;
};

// Defining the constructor forces emission of the vtable, including the
// `vector deleting destructor'`adjustor{16}' thunk.
Tool::Tool() : toolData(0) {}

Tool::~Tool() {}

} // namespace RBX
