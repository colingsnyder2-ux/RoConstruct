// Rebuild glue: reflection enum descriptors rbxgs uses but never defines, in the style of rbxgs
// v8datamodel/Camera.cpp. Names are the 2008-06 Roblox.exe strings next to each enum's type name
// (e.g. "...|Laser|Rocket|Slingshot|Hammer|Grab|GameTool|BinType"); names /GF pooled elsewhere
// ("Script", "Clone", "None", "Torso", "Brick", "Top", "Left", "Ball", "Block", "Cylinder") are the
// remaining members. Behavioural reconstruction, not byte-verified.
#include "reflection/enumconverter.h"
#include "util/NormalId.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/custommesh.h"
#include "v8world/Controller.h"
#include "AppDraw/Part.h"

namespace RBX
{
	Reflection::EnumDesc<NormalId>::EnumDesc()
		: EnumDescriptor("NormalId", typeid(NormalId))
	{
		addPair(NORM_X, "Right");
		addPair(NORM_Y, "Top");
		addPair(NORM_Z, "Back");
		addPair(NORM_X_NEG, "Left");
		addPair(NORM_Y_NEG, "Bottom");
		addPair(NORM_Z_NEG, "Front");
	}

	Reflection::EnumDesc<HopperBin::BinType>::EnumDesc()
		: EnumDescriptor("BinType", typeid(HopperBin::BinType))
	{
		addPair(HopperBin::SCRIPT_BIN, "Script");
		addPair(HopperBin::GAME_TOOL, "GameTool");
		addPair(HopperBin::GRAB_TOOL, "Grab");
		addPair(HopperBin::CLONE_TOOL, "Clone");
		addPair(HopperBin::HAMMER_TOOL, "Hammer");
		addPair(HopperBin::SLINGSHOT_TOOL, "Slingshot");
		addPair(HopperBin::ROCKET_TOOL, "Rocket");
		addPair(HopperBin::LASER_TOOL, "Laser");
	}

	Reflection::EnumDesc<SpecialShape::MeshType>::EnumDesc()
		: EnumDescriptor("MeshType", typeid(SpecialShape::MeshType))
	{
		addPair(SpecialShape::HEAD_MESH, "Head");
		addPair(SpecialShape::TORSO_MESH, "Torso");
		addPair(SpecialShape::WEDGE_MESH, "Wedge");
		addPair(SpecialShape::SPHERE_MESH, "Sphere");
		addPair(SpecialShape::CYLINDER_MESH, "Cylinder");
		addPair(SpecialShape::FILE_MESH, "FileMesh");
		addPair(SpecialShape::BRICK_MESH, "Brick");
	}

	Reflection::EnumDesc<Controller::ControllerType>::EnumDesc()
		: EnumDescriptor("ControllerType", typeid(Controller::ControllerType))
	{
		addPair(Controller::NO_CONTROLLER, "None");
		addPair(Controller::PLAYER_CONTROLLER, "Player");
		addPair(Controller::PRIMARY_CONTROLLER, "KeyboardRight");
		addPair(Controller::SECONDARY_CONTROLLER, "KeyboardLeft");
		addPair(Controller::PAD_ONE_CONTROLLER, "Joypad1");
		addPair(Controller::PAD_TWO_CONTROLLER, "Joypad2");
		addPair(Controller::AI_CHASE_CONTROLLER, "Chase");
		addPair(Controller::AI_FLEE_CONTROLLER, "Flee");
	}

	Reflection::EnumDesc<Part::PartType>::EnumDesc()
		: EnumDescriptor("PartType", typeid(Part::PartType))
	{
		addPair(Part::BALL_PART, "Ball");
		addPair(Part::BLOCK_PART, "Block");
		addPair(Part::CYLINDER_PART, "Cylinder");
	}
}
