#include "NativeSurfaceSiblingsTrial.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "util/Math.h"
namespace RBX {
const std::string ModelSetFrontTool::getCursorName() const { return "DirectionCursor"; }
MouseCommand* ModelSetFrontTool::isSticky() const { return NULL; }
void ModelSetFrontTool::applyToSurface(Surface* surface) {
    PartInstance* part = surface->getPartInstance();
    if (ModelInstance* model = dynamic_cast<ModelInstance*>(part->getTopLevelPVParent()))
        model->setFrontAndTop(Math::getWorldNormal(surface->getNormalId(), part->getCoordinateFrame()));
}
}
