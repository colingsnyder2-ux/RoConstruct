// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD

struct I { virtual void v(double); };
struct P { int a,b; I i; int c; int flag; };
void f(P *p, double d){ if (p->flag) p->i.v(d); }
