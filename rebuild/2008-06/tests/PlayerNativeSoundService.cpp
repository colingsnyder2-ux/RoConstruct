// Native SoundService constructor 005bc160, using the shared application ABI.
#include "util/Sound.h"
#include <G3D/System.h>

namespace RBX { namespace Soundscape {
SoundService::SoundService()
    : system(0),fmod_version(0),dopplerscale(1.0f),distancefactor(10.0f),
      rolloffscale(1.0f),ambientReverb(NoReverb),
      nextGarbageCollectTime(G3D::System::getTick()),mySoundDisabled(false){
    setName("Soundscape");
}
// 005bb120: ordinary member/base destruction; detachment owns FMOD shutdown.
SoundService::~SoundService(){}
} }
