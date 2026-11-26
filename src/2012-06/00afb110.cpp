// from server: 82% by Xemicl
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
    char pad[0x2c];
};
struct Derived : Base { int f1; int f2; Derived() : Base(classDescriptor(), "OutfitChanged", 0, Holder().f, Sig()), f1(0x2bc), f2(0) {} virtual ~Derived() {} };
static Derived desc;
