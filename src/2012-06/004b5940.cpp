// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string.h>
struct IU { virtual long __stdcall Q(); virtual unsigned long __stdcall AddRef(); };
struct T { int pad[15]; IU* pu; unsigned n; void* p; };
extern "C" __declspec(dllimport) void* __stdcall CoTaskMemAlloc(unsigned);
long __stdcall cp(T* d, const T* s) { *d = *s; if (s->n) { d->p = CoTaskMemAlloc(s->n); if (!d->p) { d->n = 0; return 0x8007000eL; } memcpy(d->p, s->p, d->n); } if (d->pu) d->pu->AddRef(); return 0; }
