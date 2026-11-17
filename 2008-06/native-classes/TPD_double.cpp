// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// TypedPropertyDescriptor<double> equalValues / writeValue / readValue (00563ff0, 0056e720, 0056e760)
#include "reflection/property.h"
#include "v8xml/XmlElement.h"

namespace RBX {
namespace Reflection {

template<>
bool TypedPropertyDescriptor<double>::equalValues(const DescribedBase* a, const DescribedBase* b) const
{
	const double value = getValue(a);
	return getValue(b) == value;
}

template<>
void TypedPropertyDescriptor<double>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

template<>
void TypedPropertyDescriptor<double>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		double value;
		if (element->getValue(value))
			getset->setValue(instance, value);
	}
}

template class TypedPropertyDescriptor<double>; // emits the in-class equalValues specialization through the vtable

}
}
