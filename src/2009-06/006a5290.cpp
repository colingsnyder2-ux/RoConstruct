// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)
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
}
namespace RBX {
class Instance;
class InstanceHandle { public: boost::shared_ptr<Instance> getTarget() const; };
namespace Reflection {
class DescribedBase;
class PropertyDescriptor {
public:
    virtual ~PropertyDescriptor();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void setRefValue(DescribedBase* instance, Instance* value) const = 0;
    virtual void assignIDREF(DescribedBase* propertyOwner, const InstanceHandle& handle) const = 0;
};
template<class C, class T> class RefPropDescriptor : public PropertyDescriptor {
public:
    virtual void setRefValue(DescribedBase* instance, Instance* value) const;
    virtual void assignIDREF(DescribedBase* propertyOwner, const InstanceHandle& handle) const
    {
        boost::shared_ptr<Instance> t = handle.getTarget();
        setRefValue(propertyOwner, t.get());
    }
};
template class RefPropDescriptor<Instance, Instance>;
}
}
