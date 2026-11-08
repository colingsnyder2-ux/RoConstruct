#include "NativeSurfaceSiblingsTrial.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"
namespace RBX {
const std::string GlueTool::getCursorName() const { return "GlueCursor"; }
MouseCommand* GlueTool::isSticky() const { return new GlueTool(workspace); }
void GlueTool::applyToSurface(Surface* surface) {
    surface->getPartInstance()->destroyJoints();
    surface->flat();
    surface->setSurfaceType(GLUE);
    surface->getPartInstance()->join();
    ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND);
}
}
