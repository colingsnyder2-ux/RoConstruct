// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct Base { int b; }; struct Owner : virtual Base { void call(int); };
struct Desc { typedef void (Owner::*Fn)(int); Desc(Fn fn, const char* a, const char* b, const char* c, const char* d, int y, int z, Functionality fu, Sig s); ~Desc(); char pad[0x40]; };
static Desc desc(&Owner::call, "FindPartsInRegion3WithIgnoreList", "region", "ignoreDescendentsTable", "maxParts", 0x14, 0, Holder().f, Sig());
