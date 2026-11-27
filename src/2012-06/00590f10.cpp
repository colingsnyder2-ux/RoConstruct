// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ long long* (*fn)(int); int arg; };
long long f(S* s){ return *s->fn(s->arg); }

