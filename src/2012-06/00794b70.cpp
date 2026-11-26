// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S{ virtual void v0(float); }; struct A{ char p[8]; S s; int pad; int m; }; void f(A* a,float x){ if(a->m) a->s.v0(x); }
