// from server: 98% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_, weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
template<class T> struct shared_ptr {
    T* px; shared_count pn;
};
struct X; struct T;
struct Tmp : shared_ptr<X> { Tmp(shared_ptr<T> sp, int a, int b, int c); };
struct A { int x, y; };
struct R {
    A a; shared_ptr<X> s;
    R(A a_, const shared_ptr<X>& s_) : a(a_), s(s_) {}
};
R make(A a, shared_ptr<T> sp, int x, int y, int z)
{
    return R(a, Tmp(sp, x, y, z));
}
