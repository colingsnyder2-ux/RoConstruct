// =============================================================================
// SoundWorld.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/util/SoundWorld.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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

// Explicit instantiations: they give this file the same symbols as the original object,
// where other files used them. Likely removable once the whole client links and those users exist.
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
