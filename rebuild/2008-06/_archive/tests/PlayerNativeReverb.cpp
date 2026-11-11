// 005b8880: original reverb preset switch, using SDK structs and constants.
#include "PlayerNativeReverb.h"
#include "util/StandardOut.h"
#include <fmod_errors.h>

namespace RBX { namespace Soundscape {
typedef char NativeReverbSize[sizeof(FMOD_REVERB_PROPERTIES)==0x7c?1:-1];
bool nativeReverbPreset(ReverbType type,FMOD_REVERB_PROPERTIES& result){
    static const FMOD_REVERB_PROPERTIES presets[]={
        FMOD_PRESET_OFF,FMOD_PRESET_GENERIC,FMOD_PRESET_PADDEDCELL,FMOD_PRESET_PADDEDCELL,
        FMOD_PRESET_BATHROOM,FMOD_PRESET_LIVINGROOM,FMOD_PRESET_STONEROOM,FMOD_PRESET_AUDITORIUM,
        FMOD_PRESET_CONCERTHALL,FMOD_PRESET_CAVE,FMOD_PRESET_ARENA,FMOD_PRESET_HANGAR,
        FMOD_PRESET_CARPETTEDHALLWAY,FMOD_PRESET_HALLWAY,FMOD_PRESET_STONECORRIDOR,FMOD_PRESET_ALLEY,
        FMOD_PRESET_FOREST,FMOD_PRESET_CITY,FMOD_PRESET_MOUNTAINS,FMOD_PRESET_QUARRY,
        FMOD_PRESET_PLAIN,FMOD_PRESET_PARKINGLOT,FMOD_PRESET_SEWERPIPE,FMOD_PRESET_UNDERWATER
    };
    if(static_cast<unsigned>(type)>=sizeof(presets)/sizeof(presets[0]))return false;
    result=presets[type];return true;
}
void SoundService::updateAmbientReverb(){
    FMOD_REVERB_PROPERTIES preset;
    if(system && nativeReverbPreset(ambientReverb,preset)){
        FMOD_RESULT result=system->setReverbProperties(&preset);
        if(result!=FMOD_OK)StandardOut::singleton()->print(MESSAGE_WARNING,"FMOD %d: %s",result,FMOD_ErrorString(result));
    }
}
} }
