// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O1 /Ob2 /Oy /GS- /EHsc /MD
struct R{void h();}; struct P{int a; int b;}; struct M{R* g(P*,int*);}; struct S{char pad[0x18]; M m; void f(P*);}; void S::f(P* p){ m.g(p,&p->b)->h(); }
