// >>> native-status (generated) -- do not edit >>>
// TreeNodeRemoveChildren | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by Espeon (deepseek:deepseek-chat)
// <<< native-status | src dce1a1c8 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<CRobloxTreeCtrlNode *> >;
template class std::_Tree<std::_Tset_traits<CRobloxTreeCtrlNode *,std::less<CRobloxTreeCtrlNode *>,std::allocator<CRobloxTreeCtrlNode *>,0> >;
template class std::_Vector_const_iterator<CRobloxTreeCtrlNode *,std::allocator<CRobloxTreeCtrlNode *> >;
template class std::_Vector_iterator<CRobloxTreeCtrlNode *,std::allocator<CRobloxTreeCtrlNode *> >;
template class std::vector<CRobloxTreeCtrlNode *,std::allocator<CRobloxTreeCtrlNode *> >;
