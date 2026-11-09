// >>> native-status (generated) -- do not edit >>>
// TreeNodeAddChildren | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 989379ea | roc native-status --write
#include "CRobloxTreeCtrl.h"

void CRobloxTreeCtrlNode::addChildren()
{
    for (int i = 0; i < 10; ++i) {
        boost::recursive_mutex::scoped_lock lock(tree->mutex);
        std::set<boost::shared_ptr<RBX::Instance> >::iterator it = addedChildren.begin();
        if (it == addedChildren.end()) return;
        boost::shared_ptr<RBX::Instance> child(*it);
        addedChildren.erase(it);
        lock.unlock();
        addChild(child);
    }
}
