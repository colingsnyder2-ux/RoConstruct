// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T{ void h(void*); };
struct S{ void g(T*); void f(T*); };
void S::f(T* a){ g(a); a->h(this); }
