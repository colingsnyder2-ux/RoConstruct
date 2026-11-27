// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct C { void g(void*, void*); };
struct B { char p[0x38]; C* c; };
struct A { char p[0x30]; B* b; };
struct P { char p0[0xc]; A* a; char p1[0x1c-0x10]; int x1c; char p2[0x28-0x20]; int x28; void f(); };
void P::f(){ C* c = a->b->c; if (c) c->g(&x28, &x1c); }
