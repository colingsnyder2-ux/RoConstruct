// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
struct Ref { virtual void a(); virtual void b(); virtual void dispose(); int pad; volatile long cnt; };
struct TP { virtual ~TP(); int pad; Ref* r; };
TP::~TP() { Ref* p = r; if (p && _InterlockedDecrement(&p->cnt) == 0) p->dispose(); }
