// from server: 100% by EspClaude
// roc 2007-08 00591450  RBX::ObjectValue::ObjectValue() : value() { setName("Value"); } (boost::shared_ptr<Instance> value @0xe8)
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
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
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    shared_ptr() : px(0) {}
    ~shared_ptr() {}
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
namespace RBX {
class V0 { public: virtual ~V0(); };
class V1 { public: virtual ~V1(); int a, b; };
class V2 { public: virtual ~V2(); };
template<int N> class Notifier { public: virtual ~Notifier(); int pad[5]; };
class V8 { public: virtual ~V8(); char pad[0xe8 - 0x90]; };
class Instance : public V0, public V1, public V2, public Notifier<1>, public Notifier<2>, public Notifier<3>,
                 public Notifier<4>, public Notifier<5>, public V8 {
public:
    Instance();
    void setName(const std::string& name);
};
class ObjectValue : public Instance {
    boost::shared_ptr<Instance> value;
public:
    ObjectValue();
};
ObjectValue::ObjectValue()
{
    setName("Value");
}
}
