// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /U_RELEASEASSERT
// 2008-06 native EnumDesc<T>::EnumDesc() for the seven enums the donor-free link found without a definition (the boot
// probe work/donorfree-route/make_stubs.py + boot.py hit them first): CRenderSettings AASamples 00447060, GraphicsMode
// 004471e0, FrameRateManagerMode 00447380, AntialiasingMode 00447500, BevelMode 00447680, ShadowMode 00447800, and
// SurfaceType 0064d750. Names and values are read from each body's EnumDescriptor ctor 0056c590 / addPair 0064d530 pushes
// (work/donorfree-route/enum_ctors.py lists every such body in the exe). SurfaceType ends with the legacy name "Bumps" -> 1
// (Name::declare 00553f90 then a map slot set to 1, i.e. nameToEnumLegacy). Flags line copied from ControllerEnums.cpp.
#include "CRenderSettings.h"
#include "util/SurfaceType.h"
#include "reflection/enumconverter.h"

namespace RBX {
namespace Reflection {

// 00447060
template <>
EnumDesc<CRenderSettings::AASamples>::EnumDesc() : EnumDescriptor("AASamples", typeid(CRenderSettings::AASamples))
{
	addPair(CRenderSettings::NONE, "None");
	addPair(CRenderSettings::AA4, "4");
	addPair(CRenderSettings::AA8, "8");
}

// 004471e0
template <>
EnumDesc<CRenderSettings::GraphicsMode>::EnumDesc() : EnumDescriptor("GraphicsMode", typeid(CRenderSettings::GraphicsMode))
{
	addPair(CRenderSettings::AutoGraphicsMode, "Automatic");
	addPair(CRenderSettings::Direct3D11, "OpenGL stable");
	addPair(CRenderSettings::Direct3D9, "Direct3D experimental");
	addPair(CRenderSettings::OpenGL, "OpenGL experimental");
	addPair(CRenderSettings::NoGraphics, "No Graphics");
}

// 00447380
template <>
EnumDesc<CRenderSettings::FrameRateManagerMode>::EnumDesc() : EnumDescriptor("Framerate Manager", typeid(CRenderSettings::FrameRateManagerMode))
{
	addPair(CRenderSettings::FrameRateManagerAuto, "Automatic");
	addPair(CRenderSettings::FrameRateManagerOn, "On");
	addPair(CRenderSettings::FrameRateManagerOff, "Off");
}

// 00447500: Off is added before On.
template <>
EnumDesc<CRenderSettings::AntialiasingMode>::EnumDesc() : EnumDescriptor("Antialiasing", typeid(CRenderSettings::AntialiasingMode))
{
	addPair(CRenderSettings::AntialiasingAuto, "Automatic");
	addPair(CRenderSettings::AntialiasingOff, "Off");
	addPair(CRenderSettings::AntialiasingOn, "On");
}

// 00447680
template <>
EnumDesc<CRenderSettings::BevelMode>::EnumDesc() : EnumDescriptor("Bevels", typeid(CRenderSettings::BevelMode))
{
	addPair(CRenderSettings::BevelModeAuto, "Automatic");
	addPair(CRenderSettings::BevelModeOn, "On");
	addPair(CRenderSettings::BevelModeOff, "Off");
}

// 00447800
template <>
EnumDesc<CRenderSettings::ShadowMode>::EnumDesc() : EnumDescriptor("Shadow", typeid(CRenderSettings::ShadowMode))
{
	addPair(CRenderSettings::ShadowModeAuto, "Automatic");
	addPair(CRenderSettings::ShadowModeOn, "On");
	addPair(CRenderSettings::ShadowModeOff, "Off");
}

// 0064d750
template <>
EnumDesc<SurfaceType>::EnumDesc() : EnumDescriptor("SurfaceType", typeid(SurfaceType))
{
	addPair(NO_SURFACE, "Smooth");
	addPair(GLUE, "Glue");
	addPair(WELD, "Weld");
	addPair(STUDS, "Studs");
	addPair(INLET, "Inlet");
	addPair(SPAWN_deprecated, "Spawn");
	addPair(ROTATE, "Hinge");
	addPair(ROTATE_V, "Motor");
	addPair(ROTATE_P, "SteppingMotor");
	addLegacyName("Bumps", GLUE);
}

}
}
