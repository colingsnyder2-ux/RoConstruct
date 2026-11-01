// from server: 100% by EspClaude
// roc 2009-06 006f96b0  unit: RBX::RunDragger  size: 213 bytes
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <utility>
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count() : pi_(0) {}
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
    void swap(weak_count& r) { sp_counted_base* tmp = r.pi_; r.pi_ = pi_; pi_ = tmp; }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
template<class T> class weak_ptr {
public:
    typedef weak_ptr<T> this_type;
    T* px;
    detail::weak_count pn;
    weak_ptr() : px(0), pn() {}
    template<class Y> weak_ptr& operator=(shared_ptr<Y> const& r);
    void reset() { this_type().swap(*this); }
    void swap(this_type& other) { std::swap(px, other.px); pn.swap(other.pn); }
};
}
namespace RBX {
class PartInstance;
class ModelInstance;
template<class T> boost::shared_ptr<T> shared_from(T* r);
PartInstance* getTarget(PartInstance* p);
class RunDragger {
public:
    void* vp;
    int a;
    boost::weak_ptr<PartInstance> target;
    char pad[0x14];
    PartInstance* part;
    void updateTarget();
};
void RunDragger::updateTarget()
{
    if (part)
        target = shared_from(getTarget(part));
    else
        target.reset();
}
}
