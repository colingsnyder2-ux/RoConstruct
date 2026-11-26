// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct B{ void g(); }; struct M{ void h(); }; struct A:B{ char p[0xa0]; M m; int f(){ B::g(); m.h(); return 0; } }; int k(A*a){return a->f();}
