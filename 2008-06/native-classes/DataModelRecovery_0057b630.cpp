// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include "v8datamodel/DataModel.h"
#include "v8tree/PropertyChanged.h"

namespace RBX {
void DataModel::onChildChanged(Instance* instance, const PropertyChanged& event)
{
    Instance::onChildChanged(instance, event);
    setDirty(true);
    Instance::event_itemChanged.fire(this, shared_from(instance), &event.getProperty().getDescriptor());
}
}
