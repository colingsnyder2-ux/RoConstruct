// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}-parent
// 2008-06 RefPropDescriptor<Instance,Instance> vtable overrides recovered from the original
// vftable at 0x0083a4d0: isWriteOnly 00565960, getVariant 00585420, setVariant 005da5b0.
// The overlay header restores the template-level overrides that the donor PBDB header omits.
#include "reflection/reflection.h"
#include "v8tree/Instance.h"

namespace RBX {
namespace Reflection {

template<typename Class, typename ReturnType>
bool RefPropDescriptor<Class, ReturnType>::isWriteOnly() const
{
	return getset->isWriteOnly();
}

template<typename Class, typename ReturnType>
void RefPropDescriptor<Class, ReturnType>::getVariant(const DescribedBase* instance, Value& value) const
{
	value = getset->getValue(instance);
}

template<typename Class, typename ReturnType>
void RefPropDescriptor<Class, ReturnType>::setVariant(DescribedBase* instance, const Value& value) const
{
	setRefValue(instance, value.get<ReturnType*>());
}

template bool RefPropDescriptor<Instance, Instance>::isWriteOnly() const;
template void RefPropDescriptor<Instance, Instance>::getVariant(const DescribedBase*, Value&) const;
template void RefPropDescriptor<Instance, Instance>::setVariant(DescribedBase*, const Value&) const;

}
}
