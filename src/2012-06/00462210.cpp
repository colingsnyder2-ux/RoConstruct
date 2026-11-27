// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B { void z(); };
struct G : B { void a(int); void b(); void f(); };
void G::f(){ a(0); b(); z(); }
