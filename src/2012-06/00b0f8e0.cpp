// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct ClassDesc;
ClassDesc& classDescriptor();
struct Base {
    Base(ClassDesc& cls, const char* name, int security, Functionality f, int z);
    virtual ~Base();
    char pad[0x28];
    int field;
};
struct Derived : Base {
    Derived() : Base(classDescriptor(), "Deactivated", 0, Holder().f, 0) { field = 0x88; }
    virtual ~Derived() {}
};
static Derived desc;
