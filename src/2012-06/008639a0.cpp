// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#pragma intrinsic(_InterlockedDecrement)
extern "C" long _InterlockedDecrement(volatile long*);
struct O { int a, b; long cnt; };
void __cdecl g(O*);
struct S { O* p; void f(); };
void S::f() { _InterlockedDecrement(&p->cnt); if (p) g(p); }