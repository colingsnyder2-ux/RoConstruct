// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was available. The target is a compiler-generated
// adjustor thunk (this -= 16, then jmp to the real vector deleting destructor).
// TextDisplay is modelled as two bases, with the second at offset 16 and carrying
// a virtual destructor, so the compiler emits the thunk itself.
// INFERRED: the destructor body is defined elsewhere (declared only), so this
// file contains little beyond the vtable, the vector deleting destructor and
// the thunk.

namespace RBX {

// INFERRED: primary base, 16 bytes (vptr + 12 bytes of data)
struct TextDisplayPrimaryBase {
    int pad[3];
    virtual ~TextDisplayPrimaryBase() {}
};

// INFERRED: secondary base at offset 16 with a virtual destructor
struct TextDisplaySecondaryBase {
    virtual ~TextDisplaySecondaryBase() {}
};

class TextDisplay : public TextDisplayPrimaryBase, public TextDisplaySecondaryBase {
public:
    TextDisplay();
    virtual ~TextDisplay();
private:
    int data[4];
};

// Emits the vtable, the vector deleting destructor and its adjustor{16} thunk.
TextDisplay::TextDisplay()
{
}

} // namespace RBX
