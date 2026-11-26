// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
struct R{ virtual void v0(); virtual void v1(); virtual void v2(); int pad; long u; };
struct S{ char p[0xc]; R* r; void f(); };
void S::f(){ R* p = r; if(p){ if(_InterlockedDecrement(&p->u)==0) p->v2(); } }
