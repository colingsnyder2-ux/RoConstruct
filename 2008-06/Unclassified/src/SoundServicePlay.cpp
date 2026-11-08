// >>> native-status (generated) -- do not edit >>>
// SoundServicePlay | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src e9898e9d | roc native-status --write
#include "util/Sound.h"

namespace RBX { namespace Soundscape {
void SoundService::playSound(SoundType type) {
    std::map<SoundType, boost::shared_ptr<SoundChannel> >::iterator it = stockSounds.find(type);
    if (it != stockSounds.end()) it->second->play();
}
} }
