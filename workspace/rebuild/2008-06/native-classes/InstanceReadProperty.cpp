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
