// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct Pad { char p[0x1c]; };
struct B2 { int b; void call(int); };
struct Owner : Pad, B2 { };
struct Desc { typedef void (Owner::*Fn)(int); Desc(Fn fn, const char* a, const char* b, int z, Functionality f, Sig s); ~Desc(); char pad[0x40]; };
static Desc desc(&B2::call, "isA", "className", 0, Holder().f, Sig());
