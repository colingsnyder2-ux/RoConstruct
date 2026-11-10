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
