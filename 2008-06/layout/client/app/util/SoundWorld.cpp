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
