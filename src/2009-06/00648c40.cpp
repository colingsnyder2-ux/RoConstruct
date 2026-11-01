// from server: 94% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// SoundService::openFmod (2009-06). True extent 0x250 bytes (server extent 0x213 cuts the epilogue + catch funclet).
#include <stdexcept>

typedef int FMOD_RESULT;
typedef unsigned int FMOD_CAPS;
typedef unsigned int FMOD_INITFLAGS;
typedef int FMOD_SPEAKERMODE;
struct FMOD_SYSTEM;
extern "C" {
FMOD_RESULT __stdcall FMOD_System_Create(FMOD_SYSTEM** system);
FMOD_RESULT __stdcall FMOD_System_Release(FMOD_SYSTEM* system);
FMOD_RESULT __stdcall FMOD_System_GetVersion(FMOD_SYSTEM* system, unsigned int* version);
FMOD_RESULT __stdcall FMOD_System_GetDriver(FMOD_SYSTEM* system, int* driver);
FMOD_RESULT __stdcall FMOD_System_GetDriverCaps(FMOD_SYSTEM* system, int id, FMOD_CAPS* caps, int* minfrequency, int* maxfrequency, FMOD_SPEAKERMODE* controlpanelspeakermode);
FMOD_RESULT __stdcall FMOD_System_SetSpeakerMode(FMOD_SYSTEM* system, FMOD_SPEAKERMODE speakermode);
FMOD_RESULT __stdcall FMOD_System_SetDSPBufferSize(FMOD_SYSTEM* system, unsigned int bufferlength, int numbuffers);
FMOD_RESULT __stdcall FMOD_System_Init(FMOD_SYSTEM* system, int maxchannels, FMOD_INITFLAGS flags, void* extradriverdata);
}

void checkResult(FMOD_RESULT result);
void logResult(FMOD_RESULT result);

namespace FFlag { extern bool SoundDisabled; }

namespace boost {
template<class T> class shared_ptr {
public:
	T* px; void* pn;
	~shared_ptr();
	T* operator->() const { return px; }
};
}

namespace RBX {

enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };

class StandardOut {
public:
	static boost::shared_ptr<StandardOut> singleton();
	void print(MessageType type, const char* message);
};

class GameSettings {
public:
	static GameSettings& singleton();
	char pad0[0x94];
	bool soundEnabled;
	char pad1[0x9a - 0x95];
	bool softwareSound;
};

namespace Soundscape {

enum ReverbType { NoReverb };

class SoundService {
	char pad0[0x8c];
	FMOD_SYSTEM* system;
	unsigned int fmod_version;
	char pad1[0xc8 - 0x94];
	ReverbType ambientReverb;
	char pad2[0x118 - 0xcc];
	bool mySoundDisabled;
	void update3DSettings();
	void updateAmbientReverb();
	void openFmod();
};

void SoundService::openFmod()
{
	if (!FFlag::SoundDisabled && !mySoundDisabled && GameSettings::singleton().soundEnabled)
	{
		try
		{
			checkResult(FMOD_System_Create(&system));
			checkResult(FMOD_System_GetVersion(system, &fmod_version));
			if (fmod_version < 0x00042001)
				throw std::runtime_error("Incorrect FMODEX DLL version");

			int driver = -1;
			logResult(FMOD_System_GetDriver(system, &driver));
			if (driver < 0)
				StandardOut::singleton()->print(MESSAGE_WARNING, "No active sound driver detected");

			FMOD_CAPS caps;
			FMOD_SPEAKERMODE speakerMode;
			checkResult(FMOD_System_GetDriverCaps(system, 0, &caps, 0, 0, &speakerMode));
			checkResult(FMOD_System_SetSpeakerMode(system, speakerMode));
			if (caps & 2)
			{
				StandardOut::singleton()->print(MESSAGE_WARNING, "The acceleration slider in the Sound Control Panel set to 'off'");
				checkResult(FMOD_System_SetDSPBufferSize(system, 1024, 10));
			}

			FMOD_INITFLAGS flags = 0;
			if (GameSettings::singleton().softwareSound)
				flags = 0x20;
			if (FMOD_System_Init(system, 100, flags, 0) == 0x39)
			{
				StandardOut::singleton()->print(MESSAGE_WARNING, "The speaker mode selected isn't supported by this soundcard.  Using Stereo");
				checkResult(FMOD_System_SetSpeakerMode(system, 2));
				checkResult(FMOD_System_Init(system, 100, flags, 0));
			}

			update3DSettings();
			if (ambientReverb != NoReverb)
				updateAmbientReverb();
		}
		catch (const std::exception&)
		{
			if (system)
			{
				logResult(FMOD_System_Release(system));
				system = 0;
			}
		}
	}
}

} }
