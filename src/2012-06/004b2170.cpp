// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#pragma intrinsic(_InterlockedDecrement)
extern "C" long _InterlockedDecrement(volatile long*);
struct P{char pad[0x1c]; long c;}; struct S{P* p; void f();}; void g(S*,void(*)()); void fn(); void S::f(){ if(_InterlockedDecrement(&p->c)==0) g(this,fn); }
