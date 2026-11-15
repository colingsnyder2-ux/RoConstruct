// 2008-06 native G3DTypedProperties2008 (inactive): TypedPropertyDescriptor<T> members for the G3D value types
// (Vector2int16, Vector3, Color3, CoordinateFrame), same shape as SoundTypedProperties.cpp.
#include "util/Sound.h"
#include "reflection/type.h"
#include <G3D/Vector2int16.h>
#include <G3D/Vector3.h>
#include <G3D/Color3.h>
#include <G3D/CoordinateFrame.h>
namespace RBX { namespace Reflection {
template<class T> bool TypedPropertyDescriptor<T>::isWriteOnly() const { return getset->isWriteOnly(); }
template<class T> void TypedPropertyDescriptor<T>::getVariant(const DescribedBase* instance, Value& value) const { value = getset->getValue(instance); }
template<class T> void TypedPropertyDescriptor<T>::setVariant(DescribedBase* instance, const Value& value) const { getset->setValue(instance, value.get<T>()); }
#define INSTANTIATE(T) template bool TypedPropertyDescriptor<T>::isWriteOnly() const; template void TypedPropertyDescriptor<T>::getVariant(const DescribedBase*,Value&) const; template void TypedPropertyDescriptor<T>::setVariant(DescribedBase*,const Value&) const;
INSTANTIATE(G3D::Vector2int16)
INSTANTIATE(G3D::Vector3)
INSTANTIATE(G3D::Color3)
INSTANTIATE(G3D::CoordinateFrame)
#undef INSTANTIATE
}}
