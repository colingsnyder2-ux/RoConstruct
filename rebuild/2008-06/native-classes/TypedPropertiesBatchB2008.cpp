// 2008-06 native TypedPropertiesBatchB2008 (inactive): TypedPropertyDescriptor<T>::isWriteOnly / getVariant / setVariant
// for value types that no other native unit instantiates (donor-free trial, rebuild/2008-06/out/donorfree/
// report-all-native.json). Only types the 2008 exe has a TypedPropertyDescriptor<T> RTTI class for: enum and raw
// pointer properties use EnumPropDescriptor / RefPropDescriptor there, so their TypedPropertyDescriptor references
// come from the native headers, not from 2008 code. Same generic bodies as G3DTypedProperties2008.cpp / ReflectionTypedProperties2008.cpp.
#include "reflection/type.h"
#include "reflection/property.h"
#include "util/MeshId.h"
#include "v8datamodel/BrickColor.h"
#include "script/ThreadRef.h"
#include <vector>
#include <boost/shared_ptr.hpp>
namespace RBX { namespace Reflection {
template<class T> bool TypedPropertyDescriptor<T>::isWriteOnly() const { return getset->isWriteOnly(); }
template<class T> void TypedPropertyDescriptor<T>::getVariant(const DescribedBase* instance, Value& value) const { value = getset->getValue(instance); }
template<class T> void TypedPropertyDescriptor<T>::setVariant(DescribedBase* instance, const Value& value) const { getset->setValue(instance, value.get<T>()); }
#define INSTANTIATE(T) template bool TypedPropertyDescriptor<T>::isWriteOnly() const; template void TypedPropertyDescriptor<T>::getVariant(const DescribedBase*,Value&) const; template void TypedPropertyDescriptor<T>::setVariant(DescribedBase*,const Value&) const;
INSTANTIATE(RBX::MeshId)
INSTANTIATE(RBX::BrickColor)
INSTANTIATE(RBX::Lua::FunctionRef)
INSTANTIATE(boost::shared_ptr<RBX::Instance>)
INSTANTIATE(boost::shared_ptr<RBX::Reflection::DescribedBase>)
typedef boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > InstancesRef;
INSTANTIATE(InstancesRef)
#undef INSTANTIATE
}}
