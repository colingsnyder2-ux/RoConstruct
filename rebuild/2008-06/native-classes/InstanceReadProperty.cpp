// >>> native-status (generated) -- do not edit >>>
// InstanceReadProperty | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 9a1cb05c | roc native-status --write
#include "v8tree/Instance.h"
#include "v8xml/XmlElement.h"

void RBX::Instance::readProperty(const XmlElement* element, IReferenceBinder& binder)
{
    const Name* name = NULL;
    if (const XmlAttribute* attribute = element->findAttribute(name_name)) {
        if (attribute->getValue(name)) {
            Reflection::PropertyIterator property = findProperty(*name);
            if (property != properties_end())
                (*property).read(element, binder);
        }
    }
}
