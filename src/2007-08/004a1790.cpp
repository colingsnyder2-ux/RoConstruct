// from server: 100% by EspClaude
// roc 2007-08 004a1790  template void Property::setValue<RBX::BrickColor>(const RBX::BrickColor&);
namespace RBX { class BrickColor { public: int number; }; }
// RBX::Reflection ConstProperty::getValue<T> / Property::setValue<T> (reflection/property.h, boost::polymorphic_cast).
// roc-flags: /O2 /GS /EHsc /MD
#include <typeinfo>
#include <memory>
namespace boost {
template <class Target, class Source>
inline Target polymorphic_cast(Source* x)
{
    Target tmp = dynamic_cast<Target>(x);
    if (tmp == 0) throw std::bad_cast();
    return tmp;
}
}
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX {
namespace Reflection {
class DescribedBase;
class PropertyDescriptor {
public:
    virtual ~PropertyDescriptor();
    char pad[0x14];
};
template<typename PropType>
class TypedPropertyDescriptor : public PropertyDescriptor {
public:
    class GetSet {
    public:
        virtual bool isReadOnly() const = 0;
        virtual PropType getValue(const DescribedBase*) const = 0;
        virtual void setValue(DescribedBase*, const PropType&) const = 0;
    };
protected:
    std::auto_ptr<GetSet> getset;
public:
    virtual ~TypedPropertyDescriptor();
    PropType getValue(const DescribedBase* object) const { return getset->getValue(object); }
    void setValue(DescribedBase* object, const PropType& value) const { getset->setValue(object, value); }
};
class ConstProperty {
protected:
    const PropertyDescriptor* descriptor;
    const DescribedBase* instance;
public:
    template<typename T>
    T getValue() const
    {
        const TypedPropertyDescriptor<T>* value = boost::polymorphic_cast<const TypedPropertyDescriptor<T>*>(descriptor);
        return value->getValue(instance);
    }
};
class Property : public ConstProperty {
public:
    DescribedBase* getInstance() const { return const_cast<DescribedBase*>(instance); }
    template<typename T>
    void setValue(const T& value)
    {
        const TypedPropertyDescriptor<T>* typedProp = boost::polymorphic_cast<const TypedPropertyDescriptor<T>*>(descriptor);
        typedProp->setValue(getInstance(), value);
    }
};
template void Property::setValue<RBX::BrickColor>(const RBX::BrickColor&);
}}
