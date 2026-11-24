// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available. The target is a compiler-generated
// vtable thunk, `sub ecx,0x14 ; jmp TextDisplay::`vector deleting destructor'`.
// It exists because TextDisplay has a secondary base with a virtual destructor
// at offset 20. I reconstruct that layout so the compiler generates the thunk.
namespace RBX {

// INFERRED: primary base: vptr + 16 bytes of data, so the next base sits at offset 20
struct TextDisplayPrimaryBase {
    int data[4];
    virtual void primaryVirtual() {}
};

// INFERRED: secondary base with a virtual destructor, at offset 20 in TextDisplay
struct TextDisplaySecondaryBase {
    virtual ~TextDisplaySecondaryBase() {}
};

class TextDisplay : public TextDisplayPrimaryBase, public TextDisplaySecondaryBase {
public:
    int member;
    TextDisplay();
    virtual ~TextDisplay();   // INFERRED: defined elsewhere in the original unit
};

// Defining the constructor makes the compiler emit the vtable, the vector
// deleting destructor, and the adjustor{20} thunk for the secondary base.
TextDisplay::TextDisplay() : member(0) {}

} // namespace RBX
