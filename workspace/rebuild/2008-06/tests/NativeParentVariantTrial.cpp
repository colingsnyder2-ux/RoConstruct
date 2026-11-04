// Isolated descriptor ABI fixture, never linked into the player.
#include "v8tree/Instance.h"
#include <boost/cast.hpp>

static __forceinline RBX::Instance* asInstance(RBX::Reflection::DescribedBase* value)
{
    if (value) return boost::polymorphic_cast<RBX::Instance*>(value);
    return NULL;
}

template<>
bool RBX::Reflection::RefPropDescriptor<RBX::Instance, RBX::Instance>::isReadOnly() const
{
    return getset->isReadOnly();
}

template<>
bool RBX::Reflection::RefPropDescriptor<RBX::Instance, RBX::Instance>::equalValues(
    const RBX::Reflection::DescribedBase* a, const RBX::Reflection::DescribedBase* b) const
{
    return getValue(a) == getValue(b);
}

template<>
RBX::Reflection::DescribedBase* RBX::Reflection::RefPropDescriptor<RBX::Instance, RBX::Instance>::getRefValue(
    const RBX::Reflection::DescribedBase* instance) const
{
    return getValue(instance);
}

template<>
void RBX::Reflection::RefPropDescriptor<RBX::Instance, RBX::Instance>::setRefValue(
    RBX::Reflection::DescribedBase* instance, RBX::Reflection::DescribedBase* value) const
{
    getset->setValue(instance, asInstance(value));
}

template<>
void RBX::Reflection::RefPropDescriptor<RBX::Instance, RBX::Instance>::getVariant(
    const RBX::Reflection::DescribedBase* instance, RBX::Reflection::Value& value) const
{
    boost::shared_ptr<RBX::Reflection::DescribedBase> reference = RBX::shared_from(getValue(instance));
    value = reference;
}

template<>
void RBX::Reflection::RefPropDescriptor<RBX::Instance, RBX::Instance>::setVariant(
    RBX::Reflection::DescribedBase* instance, const RBX::Reflection::Value& value) const
{
    boost::shared_ptr<RBX::Reflection::DescribedBase> reference = value.get<boost::shared_ptr<RBX::Reflection::DescribedBase> >();
    setRefValue(instance, reference.get());
}
