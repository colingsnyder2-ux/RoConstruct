// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V { int v; };
struct Base : virtual V { void call(int); };
struct Pad { char p[0x134]; };
struct Derived : Pad, Base { void call(int); };
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct Sig { int v; Sig() : v(0) {} };
struct FuncDescriptor {
    typedef void (Base::*Fn)(int);
    FuncDescriptor(Fn fn, const char* name, const char* a1, int security, Functionality f, Sig s);
    ~FuncDescriptor(); char pad[0x40];
};
static FuncDescriptor desc(static_cast<FuncDescriptor::Fn>(&Derived::call), "RemoveCustomStatus", "status", 0, Holder().f, Sig());


