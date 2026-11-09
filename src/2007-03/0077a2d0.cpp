// from server: 79% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs reflection/reflection_property.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/enumconverter.h"
#include "reflection/property.h"
#include "reflection/object.h"

namespace RBX
{
	namespace Reflection
	{
		// TODO: check if type singletons are matching
		template<>
		const Type& Type::singleton<const PropertyDescriptor*>()
		{
			static Type type("Property", typeid(const PropertyDescriptor*));
			return type;
		}

		PropertyDescriptor::PropertyDescriptor(ClassDescriptor& classDescriptor, const Type& type, const char* name, const char* category, Functionality flags)
			: MemberDescriptor(classDescriptor, name, category),
			  bIsPublic(((flags >> 0) & 1) != 0),
			  bCanStreamWrite(((flags >> 2) & 1) != 0),
			  type(type)
		{
			classDescriptor.PropertyContainer::declare(this);
		}

		void PropertyDescriptor::read(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			readValue(instance, element, binder);
		}

		XmlElement* PropertyDescriptor::write(const DescribedBase* instance, bool ignoreWriteProtection) const
		{
			if (!ignoreWriteProtection)
			{
				if (isReadOnly())
					return NULL;

				if (!canStreamWrite())
					return NULL;
			}

			XmlElement* element = new XmlElement(type.tag);
			element->addAttribute(name_name, &this->name);

			writeValue(instance, element);
			return element;
		}

		std::vector<const EnumDescriptor*>& EnumDescriptor::allEnums()
		{
			static std::vector<const EnumDescriptor*> s;
			return s;
		}

		EnumDescriptor::EnumDescriptor(const char* typeName, const type_info& type)
			: Type(typeName, type, "token"),
			  allItems(),
			  enumCount(0),
			  enumCountMSB(0)
		{
			allEnums().push_back(this);
		}

		EnumDescriptor::~EnumDescriptor()
		{
			RBXASSERT(std::find(allEnums().begin(), allEnums().end(), this) != allEnums().end());
			allEnums().erase(std::find(allEnums().begin(), allEnums().end(), this));
		}
	}
}
