#include "NativeSurfaceSiblingsTrial.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"
namespace RBX {
const std::string StudsTool::getCursorName() const { return "StudsCursor"; }
MouseCommand* StudsTool::isSticky() const { return new StudsTool(workspace); }
void StudsTool::applyToSurface(Surface* surface) {
    surface->getPartInstance()->destroyJoints();
    surface->flat();
    surface->setSurfaceType(STUDS);
    surface->getPartInstance()->join();
    ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND);
}
}
