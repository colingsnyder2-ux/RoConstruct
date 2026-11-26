// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base1 { int a; }; struct Base2 { int b; };
struct Owner : Base1, Base2 { void call(int); };
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct In { int v; In() : v(0) {} }; struct Obj { In a; In b; Obj(const Obj&); Obj() {} ~Obj(); };
template<class C> struct FuncDescriptor {
    typedef void (C::*Fn)(int);
    FuncDescriptor(Fn fn, const char* name, const char* a1, const char* a2, Obj s, const char* line, int z, int y, Functionality f, Sig g);
    ~FuncDescriptor(); char pad[0x40];
};
static FuncDescriptor<Owner> desc(&Owner::call, "Checkpoint", "text", "source", Obj(), "line", 0, 0, Holder().f, Sig());

