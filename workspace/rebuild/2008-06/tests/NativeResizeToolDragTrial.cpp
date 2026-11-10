#include "NativeResizeToolTrial.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"
namespace RBX {
void ResizeTool::capturedDrag(int axisDelta) {
    if (!targetPV.expired()) {
        PartInstance* part = static_cast<PartInstance*>(targetPV.lock().get());
        part->destroyJoints();
        if (part->resize(localNormalId, axisDelta))
            ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(CLICK_SOUND);
        part->join();
    }
}
}
