// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/openrbx/Client/fmod/api/inc /I{headers}/../../../tools/openrbx/3rdparty/fmod/api/inc
#include <fmod.hpp>
#include "SoundChannel/SoundChannel.h"
#include "util/StandardOut.h"
#include "v8datamodel/GameSettings.h"
#include <stdexcept>

namespace RBX {
namespace Soundscape {

void logFmodResult(FMOD_RESULT result);   // 005b87a0 (non-throwing check)
void checkFmodResult(FMOD_RESULT result); // 005b6fe0 (throwing check)

void SoundService::openFmod()
{
	if (soundDisabled || mySoundDisabled || !GameSettings::singleton().soundEnabled)
		return;
	try
	{
		checkFmodResult(FMOD::System_Create(&system));
		checkFmodResult(system->getVersion(&fmod_version));
		if (fmod_version < 0x41406) // INFERRED: FMOD_VERSION of the 4.14.06 SDK the client linked (cmp [edi], 0x41406 at 005ba0e6); the tree header says 4.08.08
			throw std::runtime_error("Incorrect FMODEX DLL version");
		int driver = -1;
		logFmodResult(system->getDriver(&driver));
		if (driver < 0)
			StandardOut::singleton()->print(MESSAGE_WARNING, "No active sound driver detected");
		FMOD_CAPS caps;
		FMOD_SPEAKERMODE speakerMode;
		checkFmodResult(system->getDriverCaps(0, &caps, NULL, NULL, &speakerMode));
		checkFmodResult(system->setSpeakerMode(speakerMode));
		if ((caps & FMOD_CAPS_HARDWARE_EMULATED) != 0)
		{
			StandardOut::singleton()->print(MESSAGE_WARNING, "The acceleration slider in the Sound Control Panel set to 'off'");
			checkFmodResult(system->setDSPBufferSize(1024, 10));
		}
		if (system->init(100, 0, NULL) == FMOD_ERR_OUTPUT_CREATEBUFFER)
		{
			StandardOut::singleton()->print(MESSAGE_WARNING, "The speaker mode selected isn't supported by this soundcard.  Using Stereo");
			checkFmodResult(system->setSpeakerMode(FMOD_SPEAKERMODE_STEREO));
			checkFmodResult(system->init(100, 0, NULL));
		}
		update3DSettings();
		if (ambientReverb != NoReverb)
			updateAmbientReverb();
	}
	catch (std::exception&)
	{
		if (system)
		{
			logFmodResult(system->release());
			system = NULL;
		}
	}
}

}
}
