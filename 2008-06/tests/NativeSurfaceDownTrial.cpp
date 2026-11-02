#include "NativeSurfaceToolTrial.h"
#include "util/Sound.h"
namespace RBX {
void recordCameraHistory(const char*, const Instance*);
MouseCommand* SurfaceTool::onMouseDown(const UIEvent& input) {
    onMouseHover(input);
    if (surface) {
        applyToSurface(surface);
        ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND);
        recordCameraHistory(cursor.c_str(), workspace);
        workspace->getDataState().setDirty(true);
    }
    return NULL;
}
}

