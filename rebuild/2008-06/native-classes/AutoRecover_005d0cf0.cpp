// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were available. The target is a compiler-generated
// this-adjustor thunk (sub ecx,0x14; jmp BackpackItem::`vector deleting destructor').
// The compiler emits it for the secondary base's vtable slot when BackpackItem
// derives from a 20-byte polymorphic primary base followed by a second
// polymorphic base. The hierarchy below guesses that layout so the thunk is emitted.

namespace RBX {

// INFERRED: primary base occupying the first 20 bytes (vptr + 16 bytes of data)
struct BackpackItemPrimaryBase {
    virtual ~BackpackItemPrimaryBase() {}
    int pad[4];
};

// INFERRED: secondary base at offset 20 with a virtual destructor
struct BackpackItemSecondaryBase {
    virtual ~BackpackItemSecondaryBase() {}
    int data;
};

class BackpackItem : public BackpackItemPrimaryBase, public BackpackItemSecondaryBase {
public:
    BackpackItem();
    virtual ~BackpackItem();
};

// Out-of-line definitions force the vtables (and with them the adjustor thunk)
// to be emitted.
BackpackItem::BackpackItem() {}
BackpackItem::~BackpackItem() {}

} // namespace RBX
