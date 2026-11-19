// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "SoundChannel/SoundChannel.h"
namespace RBX { namespace Soundscape {
void logFmodResult(FMOD_RESULT);
SoundChannel::~SoundChannel() {}
SoundChannel::SoundChannel()
    : fmod_channel(0), volume(0.5f), playOnRemove(false), is3D(false), looped(false),
      soundDisabled(false), playCount(-1), part(0)
{
    setName("Sound");
}
void SoundChannel::onChannelEnd()
{
    if (fmod_channel) {
        logFmodResult(fmod_channel->setUserData(0));
        fmod_channel = 0;
    }
    if (sound) {
        --sound->refCount;
        sound.reset();
    }
    updateListenState();
}
}}
