// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; int y; Holder() : x(0), y(0) {} };
struct ClassDesc;
ClassDesc& classDescriptor();
struct Base {
    Base(ClassDesc& cls, const char* name, int security, Functionality f, Sig s);
    virtual ~Base();
    char pad[0x28];
    int field; int pad2; int f1; int f2;
};
struct Derived : Base {
    Derived() : Base(classDescriptor(), "ConnectDiedSignalBackend", 5, Holder().f, Sig()) { field = 0x138; f1 = 0; f2 = 0; }
    virtual ~Derived() {}
};
static Derived desc;

