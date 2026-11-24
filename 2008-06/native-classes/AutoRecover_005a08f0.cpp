// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were supplied, so this uses minimal stand-in types.
// The adjustor{16} vector-deleting-destructor thunk (sub ecx,0x10; jmp real_vdtor) is emitted
// by the compiler for the secondary-base vftable slot of the explicitly instantiated class.

namespace RBX {

char* sWorkspace;

// INFERRED: primary polymorphic base occupying the first 16 bytes, with a virtual destructor
struct InstancePrimary {
    virtual ~InstancePrimary() {}
    int pad[3];
};

// INFERRED: secondary base at offset 16 that also carries a virtual destructor
struct InstanceSecondary {
    virtual ~InstanceSecondary() {}
    int pad2;
};

class RootInstance : public InstancePrimary, public InstanceSecondary {
public:
    virtual ~RootInstance() {}
};

class Workspace;

// INFERRED: the template argument is a pointer to the object (mangled $1?sWorkspace@2@3PADA),
// so the non-type parameter is a char** and not a reference.
template<class T, class Base, char** Name>
class DescribedNonCreatable : public Base {
public:
    DescribedNonCreatable() {}
    virtual ~DescribedNonCreatable() {}
};

// Explicit instantiation emits the vtables and the destructor thunks.
template class DescribedNonCreatable<Workspace, RootInstance, &sWorkspace>;

}
