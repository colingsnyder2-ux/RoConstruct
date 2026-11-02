#include "v8datamodel/ModelInstance.h"
namespace RBX {
void ModelInstance::onDescendentAdded(Instance* instance) {
    PVInstance::onDescendentAdded(instance);
    LocalGridExtents.setDirty();
    WorldGridExtents.setDirty();
    FlagHeight.setDirty();
    if (instance == (Instance*)candidatePrimaryPart.get()) {
        candidatePrimaryPart.reset();
        updatePrimaryPart((PartInstance*)instance);
    }
    shouldRenderSetDirty();
}
void ModelInstance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance) {
    if (primaryPart == (PartInstance*)instance.get()) primaryPart = 0;
    if (candidatePrimaryPart.get() == (PartInstance*)instance.get()) candidatePrimaryPart.reset();
    LocalGridExtents.setDirty();
    WorldGridExtents.setDirty();
    FlagHeight.setDirty();
    shouldRenderSetDirty();
    PVInstance::onDescendentRemoving(instance);
}
}
