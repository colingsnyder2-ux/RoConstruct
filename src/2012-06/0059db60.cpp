// from server: 66% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/reflection/reflection_property.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/enumconverter.h"
#include "reflection/object.h"
#include "reflection/property.h"
#include "v8xml/XmlElement.h"

namespace RBX {
namespace Reflection {

// FUNCTION: WEBSERVICE 0x10094120
// FUNCTION: ROBLOX 0x00774720
void PropertyDescriptor::read(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	readValue(instance, element, binder);
}

// FUNCTION: WEBSERVICE 0x10094130
// FUNCTION: ROBLOX 0x005c06f0
template <>
const Type& Type::singleton<const PropertyDescriptor*>()
{
	static Type type("Property", typeid(const PropertyDescriptor*));

	return type;
}

// FUNCTION: WEBSERVICE 0x100941a0
// FUNCTION: ROBLOX 0x005c0760
XmlElement* PropertyDescriptor::write(const DescribedBase* instance, bool ignoreWriteProtection) const
{
	if (!ignoreWriteProtection) {
		if (isReadOnly()) {
			return NULL;
		}

		if (!canStreamWrite()) {
			return NULL;
		}
	}

	XmlElement* element = new XmlElement(type.tag);

	element->addAttribute<const RBX::Name*>(name_name, &name);

	writeValue(instance, element);

	return element;
}

// FUNCTION: WEBSERVICE 0x10094250
// FUNCTION: ROBLOX 0x005c0810
std::vector<const EnumDescriptor*>& EnumDescriptor::allEnums()
{
	static std::vector<const EnumDescriptor*> s;

	return s;
}

// FUNCTION: ROBLOX 0x005c0870
std::vector<const EnumDescriptor*>::const_iterator EnumDescriptor::enumsBegin()
{
	return allEnums().begin();
}

// FUNCTION: ROBLOX 0x005c08a0
std::vector<const EnumDescriptor*>::const_iterator EnumDescriptor::enumsEnd()
{
	return allEnums().end();
}

// FUNCTION: WEBSERVICE 0x100942b0
// FUNCTION: ROBLOX 0x005c08d0
EnumDescriptor::~EnumDescriptor()
{
	allEnums().erase(std::find(allEnums().begin(), allEnums().end(), this));
}

// FUNCTION: WEBSERVICE 0x10094390
// FUNCTION: ROBLOX 0x005c09b0
EnumDescriptor::EnumDescriptor(const char* typeName, const std::type_info& type)
	: Type(typeName, type, "token"), enumCount(0), enumCountMSB(0)
{
	allEnums().push_back(this);
}

// FUNCTION: WEBSERVICE 0x10094410
// FUNCTION: ROBLOX 0x005c0a30
PropertyDescriptor::PropertyDescriptor(
	ClassDescriptor& classDescriptor, const Type& type, const char* name, const char* category, Functionality flags
)
	: MemberDescriptor(classDescriptor, name, category), type(type), bIsPublic(flags), bCanStreamWrite(flags >> 2)
{
	classDescriptor.MemberDescriptorContainer<PropertyDescriptor>::declare(this);
}

} // namespace Reflection
} // namespace RBX
