// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void __cdecl a(void*);
struct E { void f(void*); void b(void*); };
void E::f(void* p) { a(p); b(p); }