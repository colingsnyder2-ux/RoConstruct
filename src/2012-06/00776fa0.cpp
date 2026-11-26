// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct X { void m(int); };
struct S { char p[0x198]; X* x; void a(int); void f(int v); };
void S::f(int v) { a(v); x->m(2); }