// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// 2008-06 v8datamodel/Surface.cpp property accessors (application range 005f1290..005f1690). Flags copied from the
// sibling SurfaceFlat.cpp (Surface::flat). Surface layout from getSurfaceType 005f1290: PartInstance* at +0x0,
// NormalId at +0x4; the embedded Primitive sits at PartInstance+0x228 (surfaceType[] at +0xb8, surfaceData[] at +0xd0).
// Each setter raises the per-face descriptor from Surfaces (getSurfaceType 005eca30, getSurfaceInput 005eca90,
// getParamA 005ecaf0, getParamB 005ecb50) after PartInstance::onSurfaceChanged 005997c0.
// /fp:fast (as in PartInstanceProperties.cpp float setters): with `data.paramX != value` it gives the target fld value / fcom [paramX].
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/Surfaces.h"

namespace RBX {

// 005f1290 ?getSurfaceType@Surface@RBX@@QBE?AW4SurfaceType@2@XZ
SurfaceType Surface::getSurfaceType() const
{
	return partInstance->primitive.getSurfaceType(surfId);
}

// 005f13e0 ?setSurfaceType@Surface@RBX@@QAEXW4SurfaceType@2@@Z (calls Primitive::setSurfaceType 005e7850)
void Surface::setSurfaceType(SurfaceType type)
{
	if (type != partInstance->primitive.getSurfaceType(surfId)) {
		partInstance->primitive.setSurfaceType(surfId, type);
		partInstance->onSurfaceChanged(surfId);
		partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceType(surfId));
	}
}

// 005f1430 ?setSurfaceInput@Surface@RBX@@QAEXW4InputType@Controller@2@@Z (calls Primitive::setSurfaceData 005e7770)
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

// 005f14f0 ?setParamA@Surface@RBX@@QAEXM@Z
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

// 005f15c0 ?setParamB@Surface@RBX@@QAEXM@Z
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
