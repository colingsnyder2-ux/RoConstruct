// from server: 91% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B1 { int a; }; struct B2 { int b; };
struct Owner : B1, B2 { void call(int); };
struct Functionality { bool a; bool b; Functionality() { b = false; a = true; } };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct Desc { typedef void (Owner::*Fn)(int);
  Desc(Fn fn, const char* a, const char* b, int z, Functionality fu, Desc* o); ~Desc(); char pad[0x40]; };
extern Desc other;
static Desc desc(&Owner::call, "loadString", "key", 0, Holder().f, &other);
