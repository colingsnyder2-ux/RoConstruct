#include "NativeSurfaceSiblingsTrial.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"
namespace RBX {
const std::string LeftMotorTool::getCursorName() const { return "MotorCursor"; }
MouseCommand* LeftMotorTool::isSticky() const { return NULL; }
void LeftMotorTool::applyToSurface(Surface* surface) {
    surface->getPartInstance()->destroyJoints();
    surface->setSurfaceType(ROTATE_V);
    surface->setSurfaceInput(Controller::LEFT_TRACK_INPUT);
    surface->setParamA(-0.1f);
    surface->setParamB(0.1f);
    surface->getPartInstance()->join();
}
}
