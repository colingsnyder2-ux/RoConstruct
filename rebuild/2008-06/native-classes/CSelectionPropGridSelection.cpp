// >>> native-status (generated) -- do not edit >>>
// CSelectionPropGridSelection | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 882815c0 | roc native-status --write
#include "CSelectionPropGrid.h"
#include "v8datamodel/Selection.h"
#include <algorithm>
#include <boost/bind.hpp>

void CSelectionPropGrid::setSelection(RBX::Selection* value)
{
    boost::recursive_mutex::scoped_lock lock(mutex);
    if (selection) {
        RBX::Notifier<RBX::Selection, RBX::SelectionChanged>::disconnect(selection, this);
        std::for_each(selection->selection->begin(), selection->selection->end(),
                      boost::bind(&CPropGrid::removeInstance, this, _1));
    }
    pendingItems.clear();
    groups.clear();
    selection = RBX::shared_from(value);
    if (selection) {
        std::for_each(selection->selection->begin(), selection->selection->end(),
                      boost::bind(&CPropGrid::addInstance, this, _1));
        RBX::Notifier<RBX::Selection, RBX::SelectionChanged>::connect(selection, this);
    }
    dirty = true;
    requestUpdate();
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::_bi::value<CSelectionPropGrid *>;
template class boost::_mfi::mf1<void,CPropGrid,boost::shared_ptr<RBX::Instance> >;
template class std::_Vector_const_iterator<RBX::Listener<RBX::Selection,RBX::SelectionChanged> *,std::allocator<RBX::Listener<RBX::Selection,RBX::SelectionChanged> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Selection,RBX::SelectionChanged> *,std::allocator<RBX::Listener<RBX::Selection,RBX::SelectionChanged> *> >;
template class std::vector<RBX::Listener<RBX::Selection,RBX::SelectionChanged> *,std::allocator<RBX::Listener<RBX::Selection,RBX::SelectionChanged> *> >;
