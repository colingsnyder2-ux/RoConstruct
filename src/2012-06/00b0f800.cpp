// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base1 { int a; }; struct Base2 { int b; };
struct Owner : Base1, Base2 { void call(int); };
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct Desc { Desc(int offset, const char* name, const char* cat, int z, Functionality f, int flag); ~Desc(); char pad[0x40]; };
static Desc desc(0x84, "Equipped", "mouse", 0, Holder().f, 0);
