// >>> native-status (generated) -- do not edit >>>
// InstanceChildAcceptance | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by Espeon (deepseek:deepseek-flash)
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
