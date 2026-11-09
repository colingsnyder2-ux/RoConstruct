// from server: 100% by EspClaude
// roc 2007-08 00495600  Reflection::RefPropDescriptor<Network::Player, ModelInstance>::assignIDREF (openrbx reflection.h), this = IIDREF subobject
// roc-flags: /O2 /GS /EHsc /MD
#include <memory>
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
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    T* get() const { return px; }
};
}
namespace RBX {
class Instance;
class ModelInstance;
namespace Network { class Player; }
class InstanceHandle {
public:
    boost::shared_ptr<Instance> getTarget() const;
private:
    boost::shared_ptr<Instance> target;
};
namespace Reflection {
class DescribedBase;
class ClassDescriptor;
class RefPropertyDescriptor {
public:
    virtual ~RefPropertyDescriptor();
    char pad[0x14];
};
class __declspec(novtable) IIDREF {
public:
    virtual void assignIDREF(DescribedBase* propertyOwner, const InstanceHandle& value) const = 0;
};
template<typename PropType> class TypedPropertyDescriptor {
public:
    class GetSet {
    public:
        virtual bool isReadOnly() const = 0;
        virtual PropType getValue(const DescribedBase* object) const = 0;
        virtual void setValue(DescribedBase* object, const PropType& value) const = 0;
    };
};
template <class Class, class T>
class RefPropDescriptor : public RefPropertyDescriptor, public IIDREF
{
public:
    void setValue(DescribedBase* instance, T* value) const { getset->setValue(instance, value); }
    virtual void assignIDREF(DescribedBase* propertyOwner, const InstanceHandle& handle) const
    {
        boost::shared_ptr<Instance> t = handle.getTarget();
        setValue(propertyOwner, static_cast<T*>(t.get()));
    }
private:
    std::auto_ptr<typename TypedPropertyDescriptor<T*>::GetSet> getset;
};
}
class Instance { public: virtual ~Instance(); };
class ModelInstance : public Instance {};
template class Reflection::RefPropDescriptor<Network::Player, ModelInstance>;
}
