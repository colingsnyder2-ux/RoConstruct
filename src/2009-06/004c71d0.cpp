// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); if (_InterlockedDecrement(&weak_count_) == 0) destroy(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count(weak_count const& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->weak_count_); }
    ~weak_count() { if (pi_ != 0 && _InterlockedDecrement(&pi_->weak_count_) == 0) pi_->destroy(); }
};
}
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
};
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
template<class T> struct type {};
namespace _bi {
template<class T> class value {
public:
    T t_;
    T& get() { return t_; }
};
template<class A1, class A2, class A3, class A4, class A5> struct list5 {
    A1 a1_; A2 a2_; A3 a3_; A4 a4_; A5 a5_;
    template<class T> T& operator[](value<T>& v) const { return v.get(); }
    template<class F, class A> void operator()(type<void>, F& f, A& a, int)
    {
        f(a[a1_], a[a2_], a[a3_], a[a4_], a[a5_]);
    }
};
struct list0 {
    template<class T> T& operator[](value<T>& v) const { return v.get(); }
};
}
namespace _mfi {
template<class R, class T, class B1, class B2, class B3, class B4> class mf4 {
public:
    typedef R (T::*F)(B1, B2, B3, B4);
    F f_;
    template<class U> R operator()(U& u, B1 b1, B2 b2, B3 b3, B4 b4) const;
};
}
}
class Obj; class Other;
typedef boost::_mfi::mf4<void, Obj, boost::weak_ptr<Other>, std::string, std::string, int> MF;
typedef boost::_bi::list5<boost::_bi::value<boost::shared_ptr<Obj> >, boost::_bi::value<boost::weak_ptr<Other> >, boost::_bi::value<std::string>, boost::_bi::value<std::string>, boost::_bi::value<int> > L;
template void L::operator()<MF, boost::_bi::list0>(boost::type<void>, MF&, boost::_bi::list0&, int);
