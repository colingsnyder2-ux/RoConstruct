// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
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
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn != 0) pn->add_ref_copy(); }
    ~shared_ptr() { if (pn != 0) pn->release(); }
};
template<class T> class weak_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    weak_ptr(const weak_ptr& r) : px(r.px), pn(r.pn) { if (pn != 0) pn->weak_add_ref(); }
    ~weak_ptr() { if (pn != 0) pn->weak_release(); }
};
}
namespace RBX {
class Instance;
class SlotBase {
public:
    SlotBase(boost::weak_ptr<Instance> instance, boost::shared_ptr<Instance> other);
    boost::weak_ptr<Instance> instance;
    boost::shared_ptr<Instance> other;
};
struct Named {
    std::string name;
    Named(const std::string& n) : name(n) {}
};
class NamedSlot : public SlotBase, public Named {
public:
    NamedSlot(boost::weak_ptr<Instance> instance, boost::shared_ptr<Instance> other, std::string name);
};
NamedSlot::NamedSlot(boost::weak_ptr<Instance> instance, boost::shared_ptr<Instance> other, std::string name)
    : SlotBase(instance, other), Named(name)
{
}
}
