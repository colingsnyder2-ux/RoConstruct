// >>> native-status (generated) -- do not edit >>>
// ResizeToolDrag | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 5cdaa282 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ResizeTool.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"
namespace RBX {
void ResizeTool::capturedDrag(int axisDelta) {
    if (!targetPV.expired()) {
        PartInstance* part = static_cast<PartInstance*>(targetPV.lock().get());
        part->destroyJoints();
        if (part->resize(localNormalId, axisDelta))
            ServiceProvider::create<Soundscape::SoundService>(static_cast<Instance*>(workspace))->playSound(CLICK_SOUND);
        part->join();
    }
}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::PVInstance>;
template class boost::weak_ptr<RBX::PVInstance>;
