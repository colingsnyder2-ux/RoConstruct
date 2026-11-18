#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surface.h"

namespace RBX {
Surface::Surface(PartInstance* partInstance, NormalId surfId)
		: partInstance(partInstance),
		  surfId(surfId)
	{
	}
}

namespace RBX {
bool Surface::isControllable() const
	{
		Controller::InputType inputType = getInput();
		return inputType != Controller::NO_INPUT && inputType != Controller::CONSTANT_INPUT && inputType != Controller::SIN_INPUT;
	}
}

#undef _RELEASEASSERT

namespace RBX {
void Surface::flat()
{
    if (partInstance->primitive.getSurfaceType(surfId) != NO_SURFACE) {
        partInstance->primitive.setSurfaceType(surfId, NO_SURFACE);
        partInstance->onSurfaceChanged(surfId);
        partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceType(surfId));
    }
    setSurfaceInput(SurfaceData::empty().inputType);
    setParamA(SurfaceData::empty().paramA);
    setParamB(SurfaceData::empty().paramB);
}
}

#undef _RELEASEASSERT
#include "v8datamodel/Surfaces.h"

namespace RBX {

SurfaceType Surface::getSurfaceType() const
{
	return partInstance->primitive.getSurfaceType(surfId);
}

void Surface::setSurfaceType(SurfaceType type)
{
	if (type != partInstance->primitive.getSurfaceType(surfId)) {
		partInstance->primitive.setSurfaceType(surfId, type);
		partInstance->onSurfaceChanged(surfId);
		partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceType(surfId));
	}
}

void Surface::setSurfaceInput(Controller::InputType value)
{
	SurfaceData data = partInstance->primitive.getSurfaceData(surfId);
	if (value != data.inputType) {
		data.inputType = value;
		partInstance->primitive.setSurfaceData(surfId, data);
		partInstance->onSurfaceChanged(surfId);
		partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceInput(surfId));
	}
}

void Surface::setParamA(float value)
{
	SurfaceData data = partInstance->primitive.getSurfaceData(surfId);
	if (data.paramA != value) {
		data.paramA = value;
		partInstance->primitive.setSurfaceData(surfId, data);
		partInstance->onSurfaceChanged(surfId);
		partInstance->raisePropertyChanged(partInstance->getSurfaces().getParamA(surfId));
	}
}

void Surface::setParamB(float value)
{
	SurfaceData data = partInstance->primitive.getSurfaceData(surfId);
	if (data.paramB != value) {
		data.paramB = value;
		partInstance->primitive.setSurfaceData(surfId, data);
		partInstance->onSurfaceChanged(surfId);
		partInstance->raisePropertyChanged(partInstance->getSurfaces().getParamB(surfId));
	}
}

}
