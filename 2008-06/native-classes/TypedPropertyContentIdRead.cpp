// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native TypedPropertyDescriptor<ContentId>::readValue (placeholder func_0056f7e0, 152 B, `ret 0xc`), inactive.
// Identity: slot 11 (readValue) of the TypedPropertyDescriptor<ContentId> vtable 008312e0 and of the folded
// PropDescriptor<Script, ContentId> vtable 00831360; it sits in the TypedPropertyDescriptor specialization run after the
// BrickColor readValue / writeValue pair 0056f750 / 0056f7a0. Body: XmlElement::isXsiNil 0057c810, a default ContentId
// (std::string + mimeTypePtr = &Name::getNullName() 00554270), XmlNameValuePair::getValue(ContentId&) 0057c3d0 on the
// element's +0x10 base, then the getset slot 3 (+0xc) setValue. Same shape as the string readValue 0056e5a0
// (TPDReadValueTextVector.cpp); flags line copied from that unit.
#include "reflection/property.h"
#include "v8xml/XmlElement.h"
#include "util/ContentProvider.h"

namespace RBX {
namespace Reflection {

// 0056f7e0
template<>
void TypedPropertyDescriptor<ContentId>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		ContentId value;
		if (element->getValue(value))
		{
			setValue(instance, value);
		}
	}
}

}
}
