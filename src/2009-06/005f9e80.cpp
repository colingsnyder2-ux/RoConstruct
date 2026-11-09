// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    ~shared_ptr() { if (pn) pn->release(); }
    T* operator->() const { return px; }
    T* get() const { return px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};
}
namespace RBX {
class Name;
class Instance {
public:
    virtual ~Instance();
    char pad[0x44];
    Instance* parent;
    void setParent(Instance* p);
    Instance* getParent() const { return parent; }
    template<class T> static __forceinline T* findFirstAncestorOfClass(Instance* context) {
        Instance* p = context;
        while (p) {
            if (T* t = dynamic_cast<T*>(p)) return t;
            p = p->getParent();
        }
        return 0;
    }
};
class ServiceProvider : public Instance {
public:
    virtual void v1();
    virtual void v2();
    virtual boost::shared_ptr<Instance> createChild(const Name& className);
    static Instance* create(Instance* context, const Name& name);
};
Instance* ServiceProvider::create(Instance* context, const Name& name)
{
    ServiceProvider* provider = Instance::findFirstAncestorOfClass<ServiceProvider>(context);
    if (!provider)
        return 0;
    boost::shared_ptr<Instance> child = provider->createChild(name);
    if (child)
        child->setParent(provider);
    return child.get();
}
}
