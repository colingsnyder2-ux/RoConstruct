#include "NativeSurfaceSiblingsTrial.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"
namespace RBX {
const std::string WeldTool::getCursorName() const { return "WeldCursor"; }
MouseCommand* WeldTool::isSticky() const { return new WeldTool(workspace); }
void WeldTool::applyToSurface(Surface* surface) {
    surface->getPartInstance()->destroyJoints();
    surface->flat();
    surface->setSurfaceType(WELD);
    surface->getPartInstance()->join();
    ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND);
}
}
