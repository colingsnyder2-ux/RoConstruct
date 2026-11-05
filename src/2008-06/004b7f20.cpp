// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_e3630ff3e82b33fa.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <vector>
#include <typeinfo>
#include <intrin.h>
#include <utility>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn; __forceinline ~shared_ptr(){}
    shared_ptr():px(0),pn(){}
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
    void reset(){shared_ptr().swap(*this);}
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}

namespace RakNet { class BitStream { public: int numberOfBitsUsed; int numberOfBitsAllocated; int readOffset; int GetNumberOfBitsUsed() const { return numberOfBitsUsed; } }; }
namespace RBX {
class Name { int dictionaryIndex; public: const std::string name; const char* c_str() const { return name.c_str(); } };
class StandardOut { public: static boost::shared_ptr<StandardOut> singleton(); void __cdecl print(int, const char*, ...); };
class StandardOutB : public StandardOut { public: static boost::shared_ptr<StandardOutB> singleton(); };
}
namespace boost { template<> shared_ptr<RBX::StandardOutB>::~shared_ptr(); }
namespace RBX {
namespace Reflection {
class DescribedBase;
class ClassDescriptor;
class Descriptor { public: const Name& name; virtual ~Descriptor() {} };
class Type : public Descriptor { public: const type_info& type; const Name& tag; };
class MemberDescriptor : public Descriptor { public: const Name& category; const ClassDescriptor& owner; };
class ConstProperty;
class PropertyDescriptor : public MemberDescriptor {
public:
    typedef ConstProperty ConstMember;
private:
    unsigned bIsPublic : 1;
    unsigned bCanStreamWrite : 1;
public:
    const Type& type;
    virtual bool isReadOnly() const = 0;
    virtual bool exeExtra() const = 0;
    bool canStreamWrite() const { return bCanStreamWrite; }
    virtual bool equalValues(const DescribedBase*, const DescribedBase*) const = 0;
};
class ConstProperty {
protected:
    const PropertyDescriptor* descriptor;
    const DescribedBase* instance;
public:
    ConstProperty(const PropertyDescriptor& descriptor, const DescribedBase* instance) : descriptor(&descriptor), instance(instance) {}
    const DescribedBase* getInstance() const { return instance; }
    const PropertyDescriptor& getDescriptor() const { return *descriptor; }
};
template<class TheDescriptor>
class MemberDescriptorContainer {
public:
    typedef std::vector<TheDescriptor*> CollectionType;
    class Collection : public CollectionType {};
    class ConstIterator {
        const DescribedBase* instance;
        typename CollectionType::const_iterator iter;
    public:
        ConstIterator(const typename CollectionType::const_iterator& iter, const DescribedBase* instance) : instance(instance), iter(iter) {}
        typename TheDescriptor::ConstMember operator*() const { return typename TheDescriptor::ConstMember(getDescriptor(), instance); }
        bool operator!=(const ConstIterator& other) const { return iter != other.iter; }
        ConstIterator& operator++() { ++iter; return *this; }
        const TheDescriptor& getDescriptor() const { return **iter; }
    };
    ConstIterator members_begin(const DescribedBase* instance) const { return ConstIterator(descriptors.begin(), instance); }
    ConstIterator members_end(const DescribedBase* instance) const { return ConstIterator(descriptors.end(), instance); }
protected:
    Collection descriptors;
};
typedef MemberDescriptorContainer<PropertyDescriptor> PropertyContainer;
typedef PropertyContainer::ConstIterator ConstPropertyIterator;
class ClassDescriptor : public Descriptor, public PropertyContainer {};
class DescribedBase {
public:
    virtual ~DescribedBase();
    void* signals;
    const ClassDescriptor* descriptor;
    const ClassDescriptor& getDescriptor() const { return *descriptor; }
    ConstPropertyIterator properties_begin() const { return getDescriptor().PropertyContainer::members_begin(this); }
    ConstPropertyIterator properties_end() const { return getDescriptor().PropertyContainer::members_end(this); }
};
}
class ParentDescriptor : public Reflection::PropertyDescriptor { public: bool isReadOnly() const; bool exeExtra() const; bool equalValues(const Reflection::DescribedBase*, const Reflection::DescribedBase*) const; };
class Primary { public: virtual ~Primary(); char opaque[12]; };
class FactoryProduct { public: virtual ~FactoryProduct(); virtual const Name& getClassName() const = 0; };
class Instance : public Primary, public FactoryProduct, public Reflection::DescribedBase {
public:
    static const ParentDescriptor propParent;
};
namespace Network {
struct Settings { char prefix[0x131]; bool printInstances, printProperties; static Settings& singleton(); };
class Replicator {
public:
    const Instance* getDefault(const Name&);
    void serializeValue(const Reflection::ConstProperty&, bool, RakNet::BitStream&);
    void writeProperties(const Instance*, RakNet::BitStream&);
};
RakNet::BitStream& operator<<(RakNet::BitStream&, bool);
void Replicator::writeProperties(const Instance* instance, RakNet::BitStream& stream)
{
    const Instance* defaultInstance = getDefault(instance->getClassName());
    const Reflection::DescribedBase& described = *instance;
    Reflection::ConstPropertyIterator iter = described.properties_begin();
    Reflection::ConstPropertyIterator end = described.properties_end();
    for (; iter != end; ++iter)
    {
        const Reflection::PropertyDescriptor& descriptor = iter.getDescriptor();
        Reflection::ConstProperty property(descriptor, &described);
        if (descriptor.canStreamWrite() && &descriptor != &Instance::propParent)
        {
            const type_info& ti = descriptor.type.type;
            if (typeid(bool) == ti)
            {
                serializeValue(property, false, stream);
                if (Settings::singleton().printInstances && Settings::singleton().printProperties)
                    StandardOut::singleton()->print(1, "   write %s %s, 1 bit", descriptor.type.name.c_str(), descriptor.name.c_str());
            }
            else if (defaultInstance && descriptor.equalValues(&described, defaultInstance))
            {
                stream << true;
                if (Settings::singleton().printInstances && Settings::singleton().printProperties)
                    StandardOutB::singleton()->print(1, "   write %s %s, 1 bit (default)", descriptor.type.name.c_str(), descriptor.name.c_str());
            }
            else
            {
                int bits = stream.GetNumberOfBitsUsed();
                stream << false;
                serializeValue(property, false, stream);
                if (Settings::singleton().printInstances && Settings::singleton().printProperties)
                    StandardOut::singleton()->print(1, "   write %s %s, %d bits", descriptor.type.name.c_str(), descriptor.name.c_str(), stream.GetNumberOfBitsUsed() - bits);
            }
        }
    }
}
}
}
