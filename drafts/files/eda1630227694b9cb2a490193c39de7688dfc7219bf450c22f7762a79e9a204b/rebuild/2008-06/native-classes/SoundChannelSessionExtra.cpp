// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
#include "fmod.hpp"
#include "SoundChannel/SoundChannel.h"
bool convert(const G3D::Vector3&, FMOD_VECTOR&);
namespace RBX { namespace Soundscape {
void logFmodResult(FMOD_RESULT);
// SoundChannel ctor 005bc480, dtor 005b7680 and onChannelEnd 005bc670 are exact in SoundChannelRecovery.cpp;
// they are not repeated here.
// 005b9920
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
