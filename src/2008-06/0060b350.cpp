// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_enum_owner_expanded_family_cee52b618254f38b.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/enumconverter.h", "../roc_enum_native_owner_header_b9f24b80cd6bff22.cpp")
#undef _RELEASEASSERT
#include "util/Sound.h"
#include "reflection/enumconverter.h"
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

#include "v8datamodel/Camera.h"
#include "v8datamodel/Feature.h"
#include "util/SurfaceType.h"

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
