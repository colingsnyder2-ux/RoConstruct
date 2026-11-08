// >>> native-status (generated) -- do not edit >>>
// TreeNodeRemoveChildren | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 87bec7c8 | roc native-status --write
#include "CRobloxTreeCtrl.h"
#include <algorithm>
#include <vector>

typedef std::vector<CRobloxTreeCtrlNode*> NodeVector;
struct CollectRemovedNode {
    typedef void (NodeVector::*Callback)(CRobloxTreeCtrlNode* const&);
    Callback callback;
    NodeVector* values;
    CollectRemovedNode(Callback method, NodeVector* target) : callback(method), values(target) {}
    void operator()(CRobloxTreeCtrlNode* const& node) const { (values->*callback)(node); }
};

void CRobloxTreeCtrlNode::removeChildren()
{
    NodeVector values;
    {
        boost::recursive_mutex::scoped_lock lock(tree->mutex);
        std::for_each(removedChildren.begin(), removedChildren.end(),
            CollectRemovedNode(&NodeVector::push_back, &values));
        removedChildren.clear();
    }
    for (NodeVector::iterator it = values.begin(); it != values.end(); ++it)
        tree->DeleteItem((*it)->item);
}
