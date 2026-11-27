// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct C { char pad[0x88]; bool flag; };
struct B { C* m2(); };
struct A { B* m1(); };
A* g1(void* a, int k);
bool f(void* a) { A* p = g1(a, 1); if (p) { B* q = p->m1(); if (q) { C* r = q->m2(); if (r) return r->flag; } } return true; }
