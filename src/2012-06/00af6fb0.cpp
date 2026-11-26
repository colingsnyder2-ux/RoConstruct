// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; int c; int d;
 Functionality(bool a_, bool b_, int c_, int d_) : a(a_), b(b_), c(c_), d(d_) {}
 Functionality(const Functionality& o) : a(o.a), b(o.b), c(o.c), d(o.d) {} };
struct Single { int get() const; }; struct B1 { int a; }; struct B2 { int b; }; struct Owner : B1, B2 { void set(int); };
struct Desc { typedef int (Single::*G)() const; typedef void (Owner::*S)(int); Desc(const char* n, const char* c, G g, S s, Functionality f, int flag); ~Desc(); char pad[0x40]; };
static Desc desc("TextureName", "Data", 0, &Owner::set, Functionality(false,false,0,4), 0);
