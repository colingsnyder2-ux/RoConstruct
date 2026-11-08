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
