// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/fmod/api/inc /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
// 2008-06 native Soundscape::SoundService::soundDisabled (inactive): bool 00976fc9 (.bss, 0; openFmod 005ba060 tests it).
#include <fmod.hpp>
#include "SoundChannel/SoundChannel.h"

namespace RBX
{
	namespace Soundscape
	{
		bool SoundService::soundDisabled = false;
	}
}
