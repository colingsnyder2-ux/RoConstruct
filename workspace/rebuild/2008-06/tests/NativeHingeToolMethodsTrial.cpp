#include "NativeSurfaceSiblingsTrial.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"
namespace RBX {
const std::string HingeTool::getCursorName() const { return "HingeCursor"; }
MouseCommand* HingeTool::isSticky() const { return new HingeTool(workspace); }
void HingeTool::applyToSurface(Surface* surface) {
    surface->getPartInstance()->destroyJoints();
    surface->setSurfaceType(ROTATE);
    surface->setSurfaceInput(Controller::NO_INPUT);
    surface->setParamA(0.0f);
    surface->setParamB(0.0f);
    surface->getPartInstance()->join();
}
}
