// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// ModelInstance | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 8fcb6b6b | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::ComputeProp<RBX::Extents,RBX::ModelInstance>;
