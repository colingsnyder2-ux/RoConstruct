// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available, and the target is a compiler-generated
// adjustor thunk (this -= 16, then jump to the vector deleting destructor).
// It cannot be written by hand, so this models the layout that makes MSVC emit it:
// TypedMemItem has a primary base and a secondary polymorphic base at offset 16,
// and overrides the secondary base's virtual destructor.
// The class and base names are guesses.

namespace RBX {
namespace Stats {

struct ItemBase {            // INFERRED: primary base, 16 bytes (vptr + 12 bytes)
    virtual ~ItemBase() {}
    int pad[3];
};

struct SecondaryBase {       // INFERRED: secondary polymorphic base at offset 16
    virtual ~SecondaryBase() {}
};

class TypedMemItem : public ItemBase, public SecondaryBase {
public:
    TypedMemItem();
    virtual ~TypedMemItem();
    int value;
};

// The constructor forces emission of the vftable, which in turn emits the
// destructor thunks for the secondary base.
TypedMemItem::TypedMemItem() : value(0) {}

TypedMemItem::~TypedMemItem() {}

} // namespace Stats
} // namespace RBX
