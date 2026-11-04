#include "v8datamodel/PartInstance.h"
namespace RBX {
Instance* nativeFindUnanchoredPart(Instance* instance) {
    if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
        if (!part->getAnchored()) return part;
    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > children = instance->children.read();
    if (children) {
        std::vector<boost::shared_ptr<Instance> >::const_iterator end = children->end();
        std::vector<boost::shared_ptr<Instance> >::const_iterator it = children->begin();
        for (; it != end; ++it)
            if (nativeFindUnanchoredPart(it->get())) return it->get();
    }
    return NULL;
}
}
