// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_manual_enum_36228d39c1066b69.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/enumconverter.h", "../roc_enum_native_owner_header_b9f24b80cd6bff22.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("NetworkSettings.h", "roc_unit_dbcedf8528d38107.cpp")
#undef _RELEASEASSERT
#include "util/Sound.h"
#include "reflection/enumconverter.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/Feature.h"
#include "util/SurfaceType.h"
#include "v8world/Controller.h"
#include "util/NormalId.h"
#include "v8datamodel/custommesh.h"
#include "v8datamodel/PartInstance.h"
#include "appdraw/Part.h"
#include "v8datamodel/DebugSettings.h"
#include "NetworkSettings.h"
#include "v8datamodel/Hopper.h"
#include "roc_unit_5975d468e86a7a95.cpp"
namespace RBX { namespace Reflection {
using namespace Soundscape;
template<>
EnumDesc<Soundscape::ReverbType>::EnumDesc()
	:EnumDescriptor("ReverbType", typeid(Soundscape::ReverbType))
{
	addPair(NoReverb, "NoReverb");
	addPair(GenericReverb, "GenericReverb");
	addPair(PaddedCell, "PaddedCell");
	addPair(Room, "Room");
	addPair(Bathroom, "Bathroom");
	addPair(LivingRoom, "LivingRoom");
	addPair(StoneRoom, "StoneRoom");
	addPair(Auditorium, "Auditorium");
	addPair(ConcertHall, "ConcertHall");
	addPair(Cave, "Cave");
	addPair(Arena, "Arena");
	addPair(Hangar, "Hangar");
	addPair(CarpettedHallway, "CarpettedHallway");
	addPair(Hallway, "Hallway");
	addPair(StoneCorridor, "StoneCorridor");
	addPair(Alley, "Alley");
	addPair(Forest, "Forest");
	addPair(City, "City");
	addPair(Mountains, "Mountains");
	addPair(Quarry, "Quarry");
	addPair(Plain, "Plain");
	addPair(ParkingLot, "ParkingLot");
	addPair(SewerPipe, "SewerPipe");
	addPair(UnderWater, "UnderWater");
}
} }


namespace RBX {
template<>
	
	Reflection::EnumDesc<Camera::CameraType>::EnumDesc()
		: EnumDescriptor("CameraType", typeid(Camera::CameraType))
	{
		addPair(Camera::FIXED_CAMERA, "Fixed");
		addPair(Camera::WATCH_CAMERA, "Watch");
		addPair(Camera::ATTACH_CAMERA, "Attach");
		addPair(Camera::TRACK_CAMERA, "Track");
		addPair(Camera::FOLLOW_CAMERA, "Follow");
		addPair(Camera::CUSTOM_CAMERA, "Custom");
	}
}

namespace RBX {
template<>

	Reflection::EnumDesc<Feature::TopBottom>::EnumDesc()
		: EnumDescriptor("TopBottom", typeid(Feature::TopBottom))
	{
		addPair(Feature::TOP, "Top");
		addPair(Feature::CENTER_TB, "Center");
		addPair(Feature::BOTTOM, "Bottom");
	}
}

namespace RBX {
template<>

	Reflection::EnumDesc<Feature::LeftRight>::EnumDesc()
		: EnumDescriptor("LeftRight", typeid(Feature::LeftRight))
	{
		addPair(Feature::LEFT, "Left");
		addPair(Feature::CENTER_LR, "Center");
		addPair(Feature::RIGHT, "Right");
	}
}

namespace RBX {
template<>

	Reflection::EnumDesc<Feature::InOut>::EnumDesc()
		: EnumDescriptor("InOut", typeid(Feature::InOut))
	{
		addPair(Feature::EDGE, "Edge");
		addPair(Feature::INSET, "Inset");
		addPair(Feature::CENTER_IO, "Center");
	}
}

namespace RBX {
namespace Reflection {
template<>
		EnumDesc<SurfaceType>::EnumDesc()
			: EnumDescriptor("SurfaceType", typeid(SurfaceType))
		{
			addPair(NO_SURFACE, "Smooth");
			addPair(GLUE, "Glue");
			addPair(WELD, "Weld");
			addPair(STUDS, "Studs");
			addPair(INLET, "Inlet");
			addLegacyName("Spawn", NO_SURFACE);
			addPair(ROTATE, "Hinge");
			addPair(ROTATE_V, "Motor");
			addPair(ROTATE_P, "SteppingMotor");
			addLegacyName("Bumps", GLUE);
		}
} }
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

namespace RBX { namespace Reflection {
template<>
EnumDesc<SpecialShape::MeshType>::EnumDesc() : EnumDescriptor("MeshType", typeid(SpecialShape::MeshType))
{
	addPair(SpecialShape::HEAD_MESH, "Head");
	addPair(SpecialShape::TORSO_MESH, "Torso");
	addPair(SpecialShape::WEDGE_MESH, "Wedge");
	addPair(SpecialShape::BRICK_MESH, "Brick");
	addPair(SpecialShape::SPHERE_MESH, "Sphere");
	addPair(SpecialShape::CYLINDER_MESH, "Cylinder");
	addPair(SpecialShape::FILE_MESH, "FileMesh");
}
template<>
EnumDesc<PartInstance::FormFactor>::EnumDesc() : EnumDescriptor("FormFactor", typeid(PartInstance::FormFactor))
{
	addPair(PartInstance::SYMETRIC, "Symmetric");
	addPair(PartInstance::BRICK, "Brick");
	addPair(PartInstance::PLATE, "Plate");

	addLegacyName("Block", PartInstance::BRICK);
}
template<>
EnumDesc<Part::PartType>::EnumDesc() : EnumDescriptor("PartType", typeid(Part::PartType))
{
	addPair(Part::BALL_PART, "Ball");
	addPair(Part::BLOCK_PART, "Block");
	addPair(Part::CYLINDER_PART, "Cylinder");
}
} }

namespace RBX { namespace Reflection {
template<>
EnumDesc<DebugSettings::ErrorReporting>::EnumDesc()
	: EnumDescriptor("ErrorReporting", typeid(DebugSettings::ErrorReporting))
{
	addPair(DebugSettings::DontReport, "DontReport");
	addPair(DebugSettings::Prompt, "Prompt");
	addPair(DebugSettings::Report, "Report");
}
template<>
EnumDesc<Debugable::AssertAction>::EnumDesc() : EnumDescriptor("AssertAction", typeid(Debugable::AssertAction))
{
	addPair(Debugable::CrashOnAssert, "CrashOnAssert");
	addPair(Debugable::IgnoreAssert, "IgnoreAssert");
}
template<>
EnumDesc<SoundType>::EnumDesc() : EnumDescriptor("SoundType", typeid(SoundType))
{
	addPair(NO_SOUND, "NoSound");
	addPair(BOING_SOUND, "Boing");
	addPair(BOMB_SOUND, "Bomb");
	addPair(BREAK_SOUND, "Break");
	addPair(CLICK_SOUND, "Click");
	addPair(CLOCK_SOUND, "Clock");
	addPair(RUBBERBAND_SOUND, "Slingshot");
	addPair(PAGE_SOUND, "Page");
	addPair(PING_SOUND, "Ping");
	addPair(SNAP_SOUND, "Snap");
	addPair(SPLAT_SOUND, "Splat");
	addPair(STEP_SOUND, "Step");
	addPair(STEP_ON_SOUND, "StepOn");
	addPair(SWOOSH_SOUND, "Swoosh");
	addPair(VICTORY_SOUND, "Victory");
}
} }

namespace RBX { namespace Reflection {
template<> EnumDesc<NetworkSettings::PhysicsSendMethod>::EnumDesc():EnumDescriptor("PhysicsSendMethod",typeid(NetworkSettings::PhysicsSendMethod)){
addPair(NetworkSettings::ErrorComputation,"ErrorComputation");
addPair(NetworkSettings::RoundRobin,"RoundRobin");
}
template<> EnumDesc<NetworkSettings::PhysicsReceiveMethod>::EnumDesc():EnumDescriptor("PhysicsReceiveMethod",typeid(NetworkSettings::PhysicsReceiveMethod)){
addPair(NetworkSettings::Direct,"Direct");
addPair(NetworkSettings::Interpolation,"Interpolation");
}
template<> EnumDesc<HopperBin::BinType>::EnumDesc():EnumDescriptor("BinType",typeid(HopperBin::BinType)){
addPair(HopperBin::SCRIPT_BIN,"Script");
addPair(HopperBin::GAME_TOOL,"GameTool");
addPair(HopperBin::GRAB_TOOL,"Grab");
addPair(HopperBin::CLONE_TOOL,"Clone");
addPair(HopperBin::HAMMER_TOOL,"Hammer");
addPair(HopperBin::SLINGSHOT_TOOL,"Slingshot");
addPair(HopperBin::ROCKET_TOOL,"Rocket");
addPair(HopperBin::LASER_TOOL,"Laser");
}
} }
namespace RBX { namespace Reflection {
template<> EnumDesc<CRenderSettings::GraphicsMode>::EnumDesc()
            :EnumDescriptor("GraphicsMode",typeid(::CRenderSettings::GraphicsMode))
        {
            addPair(CRenderSettings::AutoGraphicsMode, "Automatic");
            addPair(CRenderSettings::Direct3D11, "OpenGL stable");
            addPair(CRenderSettings::Direct3D9, "Direct3D experimental");
            addPair(CRenderSettings::OpenGL, "OpenGL experimental");
            addPair(CRenderSettings::NoGraphics, "No Graphics");
        }
template<> EnumDesc<CRenderSettings::FrameRateManagerMode>::EnumDesc()
			:EnumDescriptor("Framerate Manager",typeid(::CRenderSettings::FrameRateManagerMode))
		{
			addPair(CRenderSettings::FrameRateManagerAuto,"Automatic");
			addPair(CRenderSettings::FrameRateManagerOn,"On");
			addPair(CRenderSettings::FrameRateManagerOff,"Off");
		}
template<> EnumDesc<CRenderSettings::AntialiasingMode>::EnumDesc()
			:EnumDescriptor("Antialiasing",typeid(::CRenderSettings::AntialiasingMode))
		{
			addPair(CRenderSettings::AntialiasingAuto,"Automatic");
			addPair(CRenderSettings::AntialiasingOff,"Off");
			addPair(CRenderSettings::AntialiasingOn,"On");
		}
} }