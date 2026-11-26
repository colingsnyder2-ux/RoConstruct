// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ void x(int); }; struct M{ void y(); }; struct A:B{ char p[0x104]; M m; void x(int a){ m.y(); B::x(a);} }; void h(A*p,int a){p->x(a);}
