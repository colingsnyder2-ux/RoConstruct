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
    weak_count(weak_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
};
namespace _bi {
template<class T> class value { public: value(T const& t) : t_(t) {} T t_; };
template<class A1> struct storage1 { explicit storage1(A1 a1); A1 a1_; };
template<class A1, class A2> struct storage2 : public storage1<A1> {
    storage2(A1 a1, A2 a2);
    A2 a2_;
};
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> {
    storage3(A1 a1, A2 a2, A3 a3);
    A3 a3_;
};
template<class A1, class A2, class A3> class list3 : private storage3<A1, A2, A3> {
    typedef storage3<A1, A2, A3> base_type;
public:
    list3(A1 a1, A2 a2, A3 a3) : base_type(a1, a2, a3) {}
};
}
}
namespace RBX { class Instance; class Player; }
template class boost::_bi::list3<boost::_bi::value<std::string>, boost::_bi::value<boost::weak_ptr<RBX::Instance> >, boost::_bi::value<boost::weak_ptr<RBX::Player> > >;
