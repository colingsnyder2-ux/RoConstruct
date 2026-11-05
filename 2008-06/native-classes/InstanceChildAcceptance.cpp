#include "v8tree/Instance.h"

bool RBX::Instance::canAcceptChildren(std::vector<boost::shared_ptr<Instance> >::const_iterator first,
                                      std::vector<boost::shared_ptr<Instance> >::const_iterator last)
{
    for (; first != last; ++first) {
        Instance* child = first->get();
        if (!child || child->contains(this) || child->getParent() == this ||
            (!askAddChild(child) && !child->askSetParent(this)))
            return false;
    }
    return true;
}
