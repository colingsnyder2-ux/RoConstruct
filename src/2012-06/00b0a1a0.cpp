// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct ClassDesc;
ClassDesc& classDescriptor();
struct Base {
    Base(ClassDesc& cls, const char* name, int security, Functionality f, Sig s);
    virtual ~Base();
    char pad[0x28];
    int field;
};
struct Derived : Base {
    Derived() : Base(classDescriptor(), "EscapeKeyPressed", 2, Holder().f, Sig()) { field = 0x8c; }
    virtual ~Derived() {}
};
static Derived desc;

