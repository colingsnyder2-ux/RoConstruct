// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
struct SP { long* p; };
struct X { char pad[0x10]; long* p; SP* f(SP* out); };
SP* X::f(SP* out) { volatile int z = 0; long* q = p; out->p = q; if (q) _InterlockedExchangeAdd(q, 1); return out; }