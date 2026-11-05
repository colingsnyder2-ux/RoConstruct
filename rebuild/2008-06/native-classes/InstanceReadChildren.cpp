#include "v8tree/Instance.h"
#include "v8xml/XmlElement.h"
namespace RBX {
void Instance::readChildren(const XmlElement* element, IReferenceBinder& binder)
{
    if (element) {
        for (const XmlElement* child = element->findFirstChildByTag(tag_Item); child;
             child = element->findNextChildWithSameTag(child)) {
            readChild(child, binder);
        }
    }
}
}
