#include "NativeModelToolsTrial.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"
namespace RBX {
Instance* nativeFindUnanchoredPart(Instance*);
void nativeApplyAnchored(Instance*, const bool&);
MouseCommand* AnchorTool::onMouseDown(const UIEvent&) {
    if (target && !PartInstance::getLocked(target.get())) {
        bool value = nativeFindUnanchoredPart(target.get()) != NULL;
        nativeApplyAnchored(target.get(), value);
        ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND);
    }
    return this;
}
}
