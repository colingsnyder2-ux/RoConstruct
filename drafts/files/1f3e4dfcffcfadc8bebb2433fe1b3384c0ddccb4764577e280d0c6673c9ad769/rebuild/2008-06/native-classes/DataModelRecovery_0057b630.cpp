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

// DataModel vtable 008303cc slots 5 / 6 (vtable-slot-base over ??_7ServiceProvider slots 5 / 6, onDescendentAdded
// 005726a0 / onDescendentRemoving 005726c0): each calls the ServiceProvider override, then setDirty(true) through the
// IDataState subobject at +0x1f0 (virtual slot 0, tail call). Needs both overrides declared in the core headers
// v8tree/Service.h (ServiceProvider, protected) and v8datamodel/DataModel.h (DataModel, protected); proposal.
// Define DATAMODEL_HEADER_DECLARES_DESCENDENT_HOOKS (or drop the guard) once they are declared.
#ifdef DATAMODEL_HEADER_DECLARES_DESCENDENT_HOOKS
namespace RBX {
// 0057b040
void DataModel::onDescendentAdded(Instance* instance)
{
    ServiceProvider::onDescendentAdded(instance);
    setDirty(true);
}

// 0057b070
void DataModel::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
{
    ServiceProvider::onDescendentRemoving(instance);
    setDirty(true);
}
}
#endif
