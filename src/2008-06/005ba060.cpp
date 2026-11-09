// from server: 100% by auto
// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_c17b7ffeb42a1fea.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include "util/Sound.h"
#include "util/StandardOut.h"
#include "v8datamodel/GameSettings.h"
#include "../../../openrbx/3rdparty/fmod/api/inc/fmod.hpp"
#include "../../../openrbx/3rdparty/fmod/api/inc/fmod_errors.h"
#include <stdexcept>

void checkResult(FMOD_RESULT result);
void logResult(FMOD_RESULT result);

namespace FFlag { extern bool SoundDisabled; }

namespace RBX { namespace Soundscape {

// 2008-06 field offsets read from the target (rbxgs layout is 8 bytes shorter)
struct SoundServiceLayout2008 {
	char opaque0[0x134];
	FMOD::System* system;
	unsigned fmod_version;
	char opaque1[0x170 - 0x13c];
	ReverbType ambientReverb;
	char opaque2[0x1c0 - 0x174];
	bool mySoundDisabled;
};
struct GameSettingsLayout2008 {
	char opaque0[0x138];
	bool soundEnabled;
};

void SoundService::openFmod()
{
	SoundServiceLayout2008& self = *reinterpret_cast<SoundServiceLayout2008*>(this);
	if (!FFlag::SoundDisabled && !self.mySoundDisabled && reinterpret_cast<GameSettingsLayout2008&>(GameSettings::singleton()).soundEnabled)
	{
		try
		{
			checkResult(FMOD::System_Create(&self.system));
			checkResult(self.system->getVersion(&self.fmod_version));
			if (self.fmod_version < 0x00041406)
				throw std::runtime_error("Incorrect FMODEX DLL version");

			int driver = -1;
			logResult(self.system->getDriver(&driver));
			if (driver < 0)
				StandardOut::singleton()->print(MESSAGE_WARNING, "No active sound driver detected");

			unsigned caps;
			FMOD_SPEAKERMODE speakerMode;
			checkResult(self.system->getDriverCaps(0, &caps, 0, 0, &speakerMode));
			checkResult(self.system->setSpeakerMode(speakerMode));
			if (caps & FMOD_CAPS_HARDWARE_EMULATED)
			{
				StandardOut::singleton()->print(MESSAGE_WARNING, "The acceleration slider in the Sound Control Panel set to 'off'");
				checkResult(self.system->setDSPBufferSize(1024, 10));
			}

			if (self.system->init(100, FMOD_INIT_NORMAL, 0) == FMOD_ERR_OUTPUT_CREATEBUFFER)
			{
				StandardOut::singleton()->print(MESSAGE_WARNING, "The speaker mode selected isn't supported by this soundcard.  Using Stereo");
				checkResult(self.system->setSpeakerMode(FMOD_SPEAKERMODE_STEREO));
				checkResult(self.system->init(100, FMOD_INIT_NORMAL, 0));
			}

			update3DSettings();
			if (self.ambientReverb != NoReverb)
				updateAmbientReverb();
		}
		catch (const std::exception&)
		{
			if (self.system)
			{
				logResult(self.system->release());
				self.system = 0;
			}
		}
	}
}

} }
