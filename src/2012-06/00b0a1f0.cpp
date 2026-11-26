// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct B1 { int a; }; struct B2 { int b; }; struct Owner : B1, B2 { void call(int); };
struct Desc { typedef void (Owner::*Fn)(int); Desc(Fn fn, const char* a, const char* b, const char* c, const char* d, const char* e, const char* f, int z, Functionality fu, Sig s); ~Desc(); char pad[0x40]; };
static Desc desc(&Owner::call, "SendNotification", "title", "text", "image", "duration", "callback", 2, Holder().f, Sig());
