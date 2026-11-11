// >>> native-status (generated) -- do not edit >>>
// SoundServicePlay | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (deepseek:deepseek-flash)
// <<< native-status | src 29cc1573 | roc native-status --write
#include "util/Sound.h"

namespace RBX { namespace Soundscape {
void SoundService::playSound(SoundType type) {
    std::map<SoundType, boost::shared_ptr<SoundChannel> >::iterator it = stockSounds.find(type);
    if (it != stockSounds.end()) it->second->play();
}
} }

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::Soundscape::SoundChannel>;
template class std::_Tree<std::_Tmap_traits<enum RBX::SoundType,boost::shared_ptr<RBX::Soundscape::SoundChannel>,std::less<enum RBX::SoundType>,std::allocator<std::pair<enum RBX::SoundType const ,boost::shared_ptr<RBX::Soundscape::SoundChannel> > >,0> >;
