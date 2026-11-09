// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_e538346c28c32c80.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("reflection/enumconverter.h", "../roc_enum_native_owner_header_b9f24b80cd6bff22.cpp")
#undef _RELEASEASSERT
#include "reflection/enumconverter.h"
#include "v8datamodel/DebugSettings.h"
#include "util/Sound.h"
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
