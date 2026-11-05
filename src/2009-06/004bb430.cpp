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
}
template<class T> class shared_ptr {
public:
    T* px; detail::sp_counted_base* pi_;
    shared_ptr(const shared_ptr& r) : px(r.px), pi_(r.pi_) { if (pi_) pi_->add_ref_copy(); }
    ~shared_ptr() { if (pi_) pi_->release(); }
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
namespace RBX {
class Instance;
struct Event { int a; boost::shared_ptr<Instance> b; };
struct Impl { void fire(Event e); };
struct Holder { Impl* impl; void fire(Event e); };
void Holder::fire(Event e)
{
    if (impl)
        impl->fire(e);
}
}
