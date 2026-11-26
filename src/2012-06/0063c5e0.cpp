// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct M { void m(int, int, int); };
struct D { char p[0x54]; M* x; };
void f(D* d, int a, int b) { d->x->m(a, b, 0); }