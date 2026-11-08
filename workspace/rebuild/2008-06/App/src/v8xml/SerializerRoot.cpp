#include "../../../native-headers/v8xml/XmlElement.h"
#include "v8xml/SerializerV2.h"

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
