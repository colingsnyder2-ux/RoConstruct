// >>> native-status (generated) -- do not edit >>>
// SoundTypedProperties | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 92bf579e | roc native-status --write
#include "util/Sound.h"
#include "reflection/type.h"
namespace RBX { namespace Reflection {
template<class T> bool TypedPropertyDescriptor<T>::isWriteOnly() const { return getset->isWriteOnly(); }
template<class T> void TypedPropertyDescriptor<T>::getVariant(const DescribedBase* instance, Value& value) const { value = getset->getValue(instance); }
template<class T> void TypedPropertyDescriptor<T>::setVariant(DescribedBase* instance, const Value& value) const { getset->setValue(instance, value.get<T>()); }
#define INSTANTIATE(T) template bool TypedPropertyDescriptor<T>::isWriteOnly() const; template void TypedPropertyDescriptor<T>::getVariant(const DescribedBase*,Value&) const; template void TypedPropertyDescriptor<T>::setVariant(DescribedBase*,const Value&) const;
INSTANTIATE(bool)
INSTANTIATE(float)
INSTANTIATE(int)
INSTANTIATE(Soundscape::SoundId)
#undef INSTANTIATE
}}
