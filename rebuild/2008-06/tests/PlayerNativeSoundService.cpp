// Native SoundService constructor 005bc160, using the shared application ABI.
#include "util/Sound.h"
#include "util/StandardOut.h"
#include "v8datamodel/GameSettings.h"
#include <G3D/System.h>
#include <fmod.hpp>
#include <fmod_errors.h>
#include <stdexcept>

// Original BSS byte 00976fc9 is initially zero; settings integration can set it.
namespace FFlag { bool SoundDisabled=false; }
#pragma comment(linker,"/alternatename:_FMOD_System_Create@4=_FMOD_System_Create")

static void checkSoundResult(FMOD_RESULT result){
    if(result!=FMOD_OK){
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
        throw std::runtime_error(FMOD_ErrorString(result));
    }
}
static void logSoundResult(FMOD_RESULT result){
    if(result!=FMOD_OK)RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
}

namespace RBX { namespace Soundscape {
SoundService::SoundService()
    : system(0),fmod_version(0),dopplerscale(1.0f),distancefactor(10.0f),
      rolloffscale(1.0f),ambientReverb(NoReverb),
      nextGarbageCollectTime(G3D::System::getTick()),mySoundDisabled(false){
    setName("Soundscape");
}
// 005bb120: ordinary member/base destruction; detachment owns FMOD shutdown.
SoundService::~SoundService(){}

// 005b97b0: apply the three reflected spatial-audio settings.
void SoundService::update3DSettings(){
    if(system){
        FMOD_RESULT result=system->set3DSettings(dopplerscale,distancefactor,rolloffscale);
        if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
    }
}

// 005ba020 is the 007f5220 descriptor callback for the same update.
void SoundService::on3DSettingChanged(const Reflection::PropertyDescriptor&){update3DSettings();}

// 005ba060: open FMOD with native driver checks and stereo fallback.
void SoundService::openFmod(){
    if(FFlag::SoundDisabled || mySoundDisabled || !GameSettings::singleton().soundEnabled)return;
    try{
        checkSoundResult(FMOD::System_Create(&system));
        checkSoundResult(system->getVersion(&fmod_version));
        if(fmod_version<0x00041406)throw std::runtime_error("Incorrect FMODEX DLL version");
        int driver=-1;logSoundResult(system->getDriver(&driver));
        if(driver<0)StandardOut::singleton()->print(MESSAGE_WARNING,"No active sound driver detected");
        unsigned caps;FMOD_SPEAKERMODE speakerMode;
        checkSoundResult(system->getDriverCaps(0,&caps,0,0,&speakerMode));
        checkSoundResult(system->setSpeakerMode(speakerMode));
        if(caps & FMOD_CAPS_HARDWARE_EMULATED){
            StandardOut::singleton()->print(MESSAGE_WARNING,"The acceleration slider in the Sound Control Panel set to 'off'");
            checkSoundResult(system->setDSPBufferSize(1024,10));
        }
        if(system->init(100,FMOD_INIT_NORMAL,0)==FMOD_ERR_OUTPUT_CREATEBUFFER){
            StandardOut::singleton()->print(MESSAGE_WARNING,"The speaker mode selected isn't supported by this soundcard.  Using Stereo");
            checkSoundResult(system->setSpeakerMode(FMOD_SPEAKERMODE_STEREO));
            checkSoundResult(system->init(100,FMOD_INIT_NORMAL,0));
        }
        update3DSettings();
        if(ambientReverb!=NoReverb)updateAmbientReverb();
    }catch(const std::exception&){
        if(system){logSoundResult(system->release());system=0;}
    }
}

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
