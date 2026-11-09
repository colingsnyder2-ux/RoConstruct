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
    void weak_add_ref() { atomic_increment(&weak_count_); }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    template<class P, class D> shared_count(P p, D d);
    ~shared_count();
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count& operator=(shared_count const& r)
    {
        sp_counted_base* tmp = r.pi_;
        if (tmp != pi_)
        {
            if (tmp != 0) tmp->weak_add_ref();
            if (pi_ != 0) pi_->weak_release();
            pi_ = tmp;
        }
        return *this;
    }
};
}
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
    template<class Y> void _internal_assign(Y* px2, detail::shared_count const& pn2) { px = px2; pn = pn2; }
};
template<class T> class enable_shared_from_this {
public:
    mutable weak_ptr<T> _internal_weak_this;
};
namespace detail {
template<class T, class Y> inline void sp_enable_shared_from_this(shared_count const& pn, enable_shared_from_this<T> const* pe, Y const* px)
{
    if (pe != 0) pe->_internal_weak_this._internal_assign(const_cast<Y*>(px), pn);
}
inline void sp_enable_shared_from_this(shared_count const&, ...) {}
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    template<class Y, class D> shared_ptr(Y* p, D d) : px(p), pn(p, d)
    {
        detail::sp_enable_shared_from_this(pn, p, p);
    }
};
}
namespace RBX {
struct ExePad24 { char pad[0x24]; };
class Instance : public ExePad24, public boost::enable_shared_from_this<Instance> {};
template<class T> class Creatable { public: struct Deleter { void operator()(T* p); }; };
class Script : public Instance {};
}
template boost::shared_ptr<RBX::Script>::shared_ptr(RBX::Script*, RBX::Creatable<RBX::Instance>::Deleter);
