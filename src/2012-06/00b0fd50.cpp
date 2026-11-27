// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Holder { Functionality f; int x; int y; Holder() : x(0) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Base { Base(int, const char*, const char*, const char*, const char*, int, Functionality, Sig); virtual ~Base(); char pad[48]; };
struct Derived : Base { int m0; int m1; Derived(int a0, const char* a1, const char* a2, const char* a3, const char* a4, int z, Functionality f, Sig s) : Base(a0, a1, a2, a3, a4, z, f, s), m0(1), m1(0) {} virtual ~Derived() {} };
static Derived desc(0xe0, "AdjustAnimation", "gameTime", "weight", "fadeTime", 0, Holder().f, Sig());
