// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct M { void m(void*); };
struct C { char p[0x54]; M* x; void g(); void f(void* a); };
void C::f(void* a) { g(); x->m(a); }