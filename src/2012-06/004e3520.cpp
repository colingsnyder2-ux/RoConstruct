// from server: 92% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct P{int a,b;}; struct A{ void f(P* p){ int z=0; volatile int *v=&z; p->a=0; *v=0; p->b=0; } }; void k(A*a,P*p){a->f(p);}
