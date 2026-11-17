// 2008-06 native ReflectionTypedProperties2008 (inactive): TypedPropertyDescriptor<T> members for the remaining value
// types (std::string, TextureId, ContentId, double), same shape as SoundTypedProperties.cpp / G3DTypedProperties2008.cpp.
#include "util/TextureId.h"
#include "reflection/type.h"
#include "reflection/property.h"
#include <string>
namespace RBX { namespace Reflection {
template<class T> bool TypedPropertyDescriptor<T>::isWriteOnly() const { return getset->isWriteOnly(); }
template<class T> void TypedPropertyDescriptor<T>::getVariant(const DescribedBase* instance, Value& value) const { value = getset->getValue(instance); }
template<class T> void TypedPropertyDescriptor<T>::setVariant(DescribedBase* instance, const Value& value) const { getset->setValue(instance, value.get<T>()); }
#define INSTANTIATE(T) template bool TypedPropertyDescriptor<T>::isWriteOnly() const; template void TypedPropertyDescriptor<T>::getVariant(const DescribedBase*,Value&) const; template void TypedPropertyDescriptor<T>::setVariant(DescribedBase*,const Value&) const;
INSTANTIATE(std::string)
INSTANTIATE(TextureId)
INSTANTIATE(ContentId)
INSTANTIATE(double)
#undef INSTANTIATE
}}
