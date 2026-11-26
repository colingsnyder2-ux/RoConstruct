// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct Desc { Desc(int offset, const char* name, const char* c2, int z, Functionality f, Sig s); ~Desc(); char pad[0x40]; };
static Desc desc(0x1d0, "PlayerRemovingLate", "player", 3, Holder().f, Sig());
