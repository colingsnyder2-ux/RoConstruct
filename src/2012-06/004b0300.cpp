// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct I { virtual void d0(); virtual void d1(); virtual void v2(); };
struct G { void h(); };
struct S { char p0[4]; bool b; char pad[0x10c-5]; I* i; char p2[0x118-0x110]; G* g; void f(); };
void S::f(){ b = true; i->v2(); g->h(); }
