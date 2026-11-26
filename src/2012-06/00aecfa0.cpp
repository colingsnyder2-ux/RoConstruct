// from server: 92% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base1 { int a; }; struct Base2 { int b; };
struct Owner : Base1, Base2 { void call(int); };
struct Functionality { bool a; bool b; Functionality() { b = false; a = true; } };
struct Other { int q; }; extern Other g; Other g;
struct Holder { Functionality f; int x; Holder() : x(0) {} };
template<class C> struct FuncDescriptor {
    typedef void (C::*Fn)(int);
    FuncDescriptor(Fn fn, const char* name, const char* a1, const char* a2, int security, Functionality f, Other* o);
    ~FuncDescriptor(); char pad[0x40];
};
static FuncDescriptor<Owner> desc(&Owner::call, "saveString", "key", "value", 0, Holder().f, &g);
