// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
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
}
}
namespace boost {
namespace detail {
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
class InstanceHandle {
public:
    boost::shared_ptr<Instance> getTarget() const;
};
namespace Reflection {
class DescribedBase;
template<class T> class TypedPropertyDescriptor {
public:
    class GetSet {
    public:
        virtual ~GetSet();
        virtual bool isReadOnly() const = 0;
        virtual T getValue(const DescribedBase* object) const = 0;
        virtual void setValue(DescribedBase* object, const T& value) const = 0;
    };
};
class RefPropertyDescriptor {
public:
    virtual ~RefPropertyDescriptor();
    char pad[0x14];
};
class IIDREF {
public:
    virtual void assignIDREF(DescribedBase* propertyOwner, const InstanceHandle& value) const = 0;
};
template<class T> class auto_ptr_ {
public:
    T* p;
    T* operator->() const { return p; }
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
    auto_ptr_<typename TypedPropertyDescriptor<T*>::GetSet> getset;
};
template class RefPropDescriptor<Instance, Instance>;
}
}
