// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(true) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct Owner { void call(int); };
struct Desc { Desc(const char* n, int o, const char* a, const char* b, int z, Functionality f, Sig s); ~Desc(); char pad[0x40]; };
static Desc desc("EventFilter", 0x1fd0, "firingItem", "event", 1, Holder().f, Sig());
