// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available. The target is the compiler-generated
// `adjustor{16}` thunk for the vector deleting destructor of a secondary base at
// offset 16. Declaring RelativePanel with two bases and a virtual destructor
// makes the compiler emit "sub ecx,0x10 / jmp <vector deleting destructor>".
// The base layout below is a guess, not recovered from the binary.

namespace RBX {

class PanelPrimaryBase {
public:
    virtual ~PanelPrimaryBase();
    int pad0[3];   // INFERRED: 16-byte primary base (vptr + 12 bytes)
};

class PanelSecondaryBase {
public:
    virtual ~PanelSecondaryBase();
    int pad1;
};

class RelativePanel : public PanelPrimaryBase, public PanelSecondaryBase {
public:
    virtual ~RelativePanel();
};

RelativePanel::~RelativePanel()
{
}

} // namespace RBX
