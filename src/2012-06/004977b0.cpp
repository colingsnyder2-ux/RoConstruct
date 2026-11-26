// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ double* (__cdecl *fn)(void*); void* arg; }; double f(S* s){ return *s->fn(s->arg); }