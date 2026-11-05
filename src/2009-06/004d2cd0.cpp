// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedIncrement)
namespace boost {
namespace detail {
inline void atomic_increment(long* pw) { _InterlockedIncrement(pw); }
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void add_ref_copy() { atomic_increment(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
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
template<int I> struct arg {};
namespace _bi {
template<class T> class value { public: value(T const& t) : t_(t) {} T t_; };
template<class A1> struct storage1 { A1 a1_; storage1(A1 a1); };
template<class A1, class A2> struct storage2 : public storage1<A1> { storage2(A1 a1, A2 a2); };
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> { storage3(A1 a1, A2 a2, A3 a3); };
template<class A1, class A2, class A3, class A4> struct storage4 : public storage3<A1, A2, A3> {
    storage4(A1 a1, A2 a2, A3 a3, A4) : storage3<A1, A2, A3>(a1, a2, a3) {}
};
}
}
namespace RBX { namespace Reflection { class GenericSlotAdapter; } }
template struct boost::_bi::storage4<boost::_bi::value<boost::shared_ptr<RBX::Reflection::GenericSlotAdapter> >, boost::arg<1>, boost::arg<2>, boost::arg<3> >;
