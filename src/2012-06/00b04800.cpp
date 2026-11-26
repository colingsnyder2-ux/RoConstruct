// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; int c; int d;
 Functionality(bool a_, bool b_, int c_, int d_) : a(a_), b(b_), c(c_), d(d_) {}
 Functionality(const Functionality& o) : a(o.a), b(o.b), c(o.c), d(o.d) {} };
struct V { int v; };
struct Owner : virtual V { char pad[0x2dc]; int x; };
struct D { D(const char* n, const char* c, int Owner::* p, Functionality f, int fl); ~D(); char pad[0x40]; };
static D desc("Duration", "Forcefield", &Owner::x, Functionality(false,false,0,0x1f), 0);
