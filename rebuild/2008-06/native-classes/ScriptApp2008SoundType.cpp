// 2008-06 native Reflection::EnumDesc<RBX::SoundType> constructor 00629120 (inactive): defined out of line right
// after the IEquipable unit (00628f80..00629113) and before the ClickDetector unit (00629340); its only caller is
// the function-local singleton 005bb2c0 (guard 009772c8, object 009771e0, atexit 007fe4b0) in the Sound unit.
// Name "SoundType" 00845858, type descriptor 0095b3a4, EnumDesc<SoundType> vtable 00837a40, fifteen addPair calls
// (ICF-shared addPair 0064d530). Enum values from the native util/Sound.h (read-only).
// Verified by tests/record_native_script_app2008.py.
#include "util/Sound.h"
#include "reflection/enumconverter.h"

namespace RBX
{
	Reflection::EnumDesc<SoundType>::EnumDesc()
		: EnumDescriptor("SoundType", typeid(SoundType))
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
}
