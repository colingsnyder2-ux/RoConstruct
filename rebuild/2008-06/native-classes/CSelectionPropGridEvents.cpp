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
