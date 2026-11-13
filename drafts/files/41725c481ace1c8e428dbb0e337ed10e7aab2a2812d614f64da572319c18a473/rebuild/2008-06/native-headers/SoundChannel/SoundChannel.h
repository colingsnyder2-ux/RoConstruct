#pragma once
// SoundChannel unit support: the FMOD Ex 4.x C++ API subset that RBX::Soundscape::SoundChannel calls.
// The SDK header fmod.hpp is not in the tree, so the members used here are declared with the SDK's exact
// signatures, taken from the original import decorations (fmodex.dll):
//   ?setUserData@Channel@FMOD@@QAG?AW4FMOD_RESULT@@PAX@Z      ?getMode@Channel@FMOD@@QAG?AW4FMOD_RESULT@@PAI@Z
//   ?setMode@Channel@FMOD@@QAG?AW4FMOD_RESULT@@I@Z            ?setLoopCount@Channel@FMOD@@QAG?AW4FMOD_RESULT@@H@Z
//   ?setPaused@Channel@FMOD@@QAG?AW4FMOD_RESULT@@_N@Z         ?stop@Channel@FMOD@@QAG?AW4FMOD_RESULT@@XZ
//   ?isPlaying@Channel@FMOD@@QAG?AW4FMOD_RESULT@@PA_N@Z       ?setVolume@Channel@FMOD@@QAG?AW4FMOD_RESULT@@M@Z
//   ?setCallback@Channel@FMOD@@QAG?AW4FMOD_RESULT@@W4FMOD_CHANNEL_CALLBACKTYPE@@P6G?AW43@PAUFMOD_CHANNEL@@0HII@ZH@Z
//   ?playSound@System@FMOD@@QAG?AW4FMOD_RESULT@@W4FMOD_CHANNELINDEX@@PAVSound@2@_NPAPAVChannel@2@@Z
// QAG = public __stdcall member (the SDK's F_API). FMOD_RESULT values used by the target: FMOD_OK 0,
// FMOD_ERR_INVALID_HANDLE 0x24 (cmp eax, 0x24 at 005bcf01). FMOD_MODE bits: FMOD_LOOP_OFF 1, FMOD_LOOP_NORMAL 2
// (005b98bc..005b98d3). FMOD_CHANNEL_FREE -1 (push -1 at 005bd019), FMOD_CHANNEL_CALLBACKTYPE_END 0 (005bd071).
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

// Unit-local redeclaration of the util/Sound.h Soundscape classes (pattern: ContactUnit2008ConnectorBody.cpp).
// util/Sound.h is a read-only core header and two declarations there do not fit the target; this header is used
// INSTEAD of util/Sound.h (never together with it). Every other base, member, field and offset is identical to
// util/Sound.h. Differences (also sent as util/Sound.h proposals):
//   1. Sound::get takes the context Instance: at 005bcffb playSound pushes its context argument before
//      `mov ecx, [esi+0x134]; call 005bc6f0`, and 005bc6f0 ends `ret 4`, passing the argument on to
//      ServiceProvider::create<ContentProvider>(const Instance*) (00465210).
//   2. SoundChannel has a further private member at 005bc610 (thiscall on the channel, called from
//      onAncestorChanged at 005bd983): when sound is enabled it asks the context's ContentProvider for soundId.
//      Its name is not in the identity registry (func_005bc610); preloadSound is INFERRED.
#include "util/ContentProvider.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/PartInstance.h"
#include "v8tree/Service.h"
#include <map>

class SoundServiceStatsItem;

namespace RBX
{
	enum SoundType
	{
		NO_SOUND,
		BOING_SOUND,
		BOMB_SOUND,
		BREAK_SOUND,
		CLICK_SOUND,
		CLOCK_SOUND,
		RUBBERBAND_SOUND,
		PAGE_SOUND,
		PING_SOUND,
		SNAP_SOUND,
		SPLAT_SOUND,
		STEP_SOUND,
		STEP_ON_SOUND,
		SWOOSH_SOUND,
		VICTORY_SOUND
	};

	namespace Soundscape
	{
		enum ReverbType
		{
			NoReverb,
			GenericReverb,
			PaddedCell,
			Room,
			Bathroom,
			LivingRoom,
			StoneRoom,
			Auditorium,
			ConcertHall,
			Cave,
			Arena,
			Hangar,
			CarpettedHallway,
			Hallway,
			StoneCorridor,
			Alley,
			Forest,
			City,
			Mountains,
			Quarry,
			Plain,
			ParkingLot,
			SewerPipe,
			UnderWater
		};

		class SoundId : public ContentId
		{
		public:
			SoundId()
				: ContentId()
			{
			}
			SoundId(const std::string& id)
				: ContentId(id)
			{
			}
			SoundId(const char* id)
				: ContentId(id)
			{
			}
			SoundId(const ContentId& id)
				: ContentId(id)
			{
			}
		};

		class Sound : private boost::noncopyable
		{
		private:
			FMOD::Sound* fmod_sound;
			FMOD::System* system;
		public:
			int refCount;
			const SoundId id;
			const bool is3D;

		public:
			Sound(FMOD::System*, SoundId, bool);
			~Sound();
			FMOD::Sound* get(const Instance* context); // 005bc6f0 (difference 1)
			void detach();
			void release();
		};

		extern char sSoundChannel[];

		class SoundChannel : public DescribedCreatable<SoundChannel, Instance, sSoundChannel>,
							 public Listener<RunService, Heartbeat>
		{
		private:
			boost::shared_ptr<Sound> sound;   // +0x134
			FMOD::Channel* fmod_channel;      // +0x13c
			SoundId soundId;                  // +0x140
			float volume;                     // +0x160
			bool playOnRemove;                // +0x164
			bool is3D : 1;                    // +0x165 bit 0
			bool looped : 1;                  // +0x165 bit 1
			bool soundDisabled : 1;           // +0x165 bit 2
			int playCount;                    // +0x168
			PartInstance* part;               // +0x16c
		public:
			static Reflection::BoundProp<bool, 1> sound_desc_playOnRemove;

		public:
			SoundChannel();
			virtual ~SoundChannel();
			void setSoundId(SoundId);
			SoundId getSoundId() const;
			float getVolume() const;
			void setVolume(float);
			bool getLooped() const;
			void setLooped(bool);
			int getPlayCount() const;
			void setPlayCount(int);
			void play();
			void pause();
			void stop();
			bool isPlaying() const;
			bool isPaused() const;
		protected:
			virtual bool askSetParent(const Instance*) const;
			virtual void onAncestorChanged(const AncestorChanged&);
			virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);
			virtual void onEvent(const RunService*, Heartbeat);
		private:
			void updateListenState();
			void updateLooped();
			void update3D(FMOD::Channel*);
			void playSound(Instance*);
			void playSound();
			void releaseChannel();
			void preloadSound(); // 005bc610 (difference 2; INFERRED name)
		public:
			void onChannelEnd();
		};

		extern char sSoundService[];

		class SoundService : public DescribedCreatable<SoundService, Instance, sSoundService>,
							 public Service,
							 public Listener<RunService, Heartbeat>
		{
			friend class ::SoundServiceStatsItem;
			friend class SoundChannel;
		private:
			FMOD::System* system;
			unsigned fmod_version;
			std::map<SoundType, boost::shared_ptr<SoundChannel>> stockSounds;
			float dopplerscale;
			float distancefactor;
			float rolloffscale;
			boost::shared_ptr<Instance> statsItem;
			ReverbType ambientReverb;
			double nextGarbageCollectTime;
			std::map<SoundId, boost::shared_ptr<Sound>> loadedSounds;
			std::map<SoundId, boost::shared_ptr<Sound>> loaded3DSounds;
			bool mySoundDisabled;
		public:
			bool soundDisabled;
			static Reflection::BoundProp<float, 1> prop_dopplerscale;
			static Reflection::BoundProp<float, 1> prop_distancefactor;
			static Reflection::BoundProp<float, 1> prop_rolloffscale;
			static Reflection::EnumPropDescriptor<SoundService, ReverbType> prop_AmbientReverb;

		public:
			boost::shared_ptr<Sound> loadSound(SoundId, bool);
			bool enabled() const;
			void disable();
			SoundService();
			virtual ~SoundService();
			void playSound(SoundType);
			unsigned getfmod_version() const;
			ReverbType getAmbientReverb() const;
			void setAmbientReverb(const ReverbType&);
		private:
			void openFmod();
			void closeFmod();
			void garbageCollectSounds();
		protected:
			virtual void onEvent(const RunService*, Heartbeat);
			virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);
		private:
			void loadStockSounds();
			void loadStockSounds(SoundType, std::string);
			void update3DSettings();
			void on3DSettingChanged(const Reflection::PropertyDescriptor&);
			void updateAmbientReverb();

		private:
			static void getSoundStats(const std::map<SoundId, boost::shared_ptr<Sound>>&, size_t, size_t);
			static void gcSounds(std::map<SoundId, boost::shared_ptr<Sound>>&);
		};
	}
}
