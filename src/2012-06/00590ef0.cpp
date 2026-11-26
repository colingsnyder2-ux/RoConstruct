// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ float* (*fn)(void*); void* o; };
float f(S* s){ return *s->fn(s->o); }
