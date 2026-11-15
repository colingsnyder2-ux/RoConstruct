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
