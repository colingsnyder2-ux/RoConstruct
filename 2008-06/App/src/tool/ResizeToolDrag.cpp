// >>> native-status (generated) -- do not edit >>>
// ResizeToolDrag | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 111dc4a3 | roc native-status --write
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
