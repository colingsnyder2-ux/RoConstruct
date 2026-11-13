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
