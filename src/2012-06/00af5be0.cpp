// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base1 { int a; }; struct Base2 { int b; };
struct Owner : Base1, Base2 { void call(int); };
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
template<class C> struct FuncDescriptor {
    typedef void (C::*Fn)(int);
    FuncDescriptor(Fn fn, const char* name, int security, Functionality f, Sig s);
    ~FuncDescriptor(); char pad[0x40];
};
static FuncDescriptor<Owner> desc(&Owner::call, "SetMessageBrickCount", 3, Holder().f, Sig());
