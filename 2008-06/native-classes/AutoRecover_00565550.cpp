// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is a compiler-generated adjustor thunk (ecx -= 16, then jmp to the
// real vector deleting destructor). C++ cannot spell a thunk directly, so this file rebuilds
// enough of the class layout and instantiates the template; the compiler then emits the thunk.
// INFERRED: the layout is a 16-byte primary base (Item) followed by a secondary base
// FactoryProduct<DebugSettings> at offset 16. Both have virtual destructors.

namespace RBX {

extern const char* const sDebugSettings;

class DebugSettings;

namespace GlobalSettings {
    // INFERRED: primary base occupying bytes 0..15 (vptr plus 12 bytes of data)
    class Item {
        int data[3];
    public:
        virtual ~Item() {}
    };
}

// INFERRED: secondary base with its own vptr at offset 16
template<class T>
class FactoryProduct {
    int pad;
public:
    virtual ~FactoryProduct() {}
};

// INFERRED: the template argument is the address of the string constant, which matches
// the "$1?sDebugSettings@2@3QBDB" mangling.
template<class T, class Base, const char* const* Name>
class DescribedCreatable : public Base, public FactoryProduct<T> {
public:
    DescribedCreatable() {}
    virtual ~DescribedCreatable() {}
};

// The explicit instantiation emits the vtable, the deleting destructors and the {16} adjustor thunk.
template class DescribedCreatable<DebugSettings, GlobalSettings::Item, &sDebugSettings>;

} // namespace RBX
