// from server: 81% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_, weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr() : px(0) {}
    T* operator->() const { return px; }
    T* get() const { return px; }
};
}
namespace RBX {
class Instance;
template<class T> class copy_on_write {
    boost::shared_ptr<T> ptr;
public:
    operator bool() const { return ptr.px != 0; }
    boost::shared_ptr<const T> read() const;
};
struct AncestorChanged { Instance* child; Instance* oldParent; Instance* newParent; };
struct AncestrySignal {
    char pad[0x1c]; int slots1c; int pad20; int slots24;
    bool empty() const { return slots24 == 0 && slots1c == 0; }
};
struct AncestrySignalHolder {
    AncestrySignal* sig;
    void fire(boost::shared_ptr<Instance> child, boost::shared_ptr<Instance> parent);
};
boost::shared_ptr<Instance> shared_from(Instance* p);
class Instance {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void onAncestorChanged(const AncestorChanged& event);
    char pad4[0x4c - 4];
    copy_on_write<std::vector<boost::shared_ptr<Instance> > > children;
    char pad54[0x84 - 0x54];
    AncestrySignalHolder ancestryChanged;
};
void Instance::onAncestorChanged(const AncestorChanged& event)
{
    typedef std::vector<boost::shared_ptr<Instance> >::const_iterator Iterator;
    if (children)
    {
        boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > r = children.read();
        for (Iterator it = r->begin(); it != r->end(); it++)
        {
            (*it)->onAncestorChanged(event);
        }
    }
    if (ancestryChanged.sig && !ancestryChanged.sig->empty())
        ancestryChanged.fire(shared_from(event.child), shared_from(event.newParent));
}
}
