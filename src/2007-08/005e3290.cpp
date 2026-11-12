// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/Controller.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/Controller.h"

#include "decomp.h"
#include "reflection/enumconverter.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x10059d20 FOLDED
// FUNCTION: ROBLOX 0x00407390 FOLDED
Controller::ControllerType NullController::getControllerType() const
{
	return NO_CONTROLLER;
}

// FUNCTION: WEBSERVICE 0x10099070 FOLDED
// FUNCTION: ROBLOX 0x005ad010 FOLDED
float Controller::getValue(InputType inputType) const
{
	return 0;
}

bool NullController::hasIntelligence() const
{
	return false;
}

// FUNCTION: WEBSERVICE 0x100eb790 FOLDED
bool NullController::isUserController() const
{
	return false;
}

// FUNCTION: WEBSERVICE 0x101004d0
// FUNCTION: ROBLOX 0x0061fbc0
Color3 Controller::controllerTypeToColor(ControllerType controllerType)
{
	switch (controllerType) {
	case PLAYER_CONTROLLER:
		return Color3::purple();
	case PRIMARY_CONTROLLER:
		return Color3::blue();
	case SECONDARY_CONTROLLER:
		return Color3::red();
	case AI_CHASE_CONTROLLER:
		return Color3::black();
	case AI_FLEE_CONTROLLER:
		return Color3::yellow();
	default:
		return Color3::gray();
	}
}

namespace Reflection {

// FUNCTION: WEBSERVICE 0x10100680
// FUNCTION: ROBLOX 0x0061ff30
template <>
EnumDesc<Controller::InputType>::EnumDesc() : EnumDescriptor("InputType", typeid(Controller::InputType))
{
	addPair(Controller::NO_INPUT, "NoInput");
	addPair(Controller::LEFT_TRACK_INPUT, "LeftTread");
	addPair(Controller::RIGHT_TRACK_INPUT, "RightTread");
	addPair(Controller::RIGHT_LEFT_INPUT, "Steer");
	addPair(Controller::BACK_FORWARD_INPUT, "Throtle");
	addPair(Controller::UP_DOWN_INPUT, "UpDown");
	addPair(Controller::BUTTON_1_INPUT, "Action1");
	addPair(Controller::BUTTON_2_INPUT, "Action2");
	addPair(Controller::BUTTON_3_INPUT, "Action3");
	addPair(Controller::BUTTON_4_INPUT, "Action4");
	addPair(Controller::BUTTON_3_4_INPUT, "Action5");
	addPair(Controller::CONSTANT_INPUT, "Constant");
	addPair(Controller::SIN_INPUT, "Sin");
}

// FUNCTION: WEBSERVICE 0x10100a30
// FUNCTION: ROBLOX 0x00620110
template <>
EnumDesc<Controller::ControllerType>::EnumDesc() : EnumDescriptor("ControllerType", typeid(Controller::ControllerType))
{
	addPair(Controller::PLAYER_CONTROLLER, "Player");
	addPair(Controller::PRIMARY_CONTROLLER, "KeyboardRight");
	addPair(Controller::SECONDARY_CONTROLLER, "KeyboardLeft");
	addPair(Controller::PAD_ONE_CONTROLLER, "Joypad1");
	addPair(Controller::PAD_TWO_CONTROLLER, "Joypad2");
	addPair(Controller::AI_CHASE_CONTROLLER, "Chase");
	addPair(Controller::AI_FLEE_CONTROLLER, "Flee");
	addPair(Controller::NO_CONTROLLER, "None");
}

} // namespace Reflection

} // namespace RBX
