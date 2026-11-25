// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
// 2008-06 native SoundChannel members of the util/Sound.cpp unit (inactive).
// Declarations: native-headers/SoundChannel/SoundChannel.h, the unit-local redeclaration of util/Sound.h (Sound::get
// takes the context; the extra private member 005bc610; isPaused defined in the class) plus the FMOD Ex API subset.
// Class layout as util/Sound.h, confirmed by the original accesses: Listener<RunService, Heartbeat> base +0x130,
// sound +0x134/+0x138, fmod_channel +0x13c, soundId +0x140, volume +0x160, playOnRemove +0x164, the bit fields at
// +0x165 (is3D bit 0, looped bit 1, soundDisabled bit 2), playCount +0x168, part +0x16c.
// Property descriptors referenced by address: playCountProperty 00977010, loopedProperty 00977118.
// NativeContentProvider.h first: it declares the 2008 ContentProvider (ContentProvider::sub_00562730) and consumes
// the donor util/ContentProvider.h include (ContentId) that SoundChannel.h repeats.
// The FMOD Ex SDK header (as AppUnit5B4SoundReflection.cpp uses it) ahead of SoundChannel.h's API subset: Sound::get
// needs System::createSound and FMOD_CREATESOUNDEXINFO, which the subset does not declare.
#include <fmod.hpp>
#include "util/NativeContentProvider.h"
#include "v8datamodel/GameSettings.h"
#include "SoundChannel/SoundChannel.h"
#include "v8datamodel/Workspace.h"
#include "util/standardout.h"
#include <stdexcept>

namespace RBX
{
	namespace Soundscape
	{
		// INFERRED: names. 005b87a0 logs a failed FMOD result through StandardOut (no throw); 005b6fe0 formats the same
		// message and throws std::runtime_error. Both are cdecl, one FMOD_RESULT argument (add esp, 4 at every call).
		void logFmodResult(FMOD_RESULT result);   // 005b87a0
		void checkFmodResult(FMOD_RESULT result); // 005b6fe0

		// INFERRED: name. 005bc6c0 is the stdcall FMOD channel callback (ret 0x14) registered by playSound; it reads the
		// channel user data (FMOD_Channel_GetUserData) and forwards to SoundChannel 005bc670.
		FMOD_RESULT F_CALLBACK soundChannelCallback(FMOD_CHANNEL* channel, FMOD_CHANNEL_CALLBACKTYPE type, int command,
			unsigned int commanddata1, unsigned int commanddata2); // 005bc6c0

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

		// 005bc6f0 Sound::get(const Instance* context): fmod_sound +0, system +4, id +0xc, is3D +0x2c. The content comes
		// from the context's ContentProvider (create 00465210, 00562730); createSound 0069fc54 result through
		// checkFmodResult 005b6fe0. GameSettings::singleton() 0044bee0 softwareSound +0x139. Shape: openrbx 2007
		// util/Sound.cpp Sound::get (2008 takes the context, see SoundChannel.h difference 1).
		FMOD::Sound* Sound::get(const Instance* context)
		{
			if (!fmod_sound)
			{
				boost::shared_ptr<const std::string> data = ServiceProvider::create<ContentProvider>(context)->sub_00562730(id);
				if (!data)
					return NULL;

				FMOD_MODE mode = is3D ? FMOD_3D : 0;
				mode |= FMOD_OPENMEMORY | (GameSettings::singleton().softwareSound ? FMOD_SOFTWARE : FMOD_HARDWARE);

				FMOD_CREATESOUNDEXINFO info;
				memset(&info, 0, sizeof(FMOD_CREATESOUNDEXINFO));
				info.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
				info.length = data->size();

				checkFmodResult(system->createSound(data->c_str(), mode, &info, &fmod_sound));
			}
			return fmod_sound;
		}

		extern Reflection::PropDescriptor<SoundChannel, SoundId> soundIdProperty; // 00977064

		// 005bc610 (INFERRED name, see SoundChannel.h): sound enabled (SoundService::soundDisabled 00976fc9, the channel
		// bit, GameSettings::singleton() 0044bee0 soundEnabled +0x138) -> ask the context's ContentProvider (create
		// 00465210) for soundId (00562730); the returned shared_ptr temporary is released at once (00600660).
		void SoundChannel::preloadSound() // 005bc610
		{
			if (SoundService::soundDisabled || soundDisabled)
				return;
			if (!GameSettings::singleton().soundEnabled)
				return;
			if (ContentProvider* provider = ServiceProvider::create<ContentProvider>(this))
				provider->sub_00562730(soundId);
		}

		// 005bd360: ContentId operator!= 0055bd60, the inline ContentId assignment (string operator= + mimeTypePtr at
		// +0x1c), preloadSound 005bc610, releaseChannel expanded inline, raisePropertyChanged(SoundId 00977064).
		void SoundChannel::setSoundId(SoundId value) // 005bd360
		{
			if (soundId != value)
			{
				soundId = value;
				preloadSound();
				releaseChannel();
				raisePropertyChanged(soundIdProperty);
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

		void SoundChannel::onEvent(const RunService*, Heartbeat) // 005ba3d0
		{
			if (!isPaused())
				update3D(fmod_channel);
		}

		// 005bceb0 + catch funclet 005bd0ad (ends 005bd0e8, returns 005bcf23): 569 bytes, identical with relocations
		// masked; the function table sizes the owner at 511 bytes without the funclet, so the proof finds no candidate.
		// The early soundDisabled test sits before the try state store (mov [ebp-4], 0) and re-reads memory, so it is
		// outside the try. The handler prints e.what() as MESSAGE_ERROR (push 3) with no format string.
		void SoundChannel::playSound(Instance* context) // 005bceb0
		{
			if (soundDisabled)
				return;

			try
			{
				if (looped && fmod_channel)
				{
					bool playing;
					if (fmod_channel->isPlaying(&playing) != FMOD_ERR_INVALID_HANDLE && playing)
					{
						checkFmodResult(fmod_channel->setPaused(false));
						return;
					}
				}

				SoundService* service = ServiceProvider::create<SoundService>(context);
				if (!service)
					return;
				if (!service->system)
				{
					soundDisabled = true;
					return;
				}

				releaseChannel();
				is3D = part != NULL;
				sound = service->loadSound(soundId, is3D);
				sound->refCount++;

				FMOD::Sound* fmodSound = sound->get(context);
				if (!fmodSound)
					return;

				checkFmodResult(service->system->playSound(FMOD_CHANNEL_FREE, fmodSound, true, &fmod_channel));
				updateLooped();
				update3D(fmod_channel);
				checkFmodResult(fmod_channel->setVolume(volume));
				checkFmodResult(fmod_channel->setUserData(this));
				checkFmodResult(fmod_channel->setCallback(FMOD_CHANNEL_CALLBACKTYPE_END, soundChannelCallback, 0));
				checkFmodResult(fmod_channel->setPaused(false));
				updateListenState();
			}
			catch (std::exception& e)
			{
				StandardOut::singleton()->print(MESSAGE_ERROR, e.what());
			}
		}

		// 005bd890: identical with relocations masked (370 bytes). Original references: findServiceProvider 004898d0,
		// find<RunService> 00452c80 (callDoGetClassIndex<RunService> 00450860), removeListener 005e5a80, stop 005bd590,
		// Instance::onAncestorChanged 0055acc0, __RTDynamicCast to PartInstance, updateListenState 005bc5b0,
		// create<SoundService> 004531e0, preloadSound 005bc610, playSound 005bceb0, find<Workspace> 00490af0,
		// isDescendentOf 00422ae0, releaseChannel 005b97f0. The listener pointer (this ? this+0x130 : 0) is computed
		// before the first oldProvider test, so the disconnect is its own statement through the null-checking
		// ServiceProvider::find<RunService>(const ServiceProvider*).
		void SoundChannel::onAncestorChanged(const AncestorChanged& event) // 005bd890
		{
			const ServiceProvider* oldProvider = ServiceProvider::findServiceProvider(event.oldParent);
			const ServiceProvider* newProvider = ServiceProvider::findServiceProvider(event.newParent);

			Notifier<RunService, Heartbeat>::disconnect(ServiceProvider::find<RunService>(oldProvider), this);
			if (oldProvider)
			{
				if (looped)
					stop();
				releaseChannel();
			}

			Instance::onAncestorChanged(event);

			if (event.child == this)
			{
				part = dynamic_cast<PartInstance*>(event.newParent);
				updateListenState();
			}

			if (newProvider)
			{
				SoundService* service = newProvider->create<SoundService>();
				if (service && service->system)
				{
					soundDisabled = false;
					preloadSound();
					updateListenState();
					if (playCount > 0)
						playSound(this);
				}
			}

			if (oldProvider)
			{
				Workspace* oldWorkspace = oldProvider->find<Workspace>();
				if (oldWorkspace && (event.oldParent == oldWorkspace || event.oldParent->isDescendentOf(oldWorkspace)))
				{
					Workspace* newWorkspace = ServiceProvider::find<Workspace>(newProvider);
					if (newWorkspace && (event.newParent == newWorkspace || event.newParent->isDescendentOf(newWorkspace)))
						return;
					if (playOnRemove)
						playSound(event.oldParent);
					releaseChannel();
				}
			}
		}
	}
}

namespace RBX {
namespace Soundscape {
void SoundChannel::updateListenState()
{
	if (part != 0 && is3D && fmod_channel != 0)
	{
		Listener<RunService, Heartbeat>* self = this;
		RunService* runService = ServiceProvider::create<RunService>(this);
		if (runService)
			runService->Notifier<RunService, Heartbeat>::addListener(self);
	}
	else
	{
		Listener<RunService, Heartbeat>* self = this;
		RunService* runService = ServiceProvider::create<RunService>(this);
		if (runService)
			runService->Notifier<RunService, Heartbeat>::removeListener(self);
	}
}
}
}

