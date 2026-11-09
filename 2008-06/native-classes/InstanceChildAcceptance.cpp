// >>> native-status (generated) -- do not edit >>>
// InstanceChildAcceptance | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src f502ecc8 | roc native-status --write
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
