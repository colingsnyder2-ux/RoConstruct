// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct V { int v; };
struct Base : virtual V { void call(int); };
struct Pad { char p[0x134]; };
struct Derived : Pad, Base { void call(int); };
struct Desc { typedef void (Base::*Fn)(int); Desc(Fn fn, const char* a, int z, Functionality fu, Sig s); ~Desc(); char pad[0x40]; };
static Desc desc(static_cast<Desc::Fn>(&Derived::call), "GetStatuses", 0, Holder().f, Sig());
