// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base1 { int a; }; struct Base2 { int b; };
struct Owner : Base1, Base2 { void call(int); };
struct Functionality { bool a; bool b; Functionality() : a(false), b(true) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct Desc { Desc(int offset, const char* name, const char* cat, const char* c2, const char* c3, const char* c4, int z, Functionality f, Sig s); ~Desc(); char pad[0x40]; };
static Desc desc(0xb78, "DataCustomFiltered", "peer", "result", "instance", "member", 3, Holder().f, Sig());

