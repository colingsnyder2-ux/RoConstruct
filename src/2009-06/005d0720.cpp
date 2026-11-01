// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}
struct X;
template<int I> struct arg {};
struct Local {
    boost::shared_ptr<X> sp;
    Local(boost::shared_ptr<X> sp, arg<1> c, arg<2> d);
};
struct R {
    int a;
    int b;
    Local l;
    R(int a_, int b_, const Local& l_) : a(a_), b(b_), l(l_) {}
};
R make(int a, int b, boost::shared_ptr<X> sp, arg<1> c, arg<2> d)
{
    return R(a, b, Local(sp, c, d));
}
