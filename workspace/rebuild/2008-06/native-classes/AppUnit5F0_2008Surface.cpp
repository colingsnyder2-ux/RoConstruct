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
