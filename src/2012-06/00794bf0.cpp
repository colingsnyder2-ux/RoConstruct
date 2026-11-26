// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct I{ virtual void a(); virtual void b(int); }; struct D{int x; I i;}; void f(D* d){ if(d) d->i.b(1); }
