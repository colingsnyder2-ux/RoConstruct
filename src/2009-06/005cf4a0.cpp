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
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
};
struct sp_empty {};
template<class Y, class T> struct sp_enable_if_convertible { typedef sp_empty type; };
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    template<class Y>
    shared_ptr(shared_ptr<Y> const& r, typename detail::sp_enable_if_convertible<Y,T>::type = detail::sp_empty())
        : px(r.px), pn(r.pn) {}
};
}
namespace RBX {
namespace Reflection { class DescribedBase { public: int d; }; }
struct InstancePad { char pad[0x18]; };
class Instance : public InstancePad, public Reflection::DescribedBase {};
}
template boost::shared_ptr<RBX::Reflection::DescribedBase>::shared_ptr(boost::shared_ptr<RBX::Instance> const&, boost::detail::sp_empty);
