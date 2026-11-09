// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_unit_33b45b70bbb1f7b5.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/property.h", "roc_unit_d954c1ec545a5ee5.cpp")
#include "v8tree/Instance.h"
namespace RBX {
void Instance::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
	{
		const Name* value = NULL;

		if (const XmlAttribute* attribute = propertyElement->findAttribute(name_name))
		{
			if (reinterpret_cast<const XmlNameValuePair*>(reinterpret_cast<const char*>(attribute) + 8)->getValue(value))
			{
				Reflection::PropertyIterator iter = reinterpret_cast<Reflection::DescribedBase*>(reinterpret_cast<char*>(this) + 0x14)->findProperty(*value);

				if (iter != reinterpret_cast<Reflection::DescribedBase*>(reinterpret_cast<char*>(this) + 0x14)->properties_end())
				{
					(*iter).read(propertyElement, binder);
				}
			}
		}
	}

	
}
