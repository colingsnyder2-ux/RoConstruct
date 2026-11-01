// Native Sound channel constructor 005bc480, using the application ABI.
#include "util/Sound.h"
#include "util/StandardOut.h"
#include <fmod.hpp>
#include <fmod_errors.h>

namespace RBX { namespace Soundscape {
bool sanitizeSoundVector(const G3D::Vector3&,G3D::Vector3&);
SoundChannel::SoundChannel()
    : fmod_channel(0),volume(.5f),playOnRemove(false),is3D(false),looped(false),
      soundDisabled(false),playCount(-1),part(0){
    setName("Sound");
}
// 005b7680: ordinary member/base destruction.
SoundChannel::~SoundChannel(){}

// 00565ff0: Sound accepts any parent; Instance still checks the parent's policy.
bool SoundChannel::askSetParent(const Instance*) const{return true;}

// 005b9920: transfer the owning Part's position and linear velocity to FMOD.
void SoundChannel::update3D(FMOD::Channel* channel){
    if(is3D && part){
        G3D::Vector3 position,velocity;
        if(sanitizeSoundVector(part->getCoordinateFrame().translation,position) &&
           sanitizeSoundVector(part->getVelocity().linear,velocity)){
            FMOD_VECTOR p={position.x,position.y,position.z};
            FMOD_VECTOR v={velocity.x,velocity.y,velocity.z};
            FMOD_RESULT result=channel->set3DAttributes(&p,&v);
            if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
        }
    }
}

// 005b9840: detach FMOD's callback owner and release the cached Sound reference.
void SoundChannel::onServiceProvider(const ServiceProvider*,const ServiceProvider*){
    if(fmod_channel){
        FMOD_RESULT result=fmod_channel->setUserData(0);
        if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
        fmod_channel=0;
    }
    if(sound){--sound->refCount;sound.reset();}
}

// 005ba3d0: refresh a live, unpaused channel's spatial state.
void SoundChannel::onEvent(const RunService*,Heartbeat){
    if(fmod_channel){
        bool paused;
        if(fmod_channel->getPaused(&paused)!=FMOD_ERR_INVALID_HANDLE && !paused)
            update3D(fmod_channel);
    }
}
} }
