// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_69c7c4c380ae2195.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("reflection/enumconverter.h", "../roc_enum_native_owner_header_b9f24b80cd6bff22.cpp")
#pragma include_alias("NetworkSettings.h", "roc_unit_dbcedf8528d38107.cpp")
#undef _RELEASEASSERT
#include "reflection/enumconverter.h"
#include "NetworkSettings.h"
#include "v8datamodel/Hopper.h"
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
