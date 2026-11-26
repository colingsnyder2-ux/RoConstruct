// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
#include <intrin.h>
struct S{ char p[0x1c]; long n; }; bool fn(S**); void g(S**, bool(*)(S**)); struct A{ int x; S* s; void f(){ if(_InterlockedDecrement(&s->n)==0) g(&s, fn); } }; void k(A*a){a->f();}
