// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native TypedPropertyDescriptor<std::string>::readValue (0056e5a0) and
// TypedPropertyDescriptor<G3D::Vector3>::readValue (0056e850), inactive. Flags line copied from the sibling
// TypedPropertyDescriptor specializations unit (TypedPropertySpecializations2008.cpp).
// Identity: registry decorated names
//   ?readValue@?$TypedPropertyDescriptor@V?$basic_string@...@Reflection@RBX@@EBEXPAVDescribedBase@23@PBVXmlElement@@AAVIReferenceBinder@3@@Z
//   ?readValue@?$TypedPropertyDescriptor@VVector3@G3D@@@Reflection@RBX@@EBEXPAVDescribedBase@23@PBVXmlElement@@AAVIReferenceBinder@3@@Z
// Both sit in the 0056e0c0..0056e900 TypedPropertyDescriptor specialization run (Vector2int16 readValue 0056e3a0,
// bool 0056e6e0, int 0056e7e0, Vector3 writeValue 0056e900) and call XmlElement::isXsiNil 0057c810; the string
// one reads through XmlNameValuePair::getValue(std::string&) 0057c210, the Vector3 one finds tag_X / tag_Y /
// tag_Z (0975334 / 0975380 / 0975318) with findFirstChildByTag 0057c230 and reads floats with 0057c610.
// Bodies follow donor v8tree/EnumProperty.cpp.
#include "reflection/property.h"
#include "v8xml/XmlElement.h"
#include <G3D/Vector3.h>

namespace RBX {
namespace Reflection {

// 0056e5a0
template<>
void TypedPropertyDescriptor<std::string>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		std::string value;
		if (element->getValue(value))
		{
			setValue(instance, value);
		}
	}
}

// 0056e630 ?writeValue@?$TypedPropertyDescriptor@V?$basic_string@...@std@@@Reflection@RBX@@EBEXPBVDescribedBase@23@PAVXmlElement@@@Z
// (registry identity-closure, 9 vtable references). Right after the string readValue 0056e5a0: the value comes from the
// out-of-line getValue 0061a7b0 built straight into the by-value argument of XmlNameValuePair::setValue(std::string)
// 00495dd0 on the element's XmlNameValuePair base (+0x10).
template<>
void TypedPropertyDescriptor<std::string>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

// 0056e0e0 ?setStringValue@?$TypedPropertyDescriptor@V?$basic_string@...@std@@@Reflection@RBX@@UBE_NPAVDescribedBase@23@ABV...@@Z
// (registry identity-closure, 9 vtable references): getset slot 3 (+0xc) setValue, then true.
template<>
bool TypedPropertyDescriptor<std::string>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	setValue(instance, text);
	return true;
}

// 0056e850
template<>
void TypedPropertyDescriptor<G3D::Vector3>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		if (const XmlElement* X = element->findFirstChildByTag(tag_X))
		{
			const XmlElement* Y = element->findFirstChildByTag(tag_Y);
			const XmlElement* Z = element->findFirstChildByTag(tag_Z);

			G3D::Vector3 value;

			X->getValue(value.x);
			Y->getValue(value.y);
			Z->getValue(value.z);

			setValue(instance, value);
		}
	}
}

}
}
