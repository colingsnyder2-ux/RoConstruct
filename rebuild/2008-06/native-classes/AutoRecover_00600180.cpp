// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available. The target is a compiler-generated
// vtable adjustor thunk (this -= 16; jmp to the real vector deleting destructor).
// C++ cannot spell such a thunk directly. Instead this file rebuilds a minimal
// hierarchy in which a polymorphic secondary base sits at offset 16. Explicitly
// instantiating the template then makes the compiler emit the thunk.

namespace RBX {

// INFERRED: defined elsewhere (mangled as 3QBDB: const char* const).
extern const char* const sTool;

// INFERRED: primary base of 16 bytes (vptr + 12 bytes of data).
class Instance {
public:
    int instPad[3];
    Instance() {}
    virtual ~Instance() {}
};

// INFERRED: secondary polymorphic base placed at offset 16.
class ISecondary {
public:
    int secPad;
    ISecondary() {}
    virtual ~ISecondary() {}
};

class BackpackItem : public Instance, public ISecondary {
public:
    BackpackItem() {}
    virtual ~BackpackItem() {}
};

class Tool;

// INFERRED: the non-type template argument is the address of the variable sTool
// (mangled $1?sTool@2@3QBDB).
template<class Class, class Base, const char* const* Name>
class DescribedCreatable : public Base {
public:
    DescribedCreatable() {}
    virtual ~DescribedCreatable() {}
};

template class DescribedCreatable<Tool, BackpackItem, &sTool>;

} // namespace RBX
