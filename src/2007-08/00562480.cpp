// from server: 100% by Intel_Inside
// roc-flags: /O2 /GS- /EHsc /MD

#include <vector>
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;   // vtable +4
    virtual void destroy();       // vtable +8
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

struct shared_count {
    sp_counted_base* pi_;
    ~shared_count() { if (pi_) pi_->release(); }
    shared_count& operator=(const shared_count& r);   // 0x402a60
};

template<class T> struct shared_ptr {
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
    T* get() const { return px; }
    operator bool() const { return px != 0; }
};

namespace RBX {
class Instance {                 // RTTI .?AVInstance@RBX@@ (0x881f4c)
public:
    virtual ~Instance();
};

class PVInstance : public Instance {   // RTTI .?AVPVInstance@RBX@@ (0x88c6b8)
};
}
using RBX::Instance;
using RBX::PVInstance;

struct Listener {           // subobject at +0xe8
    virtual void onEvent();
};

struct Owner {
    int pad[0x104 / 4];
    std::vector< shared_ptr<Instance> >* children;   // +0x104
    void addListener(Listener* l);                   // 0x532ba0
};

struct ServiceProvider;
ServiceProvider* findServiceProvider(Instance* inst);              // 0x41eb40
shared_ptr<Owner> findOwner(ServiceProvider* provider);            // 0x49d670

struct AncestorChanged {
    int pad[2];
    Instance* newParent;   // +8
};

struct Base {               // polymorphic: vptr at +0 (see dtor 0055ff50)
    virtual ~Base();
    int pad[(0xe8 - 4) / 4];
    void onAncestorChanged(const AncestorChanged& event);   // 0x541960
};

struct FilteredSelection : Base, Listener {
    shared_ptr<Owner> owner;            // +0xec
    std::vector<PVInstance*> items;   // +0xf4
    void onAncestorChanged(const AncestorChanged& event);
};

void FilteredSelection::onAncestorChanged(const AncestorChanged& event)
{
    Base::onAncestorChanged(event);
    if (!owner) {
        owner = findOwner(findServiceProvider(event.newParent));
        if (owner) {
            const std::vector< shared_ptr<Instance> >& c = *owner->children;
            for (std::vector< shared_ptr<Instance> >::const_iterator it = c.begin();
                 it != owner->children->end(); ++it) {
                if (PVInstance* p = dynamic_cast<PVInstance*>(it->get()))
                    items.push_back(p);
            }
            owner->addListener(this);
        }
    }
}
