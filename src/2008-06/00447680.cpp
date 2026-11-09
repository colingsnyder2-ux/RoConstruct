// from server: 100% by colin
// from server: 35% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_fe1ffe951039446c.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/enumconverter.h", "../roc_enum_native_owner_header_b9f24b80cd6bff22.cpp")
#undef _RELEASEASSERT
#include "roc_unit_ca9b99becf5bf672.cpp"
#include "reflection/enumconverter.h"
namespace RBX { namespace Reflection {
template<> EnumDesc<CRenderSettings::AASamples>::EnumDesc()
			:EnumDescriptor("AASamples",typeid(::CRenderSettings::AASamples))
		{
			addPair(CRenderSettings::NONE, "None");
			addPair(CRenderSettings::AA4, "4");
			addPair(CRenderSettings::AA8, "8");
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
template<> EnumDesc<CRenderSettings::ShadowMode>::EnumDesc()
			:EnumDescriptor("Shadow",typeid(::CRenderSettings::ShadowMode))
		{
			addPair(CRenderSettings::ShadowModeAuto,"Automatic");
			addPair(CRenderSettings::ShadowModeOn,"On");
			addPair(CRenderSettings::ShadowModeOff,"Off");
		}
template<> EnumDesc<CRenderSettings::BevelMode>::EnumDesc()
			:EnumDescriptor("Bevels",typeid(::CRenderSettings::BevelMode))
		{
			addPair(CRenderSettings::BevelModeAuto,"Automatic");
			addPair(CRenderSettings::BevelModeOn,"On");
			addPair(CRenderSettings::BevelModeOff,"Off");
		}
} }
