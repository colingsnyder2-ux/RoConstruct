// 2008-06 native Reflection::EnumDesc<RBX::SoundType> constructor 00629120 (inactive): defined out of line right
// after the IEquipable unit (00628f80..00629113) and before the ClickDetector unit (00629340); its only caller is
// the function-local singleton 005bb2c0 (guard 009772c8, object 009771e0, atexit 007fe4b0) in the Sound unit.
// Name "SoundType" 00845858, type descriptor 0095b3a4, EnumDesc<SoundType> vtable 00837a40, fifteen addPair calls
// (ICF-shared addPair 0064d530). Enum values from the native util/Sound.h (read-only).
// Verified by tests/record_native_script_app2008.py.
// >>> native-status (generated) -- do not edit >>>
// ScriptApp2008SoundType | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 5acdc6f7 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Reflection::EnumDesc<enum RBX::SoundType>;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::SoundType> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::SoundType> > >;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::SoundType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::SoundType> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::SoundType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::SoundType> >,0> >;
template class std::_Vector_const_iterator<enum RBX::SoundType,std::allocator<enum RBX::SoundType> >;
template class std::_Vector_iterator<enum RBX::SoundType,std::allocator<enum RBX::SoundType> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::SoundType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::SoundType> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Name const * const,enum RBX::SoundType> >;
template class std::vector<enum RBX::SoundType,std::allocator<enum RBX::SoundType> >;
