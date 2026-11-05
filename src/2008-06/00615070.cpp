// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_6d118bd97f069fe2.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/enumconverter.h", "../roc_enum_native_owner_header_b9f24b80cd6bff22.cpp")
#undef _RELEASEASSERT
#include "reflection/enumconverter.h"
#include "v8world/Controller.h"
#include "util/NormalId.h"
namespace RBX { namespace Reflection {
template<>
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
template<>
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
template<>
EnumDesc<NormalId>::EnumDesc() : EnumDescriptor("NormalId", typeid(NormalId))
{
	addPair(NORM_Y, "Top");
	addPair(NORM_Y_NEG, "Bottom");
	addPair(NORM_Z, "Back");
	addPair(NORM_Z_NEG, "Front");
	addPair(NORM_X, "Right");
	addPair(NORM_X_NEG, "Left");
}
} }
