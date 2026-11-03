// from server: 100% by EspClaude
// roc 2007-08 004605f0  getter returning a boost::shared_ptr member (exe +0x1d8) by value
// roc-flags: /O2 /GS- /EHsc /MD
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
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
namespace RBX {
class Instance;
class Owner {
    char pad[0x1d8];
    boost::shared_ptr<Instance> item;
public:
    boost::shared_ptr<Instance> getItem() const;
};
boost::shared_ptr<Instance> Owner::getItem() const
{
    return item;
}
}
