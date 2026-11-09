// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_; long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
struct shared_count {
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    T* operator->() const { return px; }
};
}
namespace RBX {
class Instance {
public:
    char pad[0x48];
    Instance* parent;
    Instance* getParent() const { return parent; }
    bool isAncestorOf(const Instance* d) const;
    void setParent(Instance* p);
};
class Instances {
public:
    Instances(); ~Instances();
    void push_back(const boost::shared_ptr<Instance>& i);
    char pad[0x18];
};
class Workspace : public Instance {
public:
    static Workspace* findWorkspace(Instance* i);
    void insertInstances(const Instances& items, Instance* parent, bool a, bool b);
};
void moveToParent(Instance* newParent, boost::shared_ptr<Instance> instance)
{
    if (instance->getParent() == newParent)
        return;
    Workspace* w = Workspace::findWorkspace(newParent);
    if (w && w != instance->getParent() && (!instance->getParent() || !instance->getParent()->isAncestorOf(w))) {
        Instances items;
        items.push_back(instance);
        w->insertInstances(items, w, true, true);
    }
    instance->setParent(newParent);
}
}
