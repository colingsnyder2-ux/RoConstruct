// Native SoundService constructor 005bc160, using the shared application ABI.
#include "util/Sound.h"
#include "util/StandardOut.h"
#include <G3D/System.h>
#include <fmod.hpp>
#include <fmod_errors.h>

namespace RBX { namespace Soundscape {
SoundService::SoundService()
    : system(0),fmod_version(0),dopplerscale(1.0f),distancefactor(10.0f),
      rolloffscale(1.0f),ambientReverb(NoReverb),
      nextGarbageCollectTime(G3D::System::getTick()),mySoundDisabled(false){
    setName("Soundscape");
}
// 005bb120: ordinary member/base destruction; detachment owns FMOD shutdown.
SoundService::~SoundService(){}

// 005ba970: remove stock channels, detach cached handles, then release FMOD.
void SoundService::closeFmod(){
    stockSounds.clear();removeAllChildren();
    for(std::map<SoundId,boost::shared_ptr<Sound> >::iterator i=loadedSounds.begin();i!=loadedSounds.end();++i)
        i->second->detach();
    for(std::map<SoundId,boost::shared_ptr<Sound> >::iterator i=loaded3DSounds.begin();i!=loaded3DSounds.end();++i)
        i->second->detach();
    loadedSounds.clear();loaded3DSounds.clear();
    if(system){
        FMOD_RESULT result=system->release();
        if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
        system=0;
    }
}
} }
