// >>> native-status (generated) -- do not edit >>>
// CSelectionPropGridEvents | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src b8fc85e1 | roc native-status --write
#include "CSelectionPropGrid.h"
#include "v8datamodel/SelectionChanged.h"

void CSelectionPropGrid::onEvent(const RBX::Selection*, RBX::SelectionChanged event)
{
    if (event.addedItem) addInstance(event.addedItem);
    if (event.removedItem) removeInstance(event.removedItem);
    boost::recursive_mutex::scoped_lock lock(mutex);
    dirty = true;
    pendingItems.clear();
    requestUpdate();
}
