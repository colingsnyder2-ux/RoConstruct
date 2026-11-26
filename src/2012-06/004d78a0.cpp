// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct U{int a[3]; int b;}; struct P{ void g(U*,int*); }; P* f(P* p,U* u){ p->g(u,&u->b); return p; }
