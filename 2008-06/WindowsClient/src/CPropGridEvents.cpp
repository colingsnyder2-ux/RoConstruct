// >>> native-status (generated) -- do not edit >>>
// CPropGridEvents | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 840200f3 | roc native-status --write
#include "CPropGrid.h"
#include "v8tree/PropertyChanged.h"

void CPropGrid::onEvent(const RBX::Instance*, RBX::PropertyChanged event)
{
    boost::recursive_mutex::scoped_lock lock(mutex);
    if (!dirty) {
        std::map<const RBX::Reflection::PropertyDescriptor*, Item*>::const_iterator found =
            propertyItems.find(&event.getDescriptor());
        if (found != propertyItems.end()) pendingItems.insert(found->second);
        requestUpdate();
    }
}
