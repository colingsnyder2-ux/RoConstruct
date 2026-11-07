// >>> native-status (generated) -- do not edit >>>
// InstanceSerialization | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 969415d2 | roc native-status --write
#include "../native-headers/v8tree/Instance.h"
#include "../native-headers/v8xml/XmlElement.h"

namespace RBX {
XmlElement* Instance::write() {
    if (archivable && getClassName() != Name::getNullName()) {
        XmlElement* element = new XmlElement(tag_Item);
        element->addAttribute(tag_class, &getClassName());
        element->addAttribute(name_referent, InstanceHandle(this));
        writeProperties(element->addChild(tag_Properties));
        writeChildren(element);
        return element;
    }
    return new XmlElement(tag_External, InstanceHandle(this));
}

// 00558110: serialize each child that returns an XML element.
void Instance::writeChildren(XmlElement* container) {
    if (children) {
        const std::vector<boost::shared_ptr<Instance> >& list = *children;
        for (std::vector<boost::shared_ptr<Instance> >::const_iterator it = list.begin(); it != list.end(); ++it) {
            XmlElement* element = (*it)->write();
            if (element) container->pushBackChild(element);
        }
    }
}
}
