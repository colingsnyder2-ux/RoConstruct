// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_17a2063a9f68116b.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/enumconverter.h", "../roc_enum_native_owner_header_b9f24b80cd6bff22.cpp")
#undef _RELEASEASSERT
#include "roc_unit_5975d468e86a7a95.cpp"
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
} }
