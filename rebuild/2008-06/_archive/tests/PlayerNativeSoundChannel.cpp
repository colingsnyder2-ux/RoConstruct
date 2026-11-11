// Native Sound channel constructor 005bc480, using the application ABI.
#include "util/Sound.h"
#include "util/StandardOut.h"
#include "v8datamodel/GameSettings.h"
#include "v8datamodel/Workspace.h"
#include <stdexcept>
#include <fmod.hpp>
#include <fmod_errors.h>
#pragma comment(linker,"/alternatename:_FMOD_Channel_GetUserData@8=_FMOD_Channel_GetUserData")

namespace FFlag { extern bool SoundDisabled; }
const char* sStockSound = "StockSound";
static void channelCheck(FMOD_RESULT result){
    if(result!=FMOD_OK){
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
        throw std::runtime_error(FMOD_ErrorString(result));
    }
}
namespace RBX { namespace Soundscape {
bool sanitizeSoundVector(const G3D::Vector3&,G3D::Vector3&);
static Reflection::PropDescriptor<SoundChannel,float> volumeProperty(
    "Volume","Data",&SoundChannel::getVolume,&SoundChannel::setVolume,Reflection::PropertyDescriptor::STANDARD);
static Reflection::PropDescriptor<SoundChannel,bool> loopedProperty(
    "Looped","Behavior",&SoundChannel::getLooped,&SoundChannel::setLooped,Reflection::PropertyDescriptor::STANDARD);
static Reflection::PropDescriptor<SoundChannel,bool> playingProperty(
    "IsPlaying","Data",&SoundChannel::isPlaying,0,Reflection::PropertyDescriptor::UI);
static Reflection::PropDescriptor<SoundChannel,bool> pausedProperty(
    "IsPaused","Data",&SoundChannel::isPaused,0,Reflection::PropertyDescriptor::UI);
Reflection::BoundProp<bool,1> SoundChannel::sound_desc_playOnRemove(
    "PlayOnRemove","Behavior",&SoundChannel::playOnRemove,Reflection::PropertyDescriptor::STANDARD);
static Reflection::BoundFuncDesc<SoundChannel,void(void),0> playFunction(&SoundChannel::play,"Play",Reflection::FunctionDescriptor::AnyCaller);
static Reflection::BoundFuncDesc<SoundChannel,void(void),0> pauseFunction(&SoundChannel::pause,"Pause",Reflection::FunctionDescriptor::AnyCaller);
static Reflection::BoundFuncDesc<SoundChannel,void(void),0> stopFunction(&SoundChannel::stop,"Stop",Reflection::FunctionDescriptor::AnyCaller);
static Reflection::PropDescriptor<SoundChannel,int> playCountProperty(
    "PlayCount","Data",&SoundChannel::getPlayCount,&SoundChannel::setPlayCount,Reflection::PropertyDescriptor::STREAMING);
static Reflection::PropDescriptor<SoundChannel,SoundId> soundIdProperty(
    "SoundId","Data",&SoundChannel::getSoundId,&SoundChannel::setSoundId,Reflection::PropertyDescriptor::STANDARD);
SoundChannel::SoundChannel()
    : fmod_channel(0),volume(.5f),playOnRemove(false),is3D(false),looped(false),
      soundDisabled(false),playCount(-1),part(0){
    setName("Sound");
}
// 005b7680: ordinary member/base destruction.
SoundChannel::~SoundChannel(){}

// 00565ff0: Sound accepts any parent; Instance still checks the parent's policy.
bool SoundChannel::askSetParent(const Instance*) const{return true;}

// 004e5f50 / 005bd360: update SoundId, preload in context, release old channel.
SoundId SoundChannel::getSoundId() const{return soundId;}
void SoundChannel::setSoundId(SoundId value){
    if(soundId!=value){
        soundId=value;
        if(!FFlag::SoundDisabled && !soundDisabled && GameSettings::singleton().soundEnabled &&
           ServiceProvider::findServiceProvider(this))
            ContentProvider::singleton().requestContentString(soundId);
        releaseChannel();raisePropertyChanged(soundIdProperty);
    }
}

// 005b69c0 / 005bd430: clamp volume and update a live FMOD channel.
float SoundChannel::getVolume() const{return volume;}
void SoundChannel::setVolume(float value){
    if(value<=0.0f)value=0.0f;else if(value>=1.0f)value=1.0f;
    if(volume!=value){
        volume=value;
        if(fmod_channel){FMOD_RESULT result=fmod_channel->setVolume(volume);if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));}
        raisePropertyChanged(volumeProperty);
    }
}
// 005b69d0 / 005bd4b0: keep reflected looping and FMOD mode in sync.
bool SoundChannel::getLooped() const{return looped;}
void SoundChannel::setLooped(bool value){if(looped!=value){looped=value;updateLooped();raisePropertyChanged(loopedProperty);}}
// 005b6990 / 005b6960: invalid or absent channels are not playing and are paused.
bool SoundChannel::isPlaying() const{
    if(!fmod_channel)return false;bool value=false;
    return fmod_channel->isPlaying(&value)!=FMOD_ERR_INVALID_HANDLE && value;
}
bool SoundChannel::isPaused() const{
    if(!fmod_channel)return true;bool value=true;
    return fmod_channel->getPaused(&value)==FMOD_ERR_INVALID_HANDLE || value;
}
// 005bd4f0: start playing and advance the replicated counter.
void SoundChannel::play(){playSound(this);++playCount;if(playCount<1)playCount=1;raisePropertyChanged(playCountProperty);}

// 005b65a0 / 005bda10: replicated play counter drives pause, stop and play.
int SoundChannel::getPlayCount() const{return playCount;}
void SoundChannel::setPlayCount(int value){
    if(value==-1){stop();return;}
    if(value==0){pause();return;}
    if(value>playCount){playSound(this);playCount=value;raisePropertyChanged(playCountProperty);}
}
void SoundChannel::pause(){
    if(fmod_channel){FMOD_RESULT result=fmod_channel->setPaused(true);if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));}
    updateListenState();
    if(playCount!=0){playCount=0;raisePropertyChanged(playCountProperty);}
}
void SoundChannel::stop(){
    if(fmod_channel){
        FMOD_RESULT result=fmod_channel->setUserData(0);if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
        result=fmod_channel->stop();if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
        fmod_channel=0;
    }
    updateListenState();
    if(playCount!=-1){playCount=-1;raisePropertyChanged(playCountProperty);}
}
// 005bc670 / 005bc6c0: FMOD end callback releases the channel's cache reference.
void SoundChannel::onChannelEnd(){releaseChannel();updateListenState();}
static FMOD_RESULT F_CALLBACK soundChannelCallback(FMOD_CHANNEL* channel,FMOD_CHANNEL_CALLBACKTYPE,int,unsigned int,unsigned int){
    void* value=0;FMOD_Channel_GetUserData(channel,&value);
    if(value)static_cast<SoundChannel*>(value)->onChannelEnd();
    return FMOD_OK;
}
// 005b9890: apply looping mode and count to the active channel.
void SoundChannel::updateLooped(){
    if(fmod_channel){
        FMOD_MODE mode;FMOD_RESULT result=fmod_channel->getMode(&mode);
        if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
        mode=(mode | (looped?FMOD_LOOP_NORMAL:FMOD_LOOP_OFF)) & ~(looped?FMOD_LOOP_OFF:FMOD_LOOP_NORMAL);
        result=fmod_channel->setMode(mode);if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
        result=fmod_channel->setLoopCount(looped?-1:0);if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
    }
}
// 005bceb0: resolve the provider's service and play via FMOD.
void SoundChannel::playSound(Instance* context){
    if(soundDisabled)return;
    try{
        if(looped && fmod_channel){bool playing=false;if(fmod_channel->isPlaying(&playing)!=FMOD_ERR_INVALID_HANDLE && playing){channelCheck(fmod_channel->setPaused(false));return;}}
        SoundService* service=ServiceProvider::create<SoundService>(context);
        if(!service)return;
        if(!service->system){soundDisabled=true;return;}
        releaseChannel();is3D=part!=0;sound=service->loadSound(soundId,is3D);++sound->refCount;
        FMOD::Sound* native=sound->get();if(!native)return;
        channelCheck(service->system->playSound(FMOD_CHANNEL_FREE,native,true,&fmod_channel));
        updateLooped();update3D(fmod_channel);channelCheck(fmod_channel->setVolume(volume));
        channelCheck(fmod_channel->setUserData(this));channelCheck(fmod_channel->setCallback(FMOD_CHANNEL_CALLBACKTYPE_END,soundChannelCallback,0));
        channelCheck(fmod_channel->setPaused(false));updateListenState();
    }catch(const std::exception& error){StandardOut::singleton()->print(MESSAGE_ERROR,"%s",error.what());}
}
// 005bd890: provider and workspace transitions own channel attachment.
void SoundChannel::onAncestorChanged(const AncestorChanged& event){
    const ServiceProvider* oldProvider=ServiceProvider::findServiceProvider(event.oldParent);
    const ServiceProvider* newProvider=ServiceProvider::findServiceProvider(event.newParent);
    if(oldProvider){
        Notifier<RunService,Heartbeat>::disconnect(oldProvider->create<RunService>(),this);
        if(looped)stop();releaseChannel();
    }
    Instance::onAncestorChanged(event);
    if(event.child==this){part=dynamic_cast<PartInstance*>(event.newParent);updateListenState();}
    if(newProvider){
        SoundService* service=newProvider->create<SoundService>();
        if(service && service->system){
            soundDisabled=false;
            if(!FFlag::SoundDisabled && GameSettings::singleton().soundEnabled)ContentProvider::singleton().requestContentString(soundId);
            updateListenState();if(playCount>0)playSound(this);
        }
    }
    if(oldProvider){
        Workspace* oldWorkspace=oldProvider->find<Workspace>();
        if(oldWorkspace && (event.oldParent==oldWorkspace || event.oldParent->contains(oldWorkspace))){
            Workspace* newWorkspace=newProvider?newProvider->find<Workspace>():0;
            if(newWorkspace && (event.newParent==newWorkspace || event.newParent->contains(newWorkspace)))return;
            if(playOnRemove)playSound(event.oldParent);releaseChannel();
        }
    }
}

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

// 005b97f0: detach FMOD's callback owner and release the cached Sound reference.
void SoundChannel::releaseChannel(){
    if(fmod_channel){
        FMOD_RESULT result=fmod_channel->setUserData(0);
        if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
        fmod_channel=0;
    }
    if(sound){--sound->refCount;sound.reset();}
}

// 005b9840 performs the same release when the provider changes.
void SoundChannel::onServiceProvider(const ServiceProvider*,const ServiceProvider*){releaseChannel();}

// 005bc5b0: only active spatial channels need heartbeat updates.
void SoundChannel::updateListenState(){
    RunService* runService=ServiceProvider::find<RunService>(this);
    if(part && is3D && fmod_channel)
        Notifier<RunService,Heartbeat>::connect(runService,this);
    else
        Notifier<RunService,Heartbeat>::disconnect(runService,this);
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

// 005bd250 sets the inherited archivable property to false.
StockSound::StockSound(){RBX::Instance::propArchivable.setValue(this,false);}
