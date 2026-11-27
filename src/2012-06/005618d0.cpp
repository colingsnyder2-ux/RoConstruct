// from server: 96% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A { short family; short port; int addr; bool ne(const A& o) const; };
static int eq(const A& a, const A& o) { if (a.port == o.port && a.family == 2 && a.addr == o.addr) return 1; return 0; }
bool A::ne(const A& o) const { return !eq(*this, o); }
