// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// >>> native-status (generated) -- do not edit >>>
// SerializerRoot | 2008-06 | 9 byte-exact, inactive (not link-selected)
// 9/9 mapped addresses byte-exact | named 2 | 0 unproved | no mapped strings | by auto (+3) (mixed 3)
// <<< native-status | src 53f62ba5 | roc native-status --write
#include "../native-headers/v8xml/XmlElement.h"
#include "v8xml/SerializerV2.h"
#include "v8xml/XmlSerializer.h"
#include "v8datamodel/DataModel.h"

// 00591a30: create the native place XML root and external references.
XmlElement* SerializerV2::newRootElement() {
    static const RBX::Name& tag_xmlnsxmime = RBX::Name::declare("xmlns:xmime", -1);
    XmlElement* root = new XmlElement(tag_roblox);
    root->addAttribute(tag_xmlnsxmime, "http://www.w3.org/2005/05/xmlmime");
    root->addAttribute(tag_xmlnsxsi, "http://www.w3.org/2001/XMLSchema-instance");
    root->addAttribute(tag_xsinoNamespaceSchemaLocation, "http://www.roblox.com/roblox.xsd");
    root->addAttribute(tag_version, 4);
    root->pushBackChild(new XmlElement(tag_External, &value_IDREF_null));
    root->pushBackChild(new XmlElement(tag_External, &value_IDREF_nil));
    return root;
}

void SerializerV2::loadXML(std::istream& stream, RBX::DataModel* dataModel)
{
	TextXmlParser machine(stream.rdbuf());
	std::auto_ptr<XmlElement> root = machine.parse();

	if (root->getTag() == tag_roblox)
	{
		XmlAttribute* version = root->findAttribute(tag_version);
		if (!version->getValue(schemaVersionLoading))
			throw std::runtime_error("SerializerV2::loadXML no version number");

		if (schemaVersionLoading < 4)
			throw std::runtime_error("SerializerV2::loadXML schemaVersionLoading<4");

		load(root.get(), dataModel);
		dataModel->setDirty(false);
	}
	else
	{
		schemaVersionLoading = 1;
		throw std::runtime_error("SerializerV2::loadXML ill-formed XML. No Roblox tag");
	}
}
