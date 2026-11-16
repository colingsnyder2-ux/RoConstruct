// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Inactive recovery. Existing util/Sound.h owns the class and its layout.
#include "util/Sound.h"
#include <algorithm>
#include "../../../../tools/openrbx/3rdparty/fmod/api/inc/fmod.hpp"
void checkResult(FMOD_RESULT result);
// INFERRED: descriptor type from get/set int signatures and original references
// at 005bd51e and 005bda43 to the registry-named global at 00977010.
extern RBX::Reflection::PropDescriptor<RBX::Soundscape::SoundChannel, int> playCountProperty;
extern RBX::Reflection::PropDescriptor<RBX::Soundscape::SoundChannel, bool> loopedProperty;
namespace RBX { namespace Soundscape {
void SoundChannel::play() // 005bd4f0
{
    playSound(this);
    playCount = (std::max)(playCount + 1, 1);
    raisePropertyChanged(playCountProperty);
}
void SoundChannel::pause() // 005bd540
{
    if (fmod_channel) checkResult(fmod_channel->setPaused(true));
    updateListenState();
    if (playCount != 0) {
        playCount = 0;
        raisePropertyChanged(playCountProperty);
    }
}
void SoundChannel::stop() // 005bd590
{
    if (fmod_channel) {
        checkResult(fmod_channel->setUserData(NULL));
        checkResult(fmod_channel->stop());
        fmod_channel = NULL;
    }
    updateListenState();
    if (playCount != -1) {
        playCount = -1;
        raisePropertyChanged(playCountProperty);
    }
}
void SoundChannel::setPlayCount(int value) // 005bda10
{
    if (value == -1) stop();
    else if (value == 0) pause();
    else if (value > playCount) {
        playSound(this);
        playCount = value;
        raisePropertyChanged(playCountProperty);
    }
}
void SoundChannel::onServiceProvider(const ServiceProvider*, const ServiceProvider*) // 005b9840
{
    if (fmod_channel) {
        checkResult(fmod_channel->setUserData(NULL));
        fmod_channel = NULL;
    }
    if (sound) {
        --sound->refCount;
        sound.reset();
    }
}
void SoundChannel::updateLooped() // 005b9890
{
    if (fmod_channel) {
        FMOD_MODE mode;
        checkResult(fmod_channel->getMode(&mode));
        mode = (mode | (looped ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF)) & (looped ? ~FMOD_LOOP_OFF : ~FMOD_LOOP_NORMAL);
        checkResult(fmod_channel->setMode(mode));
        checkResult(fmod_channel->setLoopCount(looped ? -1 : 0));
    }
}
void SoundChannel::onEvent(const RunService*, Heartbeat) // 005ba3d0
{
    SoundChannel* channel = this;
    FMOD::Channel* native = fmod_channel;
    bool paused;
    if (native && native->getPaused(&paused) != FMOD_ERR_INVALID_HANDLE && !paused)
        channel->update3D(channel->fmod_channel);
}
void SoundChannel::setLooped(bool value) // 005bd4b0
{
    if (looped != value) {
        looped = value;
        updateLooped();
        raisePropertyChanged(loopedProperty);
    }
}
} }
