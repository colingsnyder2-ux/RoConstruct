// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost { namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_; long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
struct sp_empty {};
template<class Y, class T> struct sp_enable_if_convertible { typedef sp_empty type; };
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    template<class Y>
    shared_ptr(shared_ptr<Y> const& r, typename detail::sp_enable_if_convertible<Y,T>::type = detail::sp_empty())
        : px(r.px), pn(r.pn) {}
};
}
namespace RBX {
class Instance { public: virtual ~Instance(); };
class Pad14 { public: virtual ~Pad14(); char pad[0x10]; };
class BodyVelocity : public Pad14, public Instance {};
class Creatable { public: template<class T> static boost::shared_ptr<T> create(); };
template<class T> class Creator {
public:
    boost::shared_ptr<Instance> create() const { return Creatable::create<T>(); }
};
template class Creator<BodyVelocity>;
}
