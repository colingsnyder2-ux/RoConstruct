// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
struct Rc { int a; long cnt; void release(); };
static __forceinline void inc(long* q, long n) { _InterlockedExchangeAdd(q, n); }
struct SP { Rc* p; SP(const SP& o) { p = o.p; if (p) inc(&p->cnt, 1); } ~SP() { if (p) p->release(); } };
struct Sub { Sub(const Sub&); int q; };
struct C { virtual void v(); int x; SP r; Sub s; C(const C& o); };
C::C(const C& o) : x(o.x), r(o.r), s(o.s) {}