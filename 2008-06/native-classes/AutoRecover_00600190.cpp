// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {

// INFERRED: no class headers were available, so these are minimal stand-ins.
// The target is the compiler-generated thunk
// `DescribedCreatable<Tool,BackpackItem,&sTool>::`vector deleting destructor'`adjustor{20}'.
// It does `sub ecx,14h` and jumps to the primary vector deleting destructor.

// INFERRED: the primary base is 20 bytes (vfptr + 16 bytes) with no virtual destructor.
class Local_00600190_Base0 {
public:
    virtual void describe() {}
    int pad[4];
};

// INFERRED: the secondary base at offset 20 owns the virtual destructor.
class Local_00600190_Base1 {
public:
    virtual ~Local_00600190_Base1() {}
    int x;
};

// INFERRED: stand-in for BackpackItem.
class BackpackItem : public Local_00600190_Base0, public Local_00600190_Base1 {
public:
    BackpackItem() : y(0) {}
    virtual ~BackpackItem() {}
    int y;
};

// INFERRED: stand-in for Tool.
class Tool : public BackpackItem {
public:
    Tool() {}
    virtual ~Tool() {}
};

extern const char* const sTool;
const char* const sTool = "Tool";

template<class T, class Base, const char* const* Name>
class DescribedCreatable : public Base {
public:
    DescribedCreatable() {}
    virtual ~DescribedCreatable() {}
};

// Explicit instantiation emits the vftables and the adjustor{20} thunk.
template class DescribedCreatable<Tool, BackpackItem, &sTool>;

}
