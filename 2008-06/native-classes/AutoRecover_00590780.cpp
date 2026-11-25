// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were provided, so the class layout below is a minimal stand-in.
// The thunk "sub ecx,0x14; jmp <vector deleting dtor>" is compiler-generated: it is the
// vtable entry for a secondary base subobject at offset 20 that has a virtual destructor.
// The class layout is reconstructed so that the compiler emits exactly that adjustor thunk.
// The mangled name requires RootInstance and NonFactoryProduct to be declared as 'class' (V prefix).

namespace RBX {

// Declaration only: defined as char sWorkspace[] = "Workspace" in NativeWorkspaceClassNames.cpp (odrdiff: 4 vs 47 B).
extern char* sWorkspace;

// INFERRED: primary base of 20 bytes (vptr + 16 bytes of data) placing the second base at +20
class InstanceBase {
public:
    int data[4];
    InstanceBase() {}
    virtual ~InstanceBase() {}
    virtual void primaryVirtual() {}
};

// INFERRED: secondary polymorphic base with a virtual destructor
class RootInstance {
public:
    int rootData;
    RootInstance() : rootData(0) {}
    virtual ~RootInstance() {}
};

template<class Product, char** Name>
class NonFactoryProduct : public InstanceBase, public Product {
public:
    NonFactoryProduct() {}
    virtual ~NonFactoryProduct() {}
};

// Explicit instantiation emits the vtables, the vector deleting destructor, and the
// `adjustor{20}' thunk for the RootInstance subobject.
template class NonFactoryProduct<RootInstance, &sWorkspace>;

}
