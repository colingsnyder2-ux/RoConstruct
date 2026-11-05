// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
#include <intrin.h>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct CountedBase { long vt; long use; long weak; };
extern long g_count;
struct Counter {
    Counter(const Counter&) { InterlockedIncrement(&g_count); }
};
struct WeakRef {
    void* px;
    CountedBase* pi;
    WeakRef(const WeakRef& r) : px(r.px), pi(r.pi) { if (pi) _InterlockedIncrement(&pi->weak); }
};
struct Obj : Counter {
    WeakRef w;
    Obj(const Obj& o);
};
Obj::Obj(const Obj& o) : Counter(o), w(o.w) {}
