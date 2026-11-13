// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Controller out-of-line static (inactive). Declaration: the donor v8world/Controller.h
// (reached through v8datamodel/PVInstance.h, see leaves2008/NullController2008.h).
//   controllerTypeToColor 00614f80 (?controllerTypeToColor@Controller@RBX@@SA?AVColor3@G3D@@W4ControllerType@12@@Z):
//   jump table 00614fd0 indexed by type - 1: PRIMARY -> blue 00514910, SECONDARY -> red (ICF unitX 005148b0),
//   PAD_ONE / PAD_TWO -> default, AI_CHASE -> black 005149f0, AI_FLEE -> yellow 00514980, PLAYER -> purple 00514940;
//   default -> gray (ICF minFinite 00514a20). Case-body order (purple first) follows the donor switch order.
// Controller::getValue 00598a50 (fldz; ret 4) is the inline virtual body of v8world/Controller.h: not redefined.
#include "v8world/Controller.h"

namespace RBX
{
	G3D::Color3 Controller::controllerTypeToColor(ControllerType controllerType) // 00614f80
	{
		switch (controllerType)
		{
		case PLAYER_CONTROLLER:
			return G3D::Color3::purple();
		case PRIMARY_CONTROLLER:
			return G3D::Color3::blue();
		case SECONDARY_CONTROLLER:
			return G3D::Color3::red();
		case AI_CHASE_CONTROLLER:
			return G3D::Color3::black();
		case AI_FLEE_CONTROLLER:
			return G3D::Color3::yellow();
		default:
			return G3D::Color3::gray();
		}
	}
}
