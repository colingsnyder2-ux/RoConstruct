// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
struct R{ char d[0x1c]; long n; }; void rel(void*, void*); struct Ptr{ R* p; Ptr(); ~Ptr(){ if(_InterlockedDecrement(&p->n)==0) rel(this,(void*)0x4b1bc0); } }; static Ptr g;
