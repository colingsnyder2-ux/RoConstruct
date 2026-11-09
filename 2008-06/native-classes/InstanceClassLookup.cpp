#include "v8tree/Instance.h"

RBX::Instance* RBX::Instance::findFirstChildByClassName(std::string className) const
{
    if (children) {
        std::vector<boost::shared_ptr<Instance> >::const_iterator end = children->end();
        for (std::vector<boost::shared_ptr<Instance> >::const_iterator it = children->begin(); it != end; ++it)
            if ((*it)->getClassNameStr() == className) return it->get();
    }
    return NULL;
}
