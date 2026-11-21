// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/fmod/api/inc
// 2008-06 util/Sound.cpp reflection statics: dynamic initializers 007f5220, 007f5250, 007f5280 (SoundService),
// 007f5450, 007f5480, 007f54b0, 007f54e0 (SoundChannel).  Object names from the 2007 donor util/Sound.cpp; name
// strings, members, callbacks and flags read from the 2008 initializers (all three SoundService props push 5).
#include "util/Sound.h"
namespace RBX {
	namespace Soundscape {
		Reflection::BoundProp<float, 1> SoundService::prop_dopplerscale("DopplerScale", "Data", &SoundService::dopplerscale, &SoundService::on3DSettingChanged, Reflection::PropertyDescriptor::STANDARD);
		Reflection::BoundProp<float, 1> SoundService::prop_distancefactor("DistanceFactor", "Data", &SoundService::distancefactor, &SoundService::on3DSettingChanged, Reflection::PropertyDescriptor::STANDARD);
		Reflection::BoundProp<float, 1> SoundService::prop_rolloffscale("RolloffScale", "Data", &SoundService::rolloffscale, &SoundService::on3DSettingChanged, Reflection::PropertyDescriptor::STANDARD);

		Reflection::BoundProp<bool, 1> SoundChannel::sound_desc_playOnRemove("PlayOnRemove", "Behavior", &SoundChannel::playOnRemove, Reflection::PropertyDescriptor::STANDARD);
		static Reflection::BoundFuncDesc<SoundChannel, void(void), 0> sound_playFunction(&SoundChannel::play, "Play", Reflection::FunctionDescriptor::NeedTrustedCaller);
	}
	// 007f54b0: registry decorated name ??__EpauseFunction@RBX@@YAXXZ puts the 2008 Pause descriptor in namespace RBX
	// (the 2007 donor's Soundscape-scope sound_pauseFunction name does not occur in the 2008 image).
	static Reflection::BoundFuncDesc<Soundscape::SoundChannel, void(void), 0> pauseFunction(&Soundscape::SoundChannel::pause, "Pause", Reflection::FunctionDescriptor::NeedTrustedCaller);
	namespace Soundscape {
		static Reflection::BoundFuncDesc<SoundChannel, void(void), 0> sound_stopFunction(&SoundChannel::stop, "Stop", Reflection::FunctionDescriptor::NeedTrustedCaller);
	}
}
