// >>> native-status (generated) -- do not edit >>>
// TreeNodeAddChildren | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src bac97f51 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Tree<std::_Tset_traits<boost::shared_ptr<RBX::Instance>,std::less<boost::shared_ptr<RBX::Instance> >,std::allocator<boost::shared_ptr<RBX::Instance> >,0> >;
