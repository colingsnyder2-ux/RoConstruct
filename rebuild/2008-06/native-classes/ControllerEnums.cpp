// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /U_RELEASEASSERT
// 2008-06 native Reflection::EnumDesc<Controller::InputType>::EnumDesc() 00615070 and
// EnumDesc<Controller::ControllerType>::EnumDesc() 00615280 (registry placeholders func_00615070 / func_00615280), inactive.
// Identity: both follow Controller::controllerTypeToColor 00614f80 in the Controller unit (v8world/Controller.cpp of the
// 2007 analog, which defines both specializations there) and call the EnumDescriptor(name, type_info) ctor 0056c590 with
// "InputType" 00843960 / "ControllerType" 008439b4, then addPair 0064d530 with the values and names read from the
// pushes: InputType 0 "NoInput" .. 4 "Throtle", 6 "UpDown" .. 13 "Sin" (no STRAFE_INPUT entry, as in the 2007 analog);
// ControllerType 7 "Player", 1 "KeyboardRight" .. 6 "Flee", 0 "None" (00815f14). Flags line copied from the sibling
// EnumDesc unit PartTypeEnums.cpp. The Controller unit itself has no native home yet.
#include "util/Controller.h"
#include "reflection/enumconverter.h"

namespace RBX {
namespace Reflection {

// 00615070
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

// 00615280
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

}
}
