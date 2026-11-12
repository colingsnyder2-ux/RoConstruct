// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// v8datamodel/Surface.cpp rows 005f1270..005f15c0 of the application range 005f0000..005f8000 (inactive 2008-06
// native recovery). Surface.flat 005f1690 is native-classes/SurfaceFlat.cpp (compiled read-only by the recorder).
// Layout: Surface is { PartInstance* partInstance (+0); NormalId surfId (+4) } (ctor 005f1270 stores both, ret 8);
// the 2008 PartInstance embeds its Primitive at +0x228 (native-headers/part-embedded), whose surfaceType[6] is at
// Primitive +0xb8 (setSurfaceType 005f13e0 compares [part + id*4 + 0x2e0]) and surfaceData[6] at +0xd0
// (getInput 005f12a0 reads [part + 0x228 + id*4 + 0xd0]).
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surface.h"

namespace RBX
{
	Surface::Surface(PartInstance* partInstance, NormalId surfId)
		: partInstance(partInstance),
		  surfId(surfId)
	{
	}

	SurfaceType Surface::getSurfaceType() const
	{
		return partInstance->getPrimitive()->getSurfaceType(surfId);
	}

	Controller::InputType Surface::getInput() const
	{
		return partInstance->getPrimitive()->getSurfaceData(surfId).inputType;
	}

	float Surface::getParamA() const
	{
		return partInstance->getPrimitive()->getSurfaceData(surfId).paramA;
	}

	float Surface::getParamB() const
	{
		return partInstance->getPrimitive()->getSurfaceData(surfId).paramB;
	}

	bool Surface::isControllable() const
	{
		Controller::InputType inputType = getInput();
		return inputType != Controller::NO_INPUT && inputType != Controller::CONSTANT_INPUT && inputType != Controller::SIN_INPUT;
	}

	void Surface::setSurfaceType(SurfaceType type)
	{
		if (type != getSurfaceType())
		{
			partInstance->getPrimitive()->setSurfaceType(surfId, type);
			partInstance->onSurfaceChanged(surfId);
			partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceType(surfId));
		}
	}

	void Surface::setSurfaceInput(Controller::InputType value)
	{
		SurfaceData current = partInstance->getPrimitive()->getSurfaceData(surfId);
		if (value != current.inputType)
		{
			current.inputType = value;
			partInstance->getPrimitive()->setSurfaceData(surfId, current);
			partInstance->onSurfaceChanged(surfId);
			partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceInput(surfId));
		}
	}

	void Surface::setParamA(float value)
	{
		SurfaceData current = partInstance->getPrimitive()->getSurfaceData(surfId);
		if (current.paramA != value)
		{
			current.paramA = value;
			partInstance->getPrimitive()->setSurfaceData(surfId, current);
			partInstance->onSurfaceChanged(surfId);
			partInstance->raisePropertyChanged(partInstance->getSurfaces().getParamA(surfId));
		}
	}

	void Surface::setParamB(float value)
	{
		SurfaceData current = partInstance->getPrimitive()->getSurfaceData(surfId);
		if (current.paramB != value)
		{
			current.paramB = value;
			partInstance->getPrimitive()->setSurfaceData(surfId, current);
			partInstance->onSurfaceChanged(surfId);
			partInstance->raisePropertyChanged(partInstance->getSurfaces().getParamB(surfId));
		}
	}
}
