// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native SoundService members of the util/Sound.cpp unit (inactive): onEvent 005bc2c0, loadStockSounds
// 005bdb10, onServiceProvider 005bdcf0.
// Declarations: native-headers/SoundChannel/SoundChannel.h (the unit-local redeclaration of util/Sound.h used by the
// SoundChannel family). That header carries an FMOD Ex subset without the two System members onEvent calls, so this
// unit supplies the FMOD subset itself (the header skips its own block when _FMOD_HPP is defined): the same
// declarations as SoundChannel.h plus, from the original import decorations (fmodex.dll),
//   ?set3DListenerAttributes@System@FMOD@@QAG?AW4FMOD_RESULT@@HPBUFMOD_VECTOR@@000@Z   (call at 005bc40b)
//   ?update@System@FMOD@@QAG?AW4FMOD_RESULT@@XZ                                        (call at 005bc45c)
// SoundService layout as util/Sound.h, confirmed by the original accesses: Listener<RunService, Heartbeat> base
// +0x130 (onEvent this - 0x130), system +0x134, stockSounds +0x13c (head +0x154, size +0x158), statsItem +0x168,
// nextGarbageCollectTime +0x178, loadedSounds +0x180, loaded3DSounds +0x1a0.
// Codegen analog (not an authentic declaration): G3D::Vector3::operator-() from the scoped axis-vector-negation profile
// (native-headers/axis-vector-negation, read-only), which writes x, y, z of the result directly. The target negates
// lookVector() straight into the argument temporary in x, y, z order (005bc334..005bc354); the default G3D 6.09 profile
// (return Vector3(-x, -y, -z)) builds y, z, x into a second temporary and copies it. Included first so its include
// guard wins. Rejected without it: one extra 12-byte temporary (frame 0x68 instead of 0x60).
#include "axis-vector-negation/G3D/Vector3.h"
#if !defined(_FMOD_HPP) && !defined(_FMOD_H)
#define _FMOD_H
#define _FMOD_HPP

#define F_API __stdcall
#define F_CALLBACK __stdcall

typedef unsigned int FMOD_MODE;
#define FMOD_LOOP_OFF    0x00000001
#define FMOD_LOOP_NORMAL 0x00000002

typedef enum
{
	FMOD_OK,
	FMOD_ERR_INVALID_HANDLE = 36
} FMOD_RESULT;

typedef enum
{
	FMOD_CHANNEL_FREE = -1,
	FMOD_CHANNEL_REUSE = -2
} FMOD_CHANNELINDEX;

typedef enum
{
	FMOD_CHANNEL_CALLBACKTYPE_END
} FMOD_CHANNEL_CALLBACKTYPE;

typedef struct
{
	float x;
	float y;
	float z;
} FMOD_VECTOR;

typedef struct FMOD_CHANNEL FMOD_CHANNEL;
typedef FMOD_RESULT (F_CALLBACK *FMOD_CHANNEL_CALLBACK)(FMOD_CHANNEL* channel, FMOD_CHANNEL_CALLBACKTYPE type,
	int command, unsigned int commanddata1, unsigned int commanddata2);

extern "C" FMOD_RESULT F_API FMOD_Channel_GetUserData(FMOD_CHANNEL* channel, void** userdata);

namespace FMOD
{
	class Sound;
	class Channel;

	class System
	{
	private:
		System();
		System(const System&);
	public:
		FMOD_RESULT F_API update();
		FMOD_RESULT F_API set3DListenerAttributes(int listener, const FMOD_VECTOR* pos, const FMOD_VECTOR* vel,
			const FMOD_VECTOR* forward, const FMOD_VECTOR* up);
		FMOD_RESULT F_API playSound(FMOD_CHANNELINDEX channelid, Sound* sound, bool paused, Channel** channel);
	};

	class Channel
	{
	private:
		Channel();
		Channel(const Channel&);
	public:
		FMOD_RESULT F_API stop();
		FMOD_RESULT F_API setPaused(bool paused);
		FMOD_RESULT F_API getPaused(bool* paused);
		FMOD_RESULT F_API setVolume(float volume);
		FMOD_RESULT F_API isPlaying(bool* isplaying);
		FMOD_RESULT F_API setCallback(FMOD_CHANNEL_CALLBACKTYPE type, FMOD_CHANNEL_CALLBACK callback, int command);
		FMOD_RESULT F_API setUserData(void* userdata);
		FMOD_RESULT F_API setMode(FMOD_MODE mode);
		FMOD_RESULT F_API getMode(FMOD_MODE* mode);
		FMOD_RESULT F_API setLoopCount(int loopcount);
	};
}
#endif

#include "SoundChannel/SoundChannel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/Stats.h"
#include <g3d/system.h>

// Unit-local declaration of SoundServiceStatsItem, identical to util/Sound.h (SoundChannel.h only forward-declares it;
// util/Sound.h cannot be included together with SoundChannel.h). The complete type is needed for the
// shared_ptr<SoundServiceStatsItem> -> shared_ptr<Instance> assignment in onServiceProvider (no pointer adjustment at
// 005bddb6: Instance is the primary base).
class SoundServiceStatsItem : public RBX::Stats::Item
{
private:
	const RBX::Soundscape::SoundService* service;
	size_t currentalloced;
	size_t maxalloced;
	size_t numSounds;
	size_t numUnusedSounds;

public:
	SoundServiceStatsItem(const RBX::Soundscape::SoundService*);
	virtual void update();
};

namespace RBX
{
	namespace Soundscape
	{
		// INFERRED: name. 005bc410 logs a failed FMOD result (see SoundChannel.cpp, 005b87a0).
		void logFmodResult(FMOD_RESULT result); // 005b87a0

		// INFERRED: name. 005b70c0 is cdecl (add esp, 8 at every call), (const Vector3& source, FMOD_VECTOR& target),
		// returns bool: zeroes denormal components (Math::isDenormal 005dd7b0), returns false for a NaN vector
		// (005dd8b0) and otherwise writes the converted vector through the second argument.
		bool toFmodVector(const G3D::Vector3& source, FMOD_VECTOR& target); // 005b70c0

		// INFERRED: out-of-line member expanded into onEvent (gcSounds 005ba2e0 has the single caller 005bc2c0); no
		// standalone copy survives in the target (unreferenced COMDAT). Evidence for a separate inlined member: the
		// target keeps the listener pointer (ebx, system at [ebx+4]) and the adjusted SoundService pointer (edi, the
		// gc fields +0x178/+0x180/+0x1a0) apart; written inline in onEvent, one base register serves both. The early
		// return yields `test ah, 5; jnp` (005bc427); `if (tick >= next)` and `if (next <= tick)` give `test ah, 1`.
		// Address: none (no out-of-line copy in the target).
		void SoundService::garbageCollectSounds()
		{
			if (G3D::System::getTick() < nextGarbageCollectTime)
				return;
			gcSounds(loadedSounds);
			gcSounds(loaded3DSounds);
			nextGarbageCollectTime = G3D::System::getTick() + 5.0;
		}

		// 005bc2c0. The heartbeat listener pointer is this; the SoundService is this - 0x130.
		void SoundService::onEvent(const RunService*, Heartbeat)
		{
			if (!system)
				return;

			if (Workspace* workspace = ServiceProvider::find<Workspace>(this))
			{
				if (Camera* camera = workspace->getCamera())
				{
					G3D::CoordinateFrame cframe = camera->getCameraCoordinateFrame();
					FMOD_VECTOR pos;
					if (toFmodVector(cframe.translation, pos))
					{
						FMOD_VECTOR forward;
						if (toFmodVector(-cframe.lookVector(), forward))
						{
							FMOD_VECTOR up;
							if (toFmodVector(cframe.upVector(), up) /* getColumn(1) 00513240 before the argument pushes */)
							{
								FMOD_VECTOR vel;
								vel.x = vel.y = vel.z = 0; // stored z, y, x (005bc39b..005bc3aa)
								if (PVInstance* pvInstance = dynamic_cast<PVInstance*>(camera->getCameraSubjectInstance()))
								{
									if (PartInstance* part = pvInstance->getPrimaryPart())
										toFmodVector(part->getLinearVelocity(), vel);
								}
								logFmodResult(system->set3DListenerAttributes(0, &pos, &vel, &forward, &up));
							}
						}
					}
				}
			}

			garbageCollectSounds();

			logFmodResult(system->update());
		}

		// 005bdb10. stockSounds.clear() is expanded inline (_Erase 004b0d80 is the ICF-shared tree eraser), then the
		// children are removed (0055afd0) before the 14 stock sounds are reloaded; strings 00838374..0083824c.
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

		// 005bdcf0. Original references: find<RunService>() const 00452c80, removeListener 005e5a80 / addListener
		// 004218a0 (ICF-shared Notifier members), setParent 0055a8f0, shared_ptr<Instance>::reset 00456e80, closeFmod
		// 005ba970, openFmod 005ba060, loadStockSounds 005bdb10, create<StatsService>() const 00458610,
		// Creatable<Instance>::create<SoundServiceStatsItem, SoundService*> 005bd1d0.
		void SoundService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			Notifier<RunService, Heartbeat>::disconnect(ServiceProvider::find<RunService>(oldProvider), this);

			if (statsItem)
			{
				statsItem->setParent(NULL);
				statsItem.reset();
			}

			if (oldProvider)
				closeFmod();

			// Its own statement like the disconnect: the newProvider tests merge and this + 0x130 (ebp) is formed before
			// the test (005bdd68); a connect inside `if (newProvider)` schedules it after the test.
			Notifier<RunService, Heartbeat>::connect(ServiceProvider::find<RunService>(newProvider), this);
			if (newProvider)
			{
				openFmod();
				loadStockSounds();
				if (Stats::StatsService* stats = newProvider->create<Stats::StatsService>())
				{
					statsItem = Creatable<Instance>::create<SoundServiceStatsItem>(this);
					statsItem->setParent(stats);
				}
			}
		}
	}
}
