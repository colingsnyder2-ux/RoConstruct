// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_005bc6c0 (placeholder name for 005bc6c0 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "util/Name.h"
#include "SoundChannel/SoundChannel.h"

namespace RBX
{
	namespace Soundscape
	{
		FMOD_RESULT F_CALLBACK sub_005bc6c0(FMOD_CHANNEL* channel, FMOD_CHANNEL_CALLBACKTYPE type, int command,
			unsigned int commanddata1, unsigned int commanddata2)
		{
			FMOD_Channel_GetUserData(channel, reinterpret_cast<void**>(&channel));
			SoundChannel* soundChannel = reinterpret_cast<SoundChannel*>(channel);
			if (soundChannel)
				soundChannel->onChannelEnd();
			return FMOD_OK;
		}
	}
}
