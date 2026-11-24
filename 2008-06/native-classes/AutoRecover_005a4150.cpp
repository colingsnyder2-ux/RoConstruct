// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target is a compiler-generated adjustor thunk (sub ecx,0x14 / jmp to the
// primary vector deleting destructor). It cannot be written by hand without inline asm,
// so I model the class layout that makes MSVC emit it: a 0x14-byte polymorphic primary
// base plus a second polymorphic base at +0x14 with a virtual destructor.
// A constructor is defined out of line so that the vftables, and with them the
// destructor thunk, are emitted. All base names, members and bodies are guesses.

namespace RBX {
namespace Stats {

class ItemBase {
public:
    ItemBase() {}
    virtual ~ItemBase() {}
    char data[16];   // INFERRED: padding so the secondary base lands at +0x14
};

class ItemInterface {
public:
    ItemInterface() {}
    virtual ~ItemInterface() {}
};

class TypedMemItem : public ItemBase, public ItemInterface {
public:
    TypedMemItem();
    virtual ~TypedMemItem();
};

TypedMemItem::TypedMemItem() {}
TypedMemItem::~TypedMemItem() {}

} // namespace Stats
} // namespace RBX
