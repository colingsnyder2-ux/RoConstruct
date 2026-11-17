// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// 005bd330: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "SoundChannel/SoundChannel.h"
#include "util/Name.h"

namespace RBX {
namespace Soundscape {

void __thiscall SoundService::setAmbientReverb(const ReverbType& value)
{
	if (value != ambientReverb)
	{
		ambientReverb = value;
		raisePropertyChanged(prop_AmbientReverb);
		updateAmbientReverb();
	}
}

}
}
