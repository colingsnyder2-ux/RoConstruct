// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count(const weak_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
};
template<int I> struct arg {};
namespace _bi {
template<class T> class value {
public:
    value(T const& t) : t_(t) {}
    T t_;
};
template<class A1, class A2, class A3> struct storage3 {
    storage3(A1 a1, A2 a2, A3 a3);
    A1 a1_; A2 a2_; A3 a3_;
};
template<class A1, class A2, class A3> class list3 : private storage3<A1, A2, A3> {
public:
    list3(A1 a1, A2 a2, A3 a3) : storage3<A1, A2, A3>(a1, a2, a3) {}
};
}
}
class X; class Y; struct P { int a, b; };
template class boost::_bi::list3<boost::_bi::value<P>, boost::_bi::value<boost::weak_ptr<X> >, boost::_bi::value<boost::weak_ptr<Y> > >;
