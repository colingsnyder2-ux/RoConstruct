// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct sp_counted_base { void* vt; long use_count_; long weak_count_; void weak_add_ref() { _InterlockedIncrement(&weak_count_); } };
struct weak_count {
    sp_counted_base* pi_;
    weak_count(const weak_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
};
extern long instanceCount;
struct Counted { Counted() {} Counted(const Counted&) { InterlockedIncrement(&instanceCount); } };
struct WeakRef : Counted { void* px; weak_count pn; };
struct M { int x; WeakRef w; };
struct C {
    int a, b, c;
    M m;
    bool f, g;
    C(int a, int b, int c, const M& m, bool f);
};
C::C(int a_, int b_, int c_, const M& m_, bool f_) : a(a_), b(b_), c(c_), m(m_), f(f_), g(false) {}
