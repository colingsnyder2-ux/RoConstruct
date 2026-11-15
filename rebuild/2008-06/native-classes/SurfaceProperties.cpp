// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surface.h"
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
