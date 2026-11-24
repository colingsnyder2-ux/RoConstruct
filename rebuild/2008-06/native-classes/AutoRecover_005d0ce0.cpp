// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// Compiler-generated adjustor thunk:
//   sub ecx,0x10 ; jmp <BackpackItem vector deleting destructor>
// INFERRED: primary base is 16 bytes; secondary base with virtual dtor at +16.

namespace RBX {

struct BackpackItemPrimaryBase {
    virtual ~BackpackItemPrimaryBase() {}
    int pad[3];
};

struct BackpackItemSecondaryBase {
    virtual ~BackpackItemSecondaryBase() {}
    int pad2;
};

class BackpackItem : public BackpackItemPrimaryBase, public BackpackItemSecondaryBase {
public:
    virtual ~BackpackItem();
    int data;
};

BackpackItem::~BackpackItem()
{
}

} // namespace RBX
