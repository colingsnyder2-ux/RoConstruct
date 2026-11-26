// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V { void* a; void (*f)(void*); };
struct A { int a; int b; V* v; int c; void g(); };
void A::g(){ if (v) v->f(&c); }
