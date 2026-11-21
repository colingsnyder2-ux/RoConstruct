// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "SoundChannel/SoundChannel.h"
namespace RBX { namespace Soundscape {
void logFmodResult(FMOD_RESULT);
static Reflection::PropDescriptor<SoundChannel, float> sound_desc_Volume("Volume", "Data", &SoundChannel::getVolume, &SoundChannel::setVolume, Reflection::PropertyDescriptor::STANDARD);
void SoundChannel::setVolume(float value)
{
    value = G3D::clamp(value, 0.0f, 1.0f);
    if (volume != value) {
        volume = value;
        if (fmod_channel)
            logFmodResult(fmod_channel->setVolume(volume));
        raisePropertyChanged(sound_desc_Volume);
    }
}
}}
