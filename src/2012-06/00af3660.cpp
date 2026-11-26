// from server: 89% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() { b = false; a = true; } };
struct Holder { Functionality f; int x; Holder() : x(0) {} };
struct Other { int x; };
extern Other other;
struct Ref { Other* p; Ref(Other* x) : p(x) {} };
struct Desc { Desc(int offset, const char* name, const char* cat, Functionality f, Ref o); ~Desc(); char pad[0x40]; };
static Desc desc(0x68, "childAdded", "child", Holder().f, &other);
