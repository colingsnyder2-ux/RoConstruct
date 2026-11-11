// >>> native-status (generated) -- do not edit >>>
// InstanceClassLookup | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by EspClaude (deepseek:deepseek-chat)
// <<< native-status | src 391fa34c | roc native-status --write
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
