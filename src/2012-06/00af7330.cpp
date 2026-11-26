// from server: 83% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; int y; Holder() : x(0), y(0) {} };
struct ClassDesc;
ClassDesc& classDescriptor();
struct Base {
    Base(ClassDesc& cls, const char* name, int security, Functionality f, float s);
    virtual ~Base();
    char pad[0x28];
    int field; int pad2; int f1; int f2;
};
struct Derived : Base {
    Derived() : Base(classDescriptor(), "Activated", 0, Holder().f, 0.0f) { field = 0x264; f1 = 0; f2 = 1; }
    virtual ~Derived() {}
};
static Derived desc;

