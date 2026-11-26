// from server: 91% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base { int b; };
struct Owner : virtual Base { void call(int); };
struct Functionality { bool a; bool b; Functionality() { b = false; a = true; } };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Desc { typedef void (Owner::*Fn)(int);
  Desc(Fn fn, const char* a, int z, Functionality fu, Desc* o); Desc(Fn fn, const char* a, int z, Functionality fu, Sig s); ~Desc(); char pad[0x40]; };
static Desc other(&Owner::call, "BreakJoints", 0, Functionality(), Sig());
static Desc desc(&Owner::call, "breakJoints", 0, Holder().f, &other);
