// from server: 93% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
struct Rc { int a, b; long cnt; };
struct String { char d[0x1c]; __declspec(dllimport) String(const String&); };
struct Inner { String s; int x; Rc* r1; int y; Rc* r2;
  __forceinline Inner(const Inner& o) : s(o.s) {
    x = o.x; r1 = o.r1; if (r1) _InterlockedExchangeAdd(&r1->cnt, 1);
    y = o.y; r2 = o.r2; if (r2) _InterlockedExchangeAdd(&r2->cnt, 1); } };
struct Outer { int a; Inner in; Outer(int a_, const Inner& i); };
Outer::Outer(int a_, const Inner& i) : a(a_), in(i) {}