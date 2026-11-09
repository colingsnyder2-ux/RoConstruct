#include "NativeSurfaceSiblingsTrial.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"
namespace RBX {
const std::string InletTool::getCursorName() const { return "InletCursor"; }
MouseCommand* InletTool::isSticky() const { return new InletTool(workspace); }
void InletTool::applyToSurface(Surface* surface) {
    surface->getPartInstance()->destroyJoints();
    surface->flat();
    surface->setSurfaceType(INLET);
    surface->getPartInstance()->join();
    ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND);
}
}
