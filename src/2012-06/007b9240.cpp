// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct I { virtual void d0(); virtual void d1(); virtual void d2(); virtual void v3(); };
struct G { char pad[0x7c]; bool f; char p2[0x10c-0x7d]; I* i; void set(bool v); };

void G::set(bool v){ if (v != f) { f = v; i->v3(); } }
