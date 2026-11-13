// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native SoundChannel members of the util/Sound.cpp unit (inactive).
// Class layout from util/Sound.h, confirmed by the original accesses: Listener<RunService, Heartbeat> base +0x130,
// sound +0x134/+0x138, fmod_channel +0x13c, soundId +0x140, volume +0x160, playOnRemove +0x164, the bit fields at
// +0x165 (is3D bit 0, looped bit 1, soundDisabled bit 2), playCount +0x168, part +0x16c.
// Property descriptors referenced by address: playCountProperty 00977010, loopedProperty 00977118.
#include "util/Sound.h"
#include "util/RunStateOwner.h"
#include "v8tree/Service.h"
#include "v8datamodel/Workspace.h"
#include "SoundChannel/SoundChannel.h"

namespace RBX
{
	namespace Soundscape
	{
		// INFERRED: names. 005b87a0 logs a failed FMOD result through StandardOut (no throw); 005b6fe0 formats the same
		// message and throws std::runtime_error. Both are cdecl, one FMOD_RESULT argument (add esp, 4 at every call).
		void logFmodResult(FMOD_RESULT result);   // 005b87a0
		void checkFmodResult(FMOD_RESULT result); // 005b6fe0

		extern Reflection::PropDescriptor<SoundChannel, int> playCountProperty; // 00977010
		extern Reflection::PropDescriptor<SoundChannel, bool> loopedProperty;   // 00977118

		void SoundChannel::releaseChannel() // 005b97f0
		{
			if (fmod_channel)
			{
				logFmodResult(fmod_channel->setUserData(0));
				fmod_channel = 0;
			}
			if (sound)
			{
				sound->refCount--;
				sound.reset();
			}
		}

		void SoundChannel::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider) // 005b9840
		{
			releaseChannel();
		}

		void SoundChannel::updateLooped() // 005b9890
		{
			if (fmod_channel)
			{
				FMOD_MODE mode;
				logFmodResult(fmod_channel->getMode(&mode));
				mode = (mode | (looped ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF)) & (looped ? ~FMOD_LOOP_OFF : ~FMOD_LOOP_NORMAL);
				logFmodResult(fmod_channel->setMode(mode));
				logFmodResult(fmod_channel->setLoopCount(looped ? -1 : 0));
			}
		}

		void SoundChannel::setLooped(bool value) // 005bd4b0
		{
			if (looped != value)
			{
				looped = value;
				updateLooped();
				raisePropertyChanged(loopedProperty);
			}
		}

		void SoundChannel::play() // 005bd4f0
		{
			playSound(this);
			playCount = std::max(playCount + 1, 1);
			raisePropertyChanged(playCountProperty);
		}

		void SoundChannel::pause() // 005bd540
		{
			if (fmod_channel)
				logFmodResult(fmod_channel->setPaused(true));
			updateListenState();
			if (playCount != 0)
			{
				playCount = 0;
				raisePropertyChanged(playCountProperty);
			}
		}

		void SoundChannel::stop() // 005bd590
		{
			if (fmod_channel)
			{
				logFmodResult(fmod_channel->setUserData(0));
				logFmodResult(fmod_channel->stop());
				fmod_channel = 0;
			}
			updateListenState();
			if (playCount != -1)
			{
				playCount = -1;
				raisePropertyChanged(playCountProperty);
			}
		}

		void SoundChannel::setPlayCount(int value) // 005bda10
		{
			if (value == -1)
				stop();
			else if (value == 0)
				pause();
			else if (value > playCount)
			{
				playSound(this);
				playCount = value;
				raisePropertyChanged(playCountProperty);
			}
		}
	}
}
