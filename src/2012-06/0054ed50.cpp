// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
#include <intrin.h>
struct CB { virtual void a(); long use; long weak; };
struct SP { int* px; CB* pn; SP(const SP& o) : px(o.px), pn(o.pn) { if (pn) _InterlockedIncrement(&pn->use); } };
void f(const SP* src, SP* dst) { if (dst) new (dst) SP(*src); }
