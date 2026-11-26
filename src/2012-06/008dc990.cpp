// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct X{ void m(int*); };
void f(X* x,int a){ x->m(&a); }
