#include "NativeModelToolsTrial.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"
namespace RBX {
MouseCommand* LockTool::onMouseDown(const UIEvent&) {
    if (target) {
        bool value = PartInstance::getLocked(target.get());
        PartInstance::setLocked(target.get(), !value);
        ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND);
    }
    return this;
}
}
