// 005bc6f0 loader, 005ba410 destructor, existing genuine Sound declaration.
// Donor get() API resolves through the current singleton ContentProvider;
// target get(context) obtains a provider from its Instance context instead.
#include "util/Sound.h"
#include "v8datamodel/GameSettings.h"
#include "util/StandardOut.h"
#include <fmod.hpp>
#include <fmod_errors.h>
#include <cstring>
#include <stdexcept>

namespace RBX { namespace Soundscape {
typedef char NativeSoundSize[sizeof(Sound)==0x30?1:-1];
typedef char NativeSoundIdSize[sizeof(SoundId)==0x20?1:-1];
typedef char NativeCreateSoundInfoSize[sizeof(FMOD_CREATESOUNDEXINFO)==0x6c?1:-1];

Sound::Sound(FMOD::System* system,SoundId id,bool is3D)
    :fmod_sound(0),system(system),refCount(0),id(id),is3D(is3D){}

Sound::~Sound(){detach();}

void Sound::detach(){
    if(fmod_sound){
        FMOD_RESULT result=fmod_sound->release();
        if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
        fmod_sound=0;
    }
}

FMOD::Sound* Sound::get(){
    if(!fmod_sound){
        boost::shared_ptr<const std::string> data=ContentProvider::singleton().requestContentString(id);
        if(!data)return 0;
        FMOD_MODE flags=FMOD_OPENMEMORY|(is3D?FMOD_3D:0)|
            (GameSettings::singleton().softwareSound?FMOD_SOFTWARE:FMOD_HARDWARE);
        FMOD_CREATESOUNDEXINFO info;
        std::memset(&info,0,sizeof(info));info.cbsize=sizeof(info);info.length=data->size();
        FMOD_RESULT result=system->createSound(data->c_str(),flags,&info,&fmod_sound);
        if(result!=FMOD_OK){
            StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
            throw std::runtime_error(FMOD_ErrorString(result));
        }
    }
    return fmod_sound;
}

// 005bb5f0: separate caches for spatial and non-spatial sounds.
boost::shared_ptr<Sound> SoundService::loadSound(SoundId id,bool is3D){
    std::map<SoundId,boost::shared_ptr<Sound> >& cache=is3D?loaded3DSounds:loadedSounds;
    std::map<SoundId,boost::shared_ptr<Sound> >::iterator found=cache.find(id);
    if(found!=cache.end())return found->second;
    boost::shared_ptr<Sound> sound(new Sound(system,id,is3D));
    cache[id]=sound;
    return sound;
}
} }
