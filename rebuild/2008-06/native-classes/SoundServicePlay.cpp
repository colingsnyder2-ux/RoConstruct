#include "util/Sound.h"

namespace RBX { namespace Soundscape {
void SoundService::playSound(SoundType type) {
    std::map<SoundType, boost::shared_ptr<SoundChannel> >::iterator it = stockSounds.find(type);
    if (it != stockSounds.end()) it->second->play();
}
} }
