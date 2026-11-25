// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were provided. The target is the compiler-generated
// adjustor{16} thunk (this -= 16; jmp vector deleting destructor) for the secondary-base
// vtable slot of DescribedCreatable<Tool,BackpackItem,&sTool>.
// The classes are modelled locally: a 16-byte primary base (BackpackItem) plus a
// second polymorphic base at offset 16.

namespace RBX {

extern const char* const sTool;
const char* const sTool = "Tool";

// INFERRED: primary base, 16 bytes (vptr + 3 ints)
class BackpackItem {
public:
    BackpackItem() : a(0), b(0), c(0) {}
    virtual ~BackpackItem() {}
private:
    int a, b, c;
};

// INFERRED: secondary base at offset 16 with a virtual destructor
class Local_00600180 {
public:
    virtual ~Local_00600180() {}
};

class Tool;

template<class T, class Base, const char* const* Name>
class DescribedCreatable : public Base, public Local_00600180 {
public:
    DescribedCreatable() {}
    virtual ~DescribedCreatable() {}
};

class Tool : public DescribedCreatable<Tool, BackpackItem, &sTool> {
};

template class DescribedCreatable<Tool, BackpackItem, &sTool>;

} // namespace RBX
