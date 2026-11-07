// >>> native-status (generated) -- do not edit >>>
// InstanceReadChildren | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src e87c5aef | roc native-status --write
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
