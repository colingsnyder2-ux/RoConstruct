#include "SoundChannel/SoundChannel.h"
#include "v8datamodel/Workspace.h"
#include "util/standardout.h"
#include <stdexcept>

namespace RBX
{
	namespace Soundscape
	{
		// INFERRED: names. 005b87a0 logs a failed FMOD result through StandardOut (no throw); 005b6fe0 formats the same
		void logFmodResult(FMOD_RESULT result);   // 005b87a0
		void checkFmodResult(FMOD_RESULT result); // 005b6fe0

		// INFERRED: name. 005bc6c0 is the stdcall FMOD channel callback (ret 0x14) registered by playSound; it reads the
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

#include "axis-vector-negation/G3D/Vector3.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/Stats.h"
#include <g3d/system.h>

namespace RBX {
namespace Soundscape {
void SoundService::loadStockSounds()
		{
			stockSounds.clear();
			removeAllChildren();
			loadStockSounds(BOING_SOUND, "Sounds\\bass.wav");
			loadStockSounds(BOMB_SOUND, "Sounds\\collide.wav");
			loadStockSounds(BREAK_SOUND, "Sounds\\glassbreak.wav");
			loadStockSounds(CLICK_SOUND, "Sounds\\switch.wav");
			loadStockSounds(CLOCK_SOUND, "Sounds\\clickfast.wav");
			loadStockSounds(RUBBERBAND_SOUND, "Sounds\\Rubber band sling shot.wav");
			loadStockSounds(PAGE_SOUND, "Sounds\\pageturn.wav");
			loadStockSounds(PING_SOUND, "Sounds\\electronicpingshort.wav");
			loadStockSounds(SNAP_SOUND, "Sounds\\snap.wav");
			loadStockSounds(SPLAT_SOUND, "Sounds\\splat.wav");
			loadStockSounds(STEP_SOUND, "Sounds\\SWITCH3.wav");
			loadStockSounds(STEP_ON_SOUND, "Sounds\\flashbulb.wav");
			loadStockSounds(SWOOSH_SOUND, "Sounds\\swoosh.wav");
			loadStockSounds(VICTORY_SOUND, "Sounds\\victory.wav");
		}
}
}
