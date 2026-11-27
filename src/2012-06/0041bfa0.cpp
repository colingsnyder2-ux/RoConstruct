// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
#include <intrin.h>
struct CB { virtual void a(); long use; long weak; };
struct SP { int* px; CB* pn; SP() {} SP(const SP& o) : px(o.px), pn(o.pn) { if (pn) _InterlockedIncrement(&pn->use); } };
extern char tinfo;
void fa(); void fb();
struct Desc { const void* t; void (*f1)(); void (*f2)(); Desc() : t(&tinfo), f2(fb), f1(fa) {} ~Desc(); };
struct X { const Desc* d; SP sp; X(const SP& o); };
X::X(const SP& o) : d(0) { ::new((void*)&sp) SP(o); static Desc dd; d = &dd; }
