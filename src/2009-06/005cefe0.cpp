// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)
namespace std { template<class T> class allocator; }
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* get() const { return px; }
};
template<class Sig, class A> class function;
namespace signals { namespace detail {
class slot_base {
public:
    struct data_t { void release(const slot_base* s); };
    int pad;
    shared_ptr<data_t> data;
};
}}
template<class SlotFunction> class slot : public signals::detail::slot_base {
public:
    ~slot() { if (data.get()) data.get()->release(this); }
};
}
namespace RBX { class Instance; }
template class boost::slot<boost::function<void (boost::shared_ptr<RBX::Instance>), std::allocator<void> > >;
