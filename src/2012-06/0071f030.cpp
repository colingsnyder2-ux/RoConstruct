// from server: 71% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct X{int m();}; struct I{virtual void v0(); virtual X* v1(int);}; struct S{char pad[0x150]; I i; int f(int a);}; int S::f(int a){ int b=a; X* x=i.v1(b); return x->m(); }
