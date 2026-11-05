// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_serializer_loadinstances_native_890d0f4bc41911b9.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8xml/XmlElement.h", "../roc_serializer_xmlelement_double_header_e504401e7c2c46c3.cpp")
#include "v8xml/SerializerV2.h"
#include "util/standardout.h"
#include <G3D/Log.h>

void SerializerV2::loadInstances(XmlElement* root, std::vector<boost::shared_ptr<RBX::Instance> >& result)
{
	if (root->getTag() == tag_roblox)
	{
		XmlAttribute* versionAttribute = root->findAttribute(tag_version);
		if (versionAttribute && versionAttribute->getValue(schemaVersionLoading) && schemaVersionLoading >= 4)
		{
			ArchiveBinder binder;
			const XmlElement* item = root->findFirstChildByTag(tag_Item);
			while (item != NULL)
			{
				const RBX::Name* className = NULL;
				if (item->findAttributeValue(tag_class, className))
				{
					boost::shared_ptr<RBX::Instance> instance = RBX::AbstractFactoryProduct<RBX::Instance>::create(*className);
					if (instance != NULL)
					{
						instance->read(item, binder);
						result.push_back(instance);
					}
					else
						RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING, "Unknown object class \"%s\" while reading XML", className ? className->c_str() : "");
				}
				item = root->findNextChildWithSameTag(item);
			}
			binder.resolveRefs();
			return;
		}
	}

	G3D::Log::common()->println("Version 1.0 - 3.0 model files not supported - all future version will be supported");
}
