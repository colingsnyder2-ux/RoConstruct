// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct P{void g();}; struct S{char pad[0xf8];P*p;void h();void f(int x);}; void S::f(int x){ if(!x) p->g(); h(); }
