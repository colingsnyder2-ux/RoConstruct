// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct I { virtual void d0(){} virtual void d1(){} virtual void d2(){} virtual bool v3(); };
struct T { int vp; bool b; char pad[0x10c-5]; I* i; int f(); };
int T::f(){ if (b) { if (!i->v3()) return 1; } return 0; }
