// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
#undef _RELEASEASSERT
// >>> native-status (generated) -- do not edit >>>
// AppUnit5F0_2008Surface | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 306258b1 | roc native-status --write
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

namespace RBX {
SurfaceType Surface::getSurfaceType() const { return partInstance->primitive.getSurfaceType(surfId); }
Controller::InputType Surface::getInput() const { return partInstance->primitive.getSurfaceData(surfId).inputType; }
float Surface::getParamA() const { return partInstance->primitive.getSurfaceData(surfId).paramA; }
float Surface::getParamB() const { return partInstance->primitive.getSurfaceData(surfId).paramB; }
}

namespace RBX {
void Surface::setSurfaceType(SurfaceType value) {
    if (value != partInstance->primitive.getSurfaceType(surfId)) {
        partInstance->primitive.setSurfaceType(surfId, value);
        partInstance->onSurfaceChanged(surfId);
        partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceType(surfId));
    }
}
void Surface::setSurfaceInput(Controller::InputType value) {
    SurfaceData data = partInstance->primitive.getSurfaceData(surfId);
    if (value != data.inputType) {
        data.inputType = value;
        partInstance->primitive.setSurfaceData(surfId, data);
        partInstance->onSurfaceChanged(surfId);
        partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceInput(surfId));
    }
}
void Surface::setParamA(float value) {
    SurfaceData data = partInstance->primitive.getSurfaceData(surfId);
    if (value != data.paramA) {
        data.paramA = value;
        partInstance->primitive.setSurfaceData(surfId, data);
        partInstance->onSurfaceChanged(surfId);
        partInstance->raisePropertyChanged(partInstance->getSurfaces().getParamA(surfId));
    }
}
void Surface::setParamB(float value) {
    SurfaceData data = partInstance->primitive.getSurfaceData(surfId);
    if (value != data.paramB) {
        data.paramB = value;
        partInstance->primitive.setSurfaceData(surfId, data);
        partInstance->onSurfaceChanged(surfId);
        partInstance->raisePropertyChanged(partInstance->getSurfaces().getParamB(surfId));
    }
}
}
