// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/util/SoundWorld.cpp

// Candidate translation unit (score above; library headers required).
#include "util/SoundWorld.h"

#include "reflection/enumconverter.h"

namespace RBX {
namespace Reflection {

// FUNCTION: WEBSERVICE 0x100e0220
// FUNCTION: ROBLOX 0x00624ac0
template <>
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

} // namespace Reflection
} // namespace RBX
