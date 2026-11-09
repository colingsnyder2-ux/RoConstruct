#include "StandardVerbs.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"
namespace RBX {
bool FollowCameraCommand::isEnabled() const {
    if (!(selection->size() > 0)) return false;
    FilteredSelection<PVInstance>* selected = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel));
    return selected->size() == 1;
}
bool WatchCameraCommand::isEnabled() const {
    if (!(selection->size() > 0)) return false;
    FilteredSelection<PVInstance>* selected = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel));
    return selected->size() == 1;
}
}

