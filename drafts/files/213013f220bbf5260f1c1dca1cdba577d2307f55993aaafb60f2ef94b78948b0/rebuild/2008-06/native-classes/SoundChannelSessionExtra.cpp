// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
#include "fmod.hpp"
#include "SoundChannel/SoundChannel.h"
bool convert(const G3D::Vector3&, FMOD_VECTOR&);
namespace RBX { namespace Soundscape {
void logFmodResult(FMOD_RESULT);
SoundChannel::~SoundChannel() {}
SoundChannel::SoundChannel() : fmod_channel(0), volume(0.5f), playOnRemove(false), is3D(false), looped(false), soundDisabled(false), playCount(-1), part(0) { setName("Sound"); }
void SoundChannel::onChannelEnd() {
    if (fmod_channel) { logFmodResult(fmod_channel->setUserData(0)); fmod_channel = 0; }
    if (sound) { --sound->refCount; sound.reset(); }
    updateListenState();
}
void SoundChannel::update3D(FMOD::Channel* channel) {
    if (is3D && part) {
        FMOD_VECTOR pos;
        if (!convert(part->getCoordinateFrame().translation, pos)) return;
        FMOD_VECTOR vel;
        if (!convert(part->getVelocity().linear, vel)) return;
        logFmodResult(channel->set3DAttributes(&pos, &vel));
    }
}
}}
